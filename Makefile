##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef

MAKEFLAGS += --no-print-directory

CMD				=
CC				= gcc
MAKE			= make

SOURCE_DIR		= src
BUILD_DIR		= build

SOURCE	= $(shell find $(SOURCE_DIR) -name "*.c")

CFLAGS	+=	-Llib -Iinclude -lmy -W -g3
LD_FLAGS	= -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system -lm

ifneq (,$(findstring tests,$(MAKECMDGOALS)))
	CFLAGS += -D__TESTS -fprofile-arcs -ftest-coverage -lcriterion --coverage
endif

OBJ		=	$(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE))

NAME	=	my_rpg

all:	$(NAME) message #test_run

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(call rich_echo,"CC","$@")
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

message:
	@echo -e "\e[38;5;33m"
	@figlet $(NAME); exit 0
	@echo -e "\e[0m"
	@$(call rich_echo,"[INFO]","Compilation done.")

$(NAME):	$(OBJ)
	@tar -xf assets.tar
	@$(MAKE) -C lib/
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LD_FLAGS)

clean:
	@$(MAKE) -C lib/ clean
	@rm -f $(OBJ)
	@rm -rf tests/*.gc*
	@rm -rf *.gc*
	@$(call rich_echo,"MK","FClean done")

fclean:		clean
	@$(MAKE) -C lib/ fclean -s
	@rm -f $(NAME)*
	@rm -f libmy.a
	@tar -cf assets.tar assets
	@$(call rich_echo,"MK","FClean done")

re:	fclean all

protos: $(NAME)
	@cproto $(SOURCE) -Iinclude

tests_run:
	$(CC) -o $(NAME)_tests $(SOURCE) tests/*.c $(CFLAGS) $(LD_FLAGS)
	./$(NAME)_tests
	mv *.gc* tests/

.PHONY: tests_run re fclean clean all $(NAME) protos message
.NOTPARALLEL:
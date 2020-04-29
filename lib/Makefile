##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## Makefile
##

OUTPUT      := libmy.a

SOURCE_DIR  := src
BUILD_DIR   := build

SOURCE       = $(shell find $(SOURCE_DIR) -name '*.c')
OBJS         = $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE))

ifneq (,$(findstring debug,$(MAKECMDGOALS)))
	CFLAGS += -D__DEBUG__ -g3
endif

define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef

all: $(OUTPUT)

re: fclean all

copy-heads: $(DEST_HEADS)

$(OUTPUT): $(OBJS)
	@$(call rich_echo,"AR","$@")
	@ar rcs $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(call rich_echo,"CC","$@")
	@mkdir -p $(@D)
	@gcc $(CC_FLAGS) -c $< -o $@

debug: all

clean:
	@$(call rich_echo,"RM","$(BUILD_DIR)/*.o")
	@rm -f $(OBJS)
	@$(call rich_echo,"RM","*.gcda *.gcno")
	@find $(BUILD_DIR) -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean: clean
	@$(call rich_echo,"RM","$(OUTPUT) *.gcov")
	@rm -f $(OUTPUT) $(wildcard *.gcov)

.PHONY: all re copy-heads clean fclean doc
.NOTPARALLEL:
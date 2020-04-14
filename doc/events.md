<h1>Documentation 😅<h4>
<h2>This is just a simple table of the CSFML sfEvt table.<h3>

| OPTIONS  | EVENT | DESCRIPTION |
| ---------|-------|-------------|
| ** 0  ** |    sfEvtClosed,                    |``The window requested to be closed (no data)``
| ** 1  ** |    sfEvtResized,                   |``The window was resized (data in event.size)``
| ** 2  ** |    sfEvtLostFocus,                 |``The window lost the focus (no data)``
| ** 3  ** |    sfEvtGainedFocus,               |``The window gained the focus (no data)``
| ** 4  ** |    sfEvtTextEntered,               |``A character was entered (data in event.text)``
| ** 5  ** |    sfEvtKeyPressed,                |``A key was pressed (data in event.key)``
| ** 6  ** |    sfEvtKeyReleased,               |``A key was released (data in event.key)``
| ** 7  ** |    sfEvtMouseWheelMoved,           |``The mouse wheel was scrolled (data in event.mouseWheel) (deprecated)``
| ** 8  ** |    sfEvtMouseWheelScrolled,        |``The mouse wheel was scrolled (data in event.mouseWheelScroll)``
| ** 9  ** |    sfEvtMouseButtonPressed,        |``A mouse button was pressed (data in event.mouseButton)``
| ** 10 ** |     sfEvtMouseButtonReleased,      |``A mouse button was released (data in event.mouseButton)``
| ** 11 ** |     sfEvtMouseMoved,               |``The mouse cursor moved (data in event.mouseMove)``
| ** 12 ** |     sfEvtMouseEntered,             |``The mouse cursor entered the area of the window (no data)``
| ** 13 ** |     sfEvtMouseLeft,                |``The mouse cursor left the area of the window (no data)``
| ** 14 ** |     sfEvtJoystickButtonPressed,    |``A joystick button was pressed (data in event.joystickButton)``
| ** 15 ** |     sfEvtJoystickButtonReleased,   |``A joystick button was released (data in event.joystickButton)``
| ** 16 ** |     sfEvtJoystickMoved,            |``The joystick moved along an axis (data in event.joystickMove)``
| ** 17 ** |     sfEvtJoystickConnected,        |``A joystick was connected (data in event.joystickConnect)``
| ** 18 ** |     sfEvtJoystickDisconnected,     |``A joystick was disconnected (data in event.joystickConnect)``
| ** 19 ** |     sfEvtTouchBegan,               |``A touch event began (data in event.touch)``
| ** 20 ** |     sfEvtTouchMoved,               |``A touch moved (data in event.touch)``
| ** 21 ** |     sfEvtTouchEnded,               |``A touch event ended (data in event.touch)``
| ** 22 ** |     sfEvtSensorChanged,            |``A sensor value changed (data in event.sensor)``
| ** 23 ** | |
| ** 24 ** |     sfEvtCount,                    |``Keep last -- the total number of event types``

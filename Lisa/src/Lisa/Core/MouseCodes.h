#pragma once

namespace Lisa {

	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0      = 0,
		Button1      = 1,
		Button2      = 2,
		Button3      = 3,
		Button4      = 4,
		Button5      = 5,
		Button6      = 6,
		Button7      = 7,

		ButtonLast   = Button7,
		ButtonLeft   = Button0,
		ButtonRight  = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define LS_MOUSE_BUTTON_0      ::Lisa::Mouse::Button0
#define LS_MOUSE_BUTTON_1      ::Lisa::Mouse::Button1
#define LS_MOUSE_BUTTON_2      ::Lisa::Mouse::Button2
#define LS_MOUSE_BUTTON_3      ::Lisa::Mouse::Button3
#define LS_MOUSE_BUTTON_4      ::Lisa::Mouse::Button4
#define LS_MOUSE_BUTTON_5      ::Lisa::Mouse::Button5
#define LS_MOUSE_BUTTON_6      ::Lisa::Mouse::Button6
#define LS_MOUSE_BUTTON_7      ::Lisa::Mouse::Button7
#define LS_MOUSE_BUTTON_LAST   ::Lisa::Mouse::ButtonLast
#define LS_MOUSE_BUTTON_LEFT   ::Lisa::Mouse::ButtonLeft
#define LS_MOUSE_BUTTON_RIGHT  ::Lisa::Mouse::ButtonRight
#define LS_MOUSE_BUTTON_MIDDLE ::Lisa::Mouse::ButtonMiddle
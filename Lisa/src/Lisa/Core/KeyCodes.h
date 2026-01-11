#pragma once

namespace Lisa {

	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space        = 32,
		Apostrophe   = 39, /* ' */
		Comma        = 44, /* , */
		Minus        = 45, /* - */
		Period       = 46, /* . */
		Slash        = 47, /* / */

		D0           = 48, /* 0 */
		D1           = 49, /* 1 */
		D2           = 50, /* 2 */
		D3           = 51, /* 3 */
		D4           = 52, /* 4 */
		D5           = 53, /* 5 */
		D6           = 54, /* 6 */
		D7           = 55, /* 7 */
		D8           = 56, /* 8 */
		D9           = 57, /* 9 */

		Semicolon    = 59, /* ; */
		Equal        = 61, /* = */

		A            = 65,
		B            = 66,
		C            = 67,
		D            = 68,
		E            = 69,
		F            = 70,
		G            = 71,
		H            = 72,
		I            = 73,
		J            = 74,
		K            = 75,
		L            = 76,
		M            = 77,
		N            = 78,
		O            = 79,
		P            = 80,
		Q            = 81,
		R            = 82,
		S            = 83,
		T            = 84,
		U            = 85,
		V            = 86,
		W            = 87,
		X            = 88,
		Y            = 89,
		Z            = 90,

		LeftBracket  = 91,  /* [ */
		Backslash    = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent  = 96,  /* ` */

		World1       = 161, /* non-US #1 */
		World2       = 162, /* non-US #2 */

		/* Function keys */
		Escape       = 256,
		Enter        = 257,
		Tab          = 258,
		Backspace    = 259,
		Insert       = 260,
		Delete       = 261,
		Right        = 262,
		Left         = 263,
		Down         = 264,
		Up           = 265,
		PageUp       = 266,
		PageDown     = 267,
		Home         = 268,
		End          = 269,
		CapsLock     = 280,
		ScrollLock   = 281,
		NumLock      = 282,
		PrintScreen  = 283,
		Pause        = 284,
		F1           = 290,
		F2           = 291,
		F3           = 292,
		F4           = 293,
		F5           = 294,
		F6           = 295,
		F7           = 296,
		F8           = 297,
		F9           = 298,
		F10          = 299,
		F11          = 300,
		F12          = 301,
		F13          = 302,
		F14          = 303,
		F15          = 304,
		F16          = 305,
		F17          = 306,
		F18          = 307,
		F19          = 308,
		F20          = 309,
		F21          = 310,
		F22          = 311,
		F23          = 312,
		F24          = 313,
		F25          = 314,

		/* Keypad */
		KP0          = 320,
		KP1          = 321,
		KP2          = 322,
		KP3          = 323,
		KP4          = 324,
		KP5          = 325,
		KP6          = 326,
		KP7          = 327,
		KP8          = 328,
		KP9          = 329,
		KPDecimal    = 330,
		KPDivide     = 331,
		KPMultiply   = 332,
		KPSubtract   = 333,
		KPAdd        = 334,
		KPEnter      = 335,
		KPEqual      = 336,

		LeftShift    = 340,
		LeftControl  = 341,
		LeftAlt      = 342,
		LeftSuper    = 343,
		RightShift   = 344,
		RightControl = 345,
		RightAlt     = 346,
		RightSuper   = 347,
		Menu         = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define LS_KEY_SPACE           ::Lisa::Key::Space
#define LS_KEY_APOSTROPHE      ::Lisa::Key::Apostrophe    /* ' */
#define LS_KEY_COMMA           ::Lisa::Key::Comma         /* , */
#define LS_KEY_MINUS           ::Lisa::Key::Minus         /* - */
#define LS_KEY_PERIOD          ::Lisa::Key::Period        /* . */
#define LS_KEY_SLASH           ::Lisa::Key::Slash         /* / */
#define LS_KEY_0               ::Lisa::Key::D0
#define LS_KEY_1               ::Lisa::Key::D1
#define LS_KEY_2               ::Lisa::Key::D2
#define LS_KEY_3               ::Lisa::Key::D3
#define LS_KEY_4               ::Lisa::Key::D4
#define LS_KEY_5               ::Lisa::Key::D5
#define LS_KEY_6               ::Lisa::Key::D6
#define LS_KEY_7               ::Lisa::Key::D7
#define LS_KEY_8               ::Lisa::Key::D8
#define LS_KEY_9               ::Lisa::Key::D9
#define LS_KEY_SEMICOLON       ::Lisa::Key::Semicolon     /* ; */
#define LS_KEY_EQUAL           ::Lisa::Key::Equal         /* = */
#define LS_KEY_A               ::Lisa::Key::A
#define LS_KEY_B               ::Lisa::Key::B
#define LS_KEY_C               ::Lisa::Key::C
#define LS_KEY_D               ::Lisa::Key::D
#define LS_KEY_E               ::Lisa::Key::E
#define LS_KEY_F               ::Lisa::Key::F
#define LS_KEY_G               ::Lisa::Key::G
#define LS_KEY_H               ::Lisa::Key::H
#define LS_KEY_I               ::Lisa::Key::I
#define LS_KEY_J               ::Lisa::Key::J
#define LS_KEY_K               ::Lisa::Key::K
#define LS_KEY_L               ::Lisa::Key::L
#define LS_KEY_M               ::Lisa::Key::M
#define LS_KEY_N               ::Lisa::Key::N
#define LS_KEY_O               ::Lisa::Key::O
#define LS_KEY_P               ::Lisa::Key::P
#define LS_KEY_Q               ::Lisa::Key::Q
#define LS_KEY_R               ::Lisa::Key::R
#define LS_KEY_S               ::Lisa::Key::S
#define LS_KEY_T               ::Lisa::Key::T
#define LS_KEY_U               ::Lisa::Key::U
#define LS_KEY_V               ::Lisa::Key::V
#define LS_KEY_W               ::Lisa::Key::W
#define LS_KEY_X               ::Lisa::Key::X
#define LS_KEY_Y               ::Lisa::Key::Y
#define LS_KEY_Z               ::Lisa::Key::Z
#define LS_KEY_LEFT_BRACKET    ::Lisa::Key::LeftBracket   /* [ */
#define LS_KEY_BACKSLASH       ::Lisa::Key::Backslash     /* \ */
#define LS_KEY_RIGHT_BRACKET   ::Lisa::Key::RightBracket  /* ] */
#define LS_KEY_GRAVE_ACCENT    ::Lisa::Key::GraveAccent   /* ` */
#define LS_KEY_WORLD_1         ::Lisa::Key::World1        /* non-US #1 */
#define LS_KEY_WORLD_2         ::Lisa::Key::World2        /* non-US #2 */

/* Function keys */
#define LS_KEY_ESCAPE          ::Lisa::Key::Escape
#define LS_KEY_ENTER           ::Lisa::Key::Enter
#define LS_KEY_TAB             ::Lisa::Key::Tab
#define LS_KEY_BACKSPACE       ::Lisa::Key::Backspace
#define LS_KEY_INSERT          ::Lisa::Key::Insert
#define LS_KEY_DELETE          ::Lisa::Key::Delete
#define LS_KEY_RIGHT           ::Lisa::Key::Right
#define LS_KEY_LEFT            ::Lisa::Key::Left
#define LS_KEY_DOWN            ::Lisa::Key::Down
#define LS_KEY_UP              ::Lisa::Key::Up
#define LS_KEY_PAGE_UP         ::Lisa::Key::PageUp
#define LS_KEY_PAGE_DOWN       ::Lisa::Key::PageDown
#define LS_KEY_HOME            ::Lisa::Key::Home
#define LS_KEY_END             ::Lisa::Key::End
#define LS_KEY_CAPS_LOCK       ::Lisa::Key::CapsLock
#define LS_KEY_SCROLL_LOCK     ::Lisa::Key::ScrollLock
#define LS_KEY_NUM_LOCK        ::Lisa::Key::NumLock
#define LS_KEY_PRINT_SCREEN    ::Lisa::Key::PrintScreen
#define LS_KEY_PAUSE           ::Lisa::Key::Pause
#define LS_KEY_F1              ::Lisa::Key::F1
#define LS_KEY_F2              ::Lisa::Key::F2
#define LS_KEY_F3              ::Lisa::Key::F3
#define LS_KEY_F4              ::Lisa::Key::F4
#define LS_KEY_F5              ::Lisa::Key::F5
#define LS_KEY_F6              ::Lisa::Key::F6
#define LS_KEY_F7              ::Lisa::Key::F7
#define LS_KEY_F8              ::Lisa::Key::F8
#define LS_KEY_F9              ::Lisa::Key::F9
#define LS_KEY_F10             ::Lisa::Key::F10
#define LS_KEY_F11             ::Lisa::Key::F11
#define LS_KEY_F12             ::Lisa::Key::F12
#define LS_KEY_F13             ::Lisa::Key::F13
#define LS_KEY_F14             ::Lisa::Key::F14
#define LS_KEY_F15             ::Lisa::Key::F15
#define LS_KEY_F16             ::Lisa::Key::F16
#define LS_KEY_F17             ::Lisa::Key::F17
#define LS_KEY_F18             ::Lisa::Key::F18
#define LS_KEY_F19             ::Lisa::Key::F19
#define LS_KEY_F20             ::Lisa::Key::F20
#define LS_KEY_F21             ::Lisa::Key::F21
#define LS_KEY_F22             ::Lisa::Key::F22
#define LS_KEY_F23             ::Lisa::Key::F23
#define LS_KEY_F24             ::Lisa::Key::F24
#define LS_KEY_F25             ::Lisa::Key::F25

/* Keypad */
#define LS_KEY_KP_0            ::Lisa::Key::KP0
#define LS_KEY_KP_1            ::Lisa::Key::KP1
#define LS_KEY_KP_2            ::Lisa::Key::KP2
#define LS_KEY_KP_3            ::Lisa::Key::KP3
#define LS_KEY_KP_4            ::Lisa::Key::KP4
#define LS_KEY_KP_5            ::Lisa::Key::KP5
#define LS_KEY_KP_6            ::Lisa::Key::KP6
#define LS_KEY_KP_7            ::Lisa::Key::KP7
#define LS_KEY_KP_8            ::Lisa::Key::KP8
#define LS_KEY_KP_9            ::Lisa::Key::KP9
#define LS_KEY_KP_DECIMAL      ::Lisa::Key::KPDecimal
#define LS_KEY_KP_DIVIDE       ::Lisa::Key::KPDivide
#define LS_KEY_KP_MULTIPLY     ::Lisa::Key::KPMultiply
#define LS_KEY_KP_SUBTRACT     ::Lisa::Key::KPSubtract
#define LS_KEY_KP_ADD          ::Lisa::Key::KPAdd
#define LS_KEY_KP_ENTER        ::Lisa::Key::KPEnter
#define LS_KEY_KP_EQUAL        ::Lisa::Key::KPEqual

#define LS_KEY_LEFT_SHIFT      ::Lisa::Key::LeftShift
#define LS_KEY_LEFT_CONTROL    ::Lisa::Key::LeftControl
#define LS_KEY_LEFT_ALT        ::Lisa::Key::LeftAlt
#define LS_KEY_LEFT_SUPER      ::Lisa::Key::LeftSuper
#define LS_KEY_RIGHT_SHIFT     ::Lisa::Key::RightShift
#define LS_KEY_RIGHT_CONTROL   ::Lisa::Key::RightControl
#define LS_KEY_RIGHT_ALT       ::Lisa::Key::RightAlt
#define LS_KEY_RIGHT_SUPER     ::Lisa::Key::RightSuper
#define LS_KEY_MENU            ::Lisa::Key::Menu
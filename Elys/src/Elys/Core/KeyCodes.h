
#pragma once

namespace Elys
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define HZ_KEY_SPACE           ::Elys::Key::Space
#define HZ_KEY_APOSTROPHE      ::Elys::Key::Apostrophe    /* ' */
#define HZ_KEY_COMMA           ::Elys::Key::Comma         /* , */
#define HZ_KEY_MINUS           ::Elys::Key::Minus         /* - */
#define HZ_KEY_PERIOD          ::Elys::Key::Period        /* . */
#define HZ_KEY_SLASH           ::Elys::Key::Slash         /* / */
#define HZ_KEY_0               ::Elys::Key::D0
#define HZ_KEY_1               ::Elys::Key::D1
#define HZ_KEY_2               ::Elys::Key::D2
#define HZ_KEY_3               ::Elys::Key::D3
#define HZ_KEY_4               ::Elys::Key::D4
#define HZ_KEY_5               ::Elys::Key::D5
#define HZ_KEY_6               ::Elys::Key::D6
#define HZ_KEY_7               ::Elys::Key::D7
#define HZ_KEY_8               ::Elys::Key::D8
#define HZ_KEY_9               ::Elys::Key::D9
#define HZ_KEY_SEMICOLON       ::Elys::Key::Semicolon     /* ; */
#define HZ_KEY_EQUAL           ::Elys::Key::Equal         /* = */
#define HZ_KEY_A               ::Elys::Key::A
#define HZ_KEY_B               ::Elys::Key::B
#define HZ_KEY_C               ::Elys::Key::C
#define HZ_KEY_D               ::Elys::Key::D
#define HZ_KEY_E               ::Elys::Key::E
#define HZ_KEY_F               ::Elys::Key::F
#define HZ_KEY_G               ::Elys::Key::G
#define HZ_KEY_H               ::Elys::Key::H
#define HZ_KEY_I               ::Elys::Key::I
#define HZ_KEY_J               ::Elys::Key::J
#define HZ_KEY_K               ::Elys::Key::K
#define HZ_KEY_L               ::Elys::Key::L
#define HZ_KEY_M               ::Elys::Key::M
#define HZ_KEY_N               ::Elys::Key::N
#define HZ_KEY_O               ::Elys::Key::O
#define HZ_KEY_P               ::Elys::Key::P
#define HZ_KEY_Q               ::Elys::Key::Q
#define HZ_KEY_R               ::Elys::Key::R
#define HZ_KEY_S               ::Elys::Key::S
#define HZ_KEY_T               ::Elys::Key::T
#define HZ_KEY_U               ::Elys::Key::U
#define HZ_KEY_V               ::Elys::Key::V
#define HZ_KEY_W               ::Elys::Key::W
#define HZ_KEY_X               ::Elys::Key::X
#define HZ_KEY_Y               ::Elys::Key::Y
#define HZ_KEY_Z               ::Elys::Key::Z
#define HZ_KEY_LEFT_BRACKET    ::Elys::Key::LeftBracket   /* [ */
#define HZ_KEY_BACKSLASH       ::Elys::Key::Backslash     /* \ */
#define HZ_KEY_RIGHT_BRACKET   ::Elys::Key::RightBracket  /* ] */
#define HZ_KEY_GRAVE_ACCENT    ::Elys::Key::GraveAccent   /* ` */
#define HZ_KEY_WORLD_1         ::Elys::Key::World1        /* non-US #1 */
#define HZ_KEY_WORLD_2         ::Elys::Key::World2        /* non-US #2 */

/* Function keys */
#define HZ_KEY_ESCAPE          ::Elys::Key::Escape
#define HZ_KEY_ENTER           ::Elys::Key::Enter
#define HZ_KEY_TAB             ::Elys::Key::Tab
#define HZ_KEY_BACKSPACE       ::Elys::Key::Backspace
#define HZ_KEY_INSERT          ::Elys::Key::Insert
#define HZ_KEY_DELETE          ::Elys::Key::Delete
#define HZ_KEY_RIGHT           ::Elys::Key::Right
#define HZ_KEY_LEFT            ::Elys::Key::Left
#define HZ_KEY_DOWN            ::Elys::Key::Down
#define HZ_KEY_UP              ::Elys::Key::Up
#define HZ_KEY_PAGE_UP         ::Elys::Key::PageUp
#define HZ_KEY_PAGE_DOWN       ::Elys::Key::PageDown
#define HZ_KEY_HOME            ::Elys::Key::Home
#define HZ_KEY_END             ::Elys::Key::End
#define HZ_KEY_CAPS_LOCK       ::Elys::Key::CapsLock
#define HZ_KEY_SCROLL_LOCK     ::Elys::Key::ScrollLock
#define HZ_KEY_NUM_LOCK        ::Elys::Key::NumLock
#define HZ_KEY_PRINT_SCREEN    ::Elys::Key::PrintScreen
#define HZ_KEY_PAUSE           ::Elys::Key::Pause
#define HZ_KEY_F1              ::Elys::Key::F1
#define HZ_KEY_F2              ::Elys::Key::F2
#define HZ_KEY_F3              ::Elys::Key::F3
#define HZ_KEY_F4              ::Elys::Key::F4
#define HZ_KEY_F5              ::Elys::Key::F5
#define HZ_KEY_F6              ::Elys::Key::F6
#define HZ_KEY_F7              ::Elys::Key::F7
#define HZ_KEY_F8              ::Elys::Key::F8
#define HZ_KEY_F9              ::Elys::Key::F9
#define HZ_KEY_F10             ::Elys::Key::F10
#define HZ_KEY_F11             ::Elys::Key::F11
#define HZ_KEY_F12             ::Elys::Key::F12
#define HZ_KEY_F13             ::Elys::Key::F13
#define HZ_KEY_F14             ::Elys::Key::F14
#define HZ_KEY_F15             ::Elys::Key::F15
#define HZ_KEY_F16             ::Elys::Key::F16
#define HZ_KEY_F17             ::Elys::Key::F17
#define HZ_KEY_F18             ::Elys::Key::F18
#define HZ_KEY_F19             ::Elys::Key::F19
#define HZ_KEY_F20             ::Elys::Key::F20
#define HZ_KEY_F21             ::Elys::Key::F21
#define HZ_KEY_F22             ::Elys::Key::F22
#define HZ_KEY_F23             ::Elys::Key::F23
#define HZ_KEY_F24             ::Elys::Key::F24
#define HZ_KEY_F25             ::Elys::Key::F25

/* Keypad */
#define HZ_KEY_KP_0            ::Elys::Key::KP0
#define HZ_KEY_KP_1            ::Elys::Key::KP1
#define HZ_KEY_KP_2            ::Elys::Key::KP2
#define HZ_KEY_KP_3            ::Elys::Key::KP3
#define HZ_KEY_KP_4            ::Elys::Key::KP4
#define HZ_KEY_KP_5            ::Elys::Key::KP5
#define HZ_KEY_KP_6            ::Elys::Key::KP6
#define HZ_KEY_KP_7            ::Elys::Key::KP7
#define HZ_KEY_KP_8            ::Elys::Key::KP8
#define HZ_KEY_KP_9            ::Elys::Key::KP9
#define HZ_KEY_KP_DECIMAL      ::Elys::Key::KPDecimal
#define HZ_KEY_KP_DIVIDE       ::Elys::Key::KPDivide
#define HZ_KEY_KP_MULTIPLY     ::Elys::Key::KPMultiply
#define HZ_KEY_KP_SUBTRACT     ::Elys::Key::KPSubtract
#define HZ_KEY_KP_ADD          ::Elys::Key::KPAdd
#define HZ_KEY_KP_ENTER        ::Elys::Key::KPEnter
#define HZ_KEY_KP_EQUAL        ::Elys::Key::KPEqual

#define HZ_KEY_LEFT_SHIFT      ::Elys::Key::LeftShift
#define HZ_KEY_LEFT_CONTROL    ::Elys::Key::LeftControl
#define HZ_KEY_LEFT_ALT        ::Elys::Key::LeftAlt
#define HZ_KEY_LEFT_SUPER      ::Elys::Key::LeftSuper
#define HZ_KEY_RIGHT_SHIFT     ::Elys::Key::RightShift
#define HZ_KEY_RIGHT_CONTROL   ::Elys::Key::RightControl
#define HZ_KEY_RIGHT_ALT       ::Elys::Key::RightAlt
#define HZ_KEY_RIGHT_SUPER     ::Elys::Key::RightSuper
#define HZ_KEY_MENU            ::Elys::Key::Menu
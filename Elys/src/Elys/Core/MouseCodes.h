#pragma once

namespace Elys
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define HZ_MOUSE_BUTTON_0      ::Elys::Mouse::Button0
#define HZ_MOUSE_BUTTON_1      ::Elys::Mouse::Button1
#define HZ_MOUSE_BUTTON_2      ::Elys::Mouse::Button2
#define HZ_MOUSE_BUTTON_3      ::Elys::Mouse::Button3
#define HZ_MOUSE_BUTTON_4      ::Elys::Mouse::Button4
#define HZ_MOUSE_BUTTON_5      ::Elys::Mouse::Button5
#define HZ_MOUSE_BUTTON_6      ::Elys::Mouse::Button6
#define HZ_MOUSE_BUTTON_7      ::Elys::Mouse::Button7
#define HZ_MOUSE_BUTTON_LAST   ::Elys::Mouse::ButtonLast
#define HZ_MOUSE_BUTTON_LEFT   ::Elys::Mouse::ButtonLeft
#define HZ_MOUSE_BUTTON_RIGHT  ::Elys::Mouse::ButtonRight
#define HZ_MOUSE_BUTTON_MIDDLE ::Elys::Mouse::ButtonMiddle

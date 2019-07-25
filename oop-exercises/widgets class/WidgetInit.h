#pragma once

#include "Widget.h"


Widget* GetAWidgetPtr(bool condition)
{
	if (condition)
		return new Widget{ "True cond" };

	else
		return new Widget{ "False cond" };
}

Widget GetAWidget(bool condition)
{
	if (condition)
		return { "True condition" };

	else
		return { "False condition" };
}

//_> should invoke copy ctor on returning
Widget GetAWidgetWorse(bool condition)
{
	Widget w{};

	if (condition) {
		w.SetName("true cond");
		return w;
	}
	else {
		w.SetName("false cond");
		return w;
	}
}


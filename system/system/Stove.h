#pragma once
#include "Appliance.h"

class Stove :public Appliance {
public:

private:
	struct HeatingElement {
		int power;
		bool isOn;
	};

};
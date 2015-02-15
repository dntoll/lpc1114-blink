#ifndef ARDUINO_STYLE
#define ARDUINO_STYLE

enum PIN_MODE {
	INPUT = 0,
	OUTPUT
};

enum PIN {
	GPIO0_0 = 0,
	GPIO0_1,
	GPIO0_2,
	GPIO0_3,
	GPIO0_4,
	GPIO0_5,
	GPIO0_6,
	GPIO0_7,
	GPIO0_8,
	GPIO0_9,
	GPIO1_0,
	GPIO1_1,
	GPIO1_2,
	GPIO1_3,
	GPIO1_4,
	GPIO1_5,
	GPIO1_6,
	GPIO1_7,
	GPIO1_8,
	GPIO1_9
};

enum DIGITAL_STATE {
	LOW = 0,
	HIGH = 1
};

LPC_GPIO_TypeDef* getPort(enum PIN pin) {
	switch (pin) {
		case GPIO0_0 :
		case GPIO0_1 :
		case GPIO0_2 :
		case GPIO0_3 :
		case GPIO0_4 :
		case GPIO0_5 :
		case GPIO0_6 :
		case GPIO0_7 :
		case GPIO0_8 :
		case GPIO0_9 : return LPC_GPIO0;
		case GPIO1_0 :
		case GPIO1_1 :
		case GPIO1_2 :
		case GPIO1_3 :
		case GPIO1_4 :
		case GPIO1_5 :
		case GPIO1_6 :
		case GPIO1_7 :
		case GPIO1_8 :
		case GPIO1_9 : return LPC_GPIO1;
	};

	return 0; //how to handle errors?
}

unsigned int getPin(enum PIN pin) {
	switch (pin) {
		case GPIO0_0 : return 1 << 0;
		case GPIO0_1 : return 1 << 1;
		case GPIO0_2 : return 1 << 2;
		case GPIO0_3 : return 1 << 3;
		case GPIO0_4 : return 1 << 4;
		case GPIO0_5 : return 1 << 5;
		case GPIO0_6 : return 1 << 6;
		case GPIO0_7 : return 1 << 7;
		case GPIO0_8 : return 1 << 8;
		case GPIO0_9 : return 1 << 9;
		case GPIO1_0 : return 1 << 0;
		case GPIO1_1 : return 1 << 1;
		case GPIO1_2 : return 1 << 2;
		case GPIO1_3 : return 1 << 3;
		case GPIO1_4 : return 1 << 4;
		case GPIO1_5 : return 1 << 5;
		case GPIO1_6 : return 1 << 6;
		case GPIO1_7 : return 1 << 7;
		case GPIO1_8 : return 1 << 8;
		case GPIO1_9 : return 1 << 9;
	};

	return 0; //how to handle errors?
}


void pinMode(enum PIN pin, enum PIN_MODE mode) {
	LPC_GPIO_TypeDef   * port = getPort(pin);
	unsigned int portPin = getPin(pin);

	if (mode == OUTPUT) {
		port->DIR |= portPin;
	} 
	//This is just a guess that the port is input by default, other modes?
	else if (mode == INPUT) {
		port->DIR &= ~portPin;
	}
}

void digitalWrite(enum PIN pin, enum DIGITAL_STATE value) {
	LPC_GPIO_TypeDef   * port = getPort(pin);
	unsigned int portPin = getPin(pin);
	
	if (value == HIGH) {
		port->DATA |= portPin;
	} else {
		port->DATA &= ~portPin;
	}
}

enum DIGITAL_STATE digitalRead(enum PIN pin) {
	LPC_GPIO_TypeDef   * port = getPort(pin);
	enum PIN portPin = getPin(pin);
	
	
	return (port->DATA & portPin);
}

void delay(unsigned int timeMilliseconds) {
	volatile uint32_t count, count_max = 2000 * timeMilliseconds ;

	for (count = 0; count < count_max; count++);	// delay

}

#endif

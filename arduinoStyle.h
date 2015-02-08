#ifndef ARDUINO_STYLE
#define ARDUINO_STYLE

enum PIN_MODE {
	INPUT = 0,
	OUTPUT
};

enum PIN {
	GPIO1_8 = 0
};

enum DIGITAL_STATE {
	LOW = 0,
	HIGH = 1
};

void pinMode(unsigned int pin, unsigned int mode) {
	LPC_GPIO_TypeDef   * port;
	unsigned int portPin = 0;

	//do the translation
	//maybe a mask would be better?
	switch (pin) {
		case GPIO1_8 : port = LPC_GPIO1; portPin = 1 << 8;
	};
	
	if (mode == OUTPUT) {
		port->DIR |= portPin;
	}
}

void digitalWrite(unsigned int pin, unsigned int value) {
	LPC_GPIO_TypeDef   * port;
	unsigned int portPin = 0;
	switch (pin) {
		case GPIO1_8 : port = LPC_GPIO1; portPin = 1 << 8;
	};
	
	if (value == HIGH) {
		port->DATA |= portPin;
	} else {
		port->DATA &= ~portPin;
	}
}

void delay(unsigned int timeMilliseconds) {
	volatile uint32_t count, count_max = 2000 * timeMilliseconds ;

	for (count = 0; count < count_max; count++);	// delay

}

#endif

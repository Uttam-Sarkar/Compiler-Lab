#define RCC_CR  (*((volatile unsigned long *)0x40021000))
#define RCC_APB2ENR  (*((volatile unsigned long *)0x40021018))
#define RCC_CFGR  (*((volatile unsigned long *)0x40021004))

#define GPIOC_CRH  (*((volatile unsigned long *)0x40011004))
#define GPIOC_ODR  (*((volatile unsigned long *)0x4001100C))

#define SysTick_CTRL  (*((volatile unsigned long *)0xE000E010)) 
#define SysTick_LOAD  (*((volatile unsigned long *)0xE000E014)) 
#define SysTick_VAL  (*((volatile unsigned long *)0xE000E018)) 

void systikInit();
void miliSecDelay();
void delay(int time);
void systemClockInit();

int main(){
	RCC_APB2ENR |= 0x10;
	GPIOC_CRH &= 0xFF0FFFFF;
	GPIOC_CRH |= 0x300000;
	
	
	systikInit();
	systemClockInit();
	
	
	while(1){
		GPIOC_ODR ^= 0x2000;		
		delay(1000);		
	}
}



void systikInit(){
	SysTick_CTRL = 0;
	SysTick_LOAD = 0x00ffffff;
	SysTick_VAL = 0;
	
	SysTick_CTRL |= 5;
}

void systemClockInit(){
	RCC_CFGR &= ~(0x3); 
	while((RCC_CFGR & (3<<2)) != (0<<2));

}

void miliSecDelay(){
	SysTick_LOAD = 8000 - 1;
	SysTick_VAL = 0;
	while((SysTick_CTRL & 0x10000) == 0);
}

void delay(int time){
	for(int i=0; i<time; i++){
		miliSecDelay();
	}
}

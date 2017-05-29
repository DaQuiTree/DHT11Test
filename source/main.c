#include "config.h"
#include "lcd12864.h"
#include "DHT11.h"	

void main()
{
	uint8 temp,humi;
	uint16 dat[3];

	InitLCD12864();
	ConfigureDHT11();
	DHT11GetData(&humi, &temp);

	dat[0] = temp/10 + 0xA3B0;
	dat[1] = temp%10 + 0xA3B0;
	dat[2] = 0xA1E6; 
	LCDShowCN(3,1,dat,3);  //ÎÂ¶È

	dat[0] = humi/10 + 0xA3B0;
	dat[1] = humi%10 + 0xA3B0;
	dat[2] = 0xA3A5; 
	LCDShowCN(3,2,dat,3);  //Êª¶È

	while(1);
}


#include <stdio.h>

signed long int t_fine;

double BME280_Temperature_double(signed long int adc_T);
double BME280_Pressure_double(signed long int adc_P);
double BME280_Humidity_double(signed long int adc_H);


int main()
{
	signed long int i;
	printf("Hello World!\n");
	printf("Please Input temp:");
	scanf("%x", &i);
	printf("%.3f\n", BME280_Temperature_double(i));	
}

double BME280_Temperature_double(signed long int adc_T)
{
	double var1, var2, T;
	unsigned long int dig_T1 = 0x6e6f; 
	signed long int dig_T2 = 0x684b;
	signed long int dig_T3 = 0x0032;
	var1 = (((double)adc_T)/16384.0 - ((double)dig_T1)/1024.0) * ((double)dig_T2);
	var2 = ((((double)adc_T)/131072.0 - ((double)dig_T1)/8192.0)) * ((double)dig_T3);
	t_fine = (signed long int)(var1+var2);
	T = (var1 + var2) / 5120.0;
	return T; 
}


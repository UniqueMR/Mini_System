/*
 * square_wave.cpp
 *
 *  Created on: 2021��5��31��
 *      Author: Unique MR
 */
#include "include.hpp"

const int counter0_initial = 144;

void square_wave(int &volt,int &edge,int &counter,int &freq_change,int &volt_set,int &blank)
{
	const int counter_max = counter0_initial * 100 / freq_change;

	if(counter <= ((counter_max*2*blank)/100))//countermax * 2��ʾһ�����ڵļ������ȣ�blank�����ߵ�ƽ��ռ�İٷֱ�
		volt = 4095 * volt_set/340;
	else if(counter >= counter_max*2 )
		counter = 0;
	else
		volt = 0;
	counter++;
	Xil_Out16(XPAR_AXI_QUAD_SPI_0_BASEADDR+XSP_DTR_OFFSET,volt&0xfff);//����SPI���䣬����ʱ�Ӻ�Ƭѡ�ź�
}

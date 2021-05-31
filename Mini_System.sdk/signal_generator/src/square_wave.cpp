/*
 * square_wave.cpp
 *
 *  Created on: 2021��5��31��
 *      Author: Unique MR
 */
#include "include.hpp"

void square_wave(int &volt,int &edge,int &counter)
{
	if(counter >= 0xfff)
	{
		if(edge == 1)
			edge = 0;
		else
			edge = 1;
		counter = 0;
	}
	if(edge == 0)
		volt = 0xfff;
	else
		volt = 0;
	counter++;
	Xil_Out16(XPAR_AXI_QUAD_SPI_0_BASEADDR+XSP_DTR_OFFSET,volt&0xfff);//����SPI���䣬����ʱ�Ӻ�Ƭѡ�ź�
}
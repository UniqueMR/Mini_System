/*
 * sawtooth_wave.c
 *
 *  Created on: 2021��5��31��
 *      Author: Unique MR
 */
#include "include.h"

void sawtooth_wave(int volt)
{
	volt++;
	Xil_Out16(XPAR_AXI_QUAD_SPI_0_BASEADDR+XSP_DTR_OFFSET,volt&0xfff);//����SPI���䣬����ʱ�Ӻ�Ƭѡ�ź�
}
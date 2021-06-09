/*
 * transition.cpp
 *
 *  Created on: 2021��6��7��
 *      Author: uniqueMR
 */

#include "include.hpp"

const int segcode_change[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
const int segcode_p[4] = {0x08,0x03,0x46,0x21};
void transition(unsigned short control,int &volt_set,int &freq_change,int *segcode)
{
	//���ɷ��ȵ����źź�Ƶ�ʿ����ź�
	int volt_set_control = (control >> 2)&0x3f;
	int freq_change_control = (control >> 8)&0x3f;
	volt_set -= (volt_set_control*5);

	int freq_change_regulation = 0;//����Ƶ�ʸı�ķ��򣬼�����Ƶ�ʻ��Ǽ�СƵ��
	if((freq_change_control >> 5)&0x1)
		freq_change_regulation = 1;
	else freq_change_regulation = 0;

	int freq_change_value = freq_change_control&0x1f;//����Ƶ�ʸı�ķ���
	if(!freq_change_regulation)
		freq_change += (freq_change_value*20);
	else
		freq_change -= (freq_change_value*20);

	//���ɲ���ѡ���źš�
	int alter = control&0x3;

	//������Ҫ��ʵ�Ķ���
	int volt_0 = volt_set % 10;
	int volt_1 = (volt_set / 10) % 10;
	int volt_2 = volt_set / 100;

	int freq_0 = freq_change % 10;
	int freq_1 = (freq_change / 10) % 10;
	int freq_2 = (freq_change / 100) % 10;
	int freq_3 = (freq_change / 1000) % 10;

	segcode[7] = segcode_change[freq_0];
	segcode[6] = segcode_change[freq_1];
	segcode[5] = segcode_change[freq_2];
	segcode[4] = segcode_change[freq_3];
	segcode[3] = segcode_change[volt_0];
	segcode[2] = segcode_change[volt_1];
	segcode[1] = segcode_change[volt_2]&0x7f;
	segcode[0] = segcode_p[alter];

	return;
}

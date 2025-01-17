/*
 * button_handle.cpp
 *
 *  Created on: 2021��6��8��
 *      Author: uniqueMR
 */
#include "include.hpp"

void button_handle(int &blank)
{
	int btncode;
	btncode =Xil_In32(XPAR_AXI_GPIO_2_BASEADDR+XGPIO_DATA_OFFSET);
	    	if(btncode == 0x2)
	    		blank -= 1;
	    	else if(btncode == 0x8)
	    		blank += 1;
	    	else if(btncode == 0x10)
	    		blank = 50;
	    	else;
			xil_printf("The pushed button's code is 0x%x\n",btncode);
			xil_printf("The blank is %d\n",blank);


	        Xil_Out32(XPAR_AXI_GPIO_2_BASEADDR+XGPIO_ISR_OFFSET,Xil_In32(XPAR_AXI_GPIO_2_BASEADDR+XGPIO_ISR_OFFSET));
}

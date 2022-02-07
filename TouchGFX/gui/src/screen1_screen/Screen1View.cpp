#include <gui/screen1_screen/Screen1View.hpp>
#include <../gui/include/gui/containers/MenuElement.hpp>
#include "main.h"
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <stdio.h>
#include <string.h>

extern TIM_HandleTypeDef htim1;

extern uint8_t setMode;

extern uint8_t needChangeScreen;
extern int8_t enc_value;
uint32_t cur_pos = 1;

uint8_t sel = 0;

struct settings{
	struct param set[5];
}settings;


Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

	strcpy("Set1",settings.set[0].name);
	settings.set[0].value = 32;

	strcpy("Set2",settings.set[1].name);
	settings.set[1].value = 32;

	strcpy("Set3",settings.set[2].name);
	settings.set[2].value = 32;

	strcpy("Set4",settings.set[3].name);
	settings.set[3].value = 32;

	strcpy("Set5",settings.set[4].name);
	settings.set[4].value = 32;
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	if(needChangeScreen == 1)
	{
		needChangeScreen = 0;
		if(setMode == 0)
			application().gotoScreen2ScreenNoTransition();
	}
	if(setMode == 0)
	{
		button1.setAlpha(100);
		button1.invalidate();
		if(enc_value > 3)
		{
			if(cur_pos<10) cur_pos++;
			__HAL_TIM_SET_COUNTER(&htim1, 0);
		}
		if(enc_value < -3)
		{
			if(cur_pos > 1)cur_pos--;
			__HAL_TIM_SET_COUNTER(&htim1, 0);
		}

	}
	if(setMode == 1)
	{
		button1.setAlpha(210);
		button1.invalidate();
		int8_t val =  __HAL_TIM_GET_COUNTER(&htim1);
		settings.set[cur_pos-1].value += val;
		__HAL_TIM_SET_COUNTER(&htim1, 0);
		scrollList1ListItems.element[cur_pos-1].setNumber(settings.set[cur_pos-1].value);
	}


	enc_value = __HAL_TIM_GET_COUNTER(&htim1);
	enc_value *= -1;
	scrollList1.animateToItem(cur_pos-1, 6);
	scrollList1.invalidate();
	button1.moveTo(21, scrollList1ListItems.element[cur_pos-1].getY());
	button1.invalidate();

	for(uint16_t i =0; i<5; i++)
		scrollList1ListItems.element[i].setNumber(settings.set[i].value);


}

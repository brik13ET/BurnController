#include <gui/screen1_screen/Screen1View.hpp>
#include <../gui/include/gui/containers/MenuElement.hpp>
#include "main.h"
#include <gui_generated/common/FrontendApplicationBase.hpp>
extern TIM_HandleTypeDef htim1;

extern uint8_t setMode;

extern uint8_t needChangeScreen;
extern int8_t enc_value;
uint32_t cur_pos = 1;

uint8_t sel = 0;

extern struct settings  settings;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	scrollList1ListItems.element[2].setNumber(15);
	if(needChangeScreen == 1)
	{
		needChangeScreen = 0;
		application().gotoScreen2ScreenNoTransition();
	}
	if(setMode == 0)
	{
		radioButton1.setAlpha(0);
		radioButton1.invalidate();
		if(enc_value > 3)
		{
			if(cur_pos<4) cur_pos++;
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
		cur_pos = 1;
		radioButton1.setAlpha(255);
		radioButton1.invalidate();

		//scrollWheel1UpdateCenterItem(item, itemIndex)
		//scrollWheel1SelectedListItems.element[1].setNumber((int)(-1 *__HAL_TIM_GET_COUNTER(&htim1)));
		//scrollWheel1ListItems.element[0].

	}
	enc_value = __HAL_TIM_GET_COUNTER(&htim1);
	enc_value *= -1;
	scrollList1.animateToItem(cur_pos-1, 100);
	scrollList1.invalidate();
	//scrollWheel1.animateToItem(cur_pos-1, 4);



	//Unicode::snprintf(scrollWheel1.Container(1).textArea1Buffer, scrollWheel1.Container(1)., "%d", 9);*/

}

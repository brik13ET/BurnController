#include <gui/status_screen/StatusView.hpp>

#include <gui/containers/MenuElement.hpp>
#include "main.h"

StatusView::StatusView()
{

	for(uint16_t i =0; i<status_SIZE; i++)
	{
		scrollWheel1ListItems.element[i].Rename(status[i].name);
	}
}

void StatusView::setupScreen()
{
    StatusViewBase::setupScreen();
}

void StatusView::tearDownScreen()
{
    StatusViewBase::tearDownScreen();
}

void StatusView::handleTickEvent()
{
	if(needChangeScreen == 1)
	{
		needChangeScreen = 0;
		application().gotoSettingsScreenSlideTransitionEast();
		return;
	}
	if(enc_value > 0)
	{
		if(cur_pos<status_SIZE) cur_pos++;
		__HAL_TIM_SET_COUNTER(&htim1, 0);
	}
	if(enc_value < 0)
	{
		if(cur_pos > 1)cur_pos--;
		__HAL_TIM_SET_COUNTER(&htim1, 0);
	}
	enc_value = __HAL_TIM_GET_COUNTER(&htim1);
	enc_value *= -1;
	scrollWheel1.animateToItem(cur_pos-1, 6);

	for(uint16_t i =0; i<status_SIZE; i++)
	{
		scrollWheel1ListItems.element[i].setNumber(status[i].value);
	}
	scrollWheel1.invalidate();
}

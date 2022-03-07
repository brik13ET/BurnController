#include <gui/settings_screen/SettingsView.hpp>

#include <gui/containers/MenuElement.hpp>
#include "main.h"

SettingsView::SettingsView()
{
	for(uint16_t i =0; i<set_SIZE; i++)
	{
		scrollWheel1ListItems.element[i].Rename(set[i].name);
	}
}

void SettingsView::setupScreen()
{
    SettingsViewBase::setupScreen();
}

void SettingsView::tearDownScreen()
{
    SettingsViewBase::tearDownScreen();
}

void SettingsView::handleTickEvent()
{

	if(needChangeScreen == 1)
	{
		needChangeScreen = 0;
		if(setMode == 0)
			application().gotoAdvancedScreenSlideTransitionEast();
		return;
	}
	if(setMode == 0)
	{
		if(enc_value > 0)
		{
			if(cur_pos<set_SIZE) cur_pos++;
			__HAL_TIM_SET_COUNTER(&htim1, 0);
		}
		if(enc_value < 0)
		{
			if(cur_pos > 1)cur_pos--;
			__HAL_TIM_SET_COUNTER(&htim1, 0);
		}

	}
	if(setMode == 1)
	{
		int8_t val =  __HAL_TIM_GET_COUNTER(&htim1);
		set[cur_pos-1].value += val;
		__HAL_TIM_SET_COUNTER(&htim1, 0);
		scrollWheel1ListItems.element[cur_pos-1].setNumber(set[cur_pos-1].value);
	}


	enc_value = __HAL_TIM_GET_COUNTER(&htim1);
	enc_value *= -1;
	scrollWheel1.animateToItem(cur_pos-1, 6);
	for (uint8_t i = 0; i < scrollWheel1ListItems.getNumberOfDrawables(); ++i) {
		scrollWheel1ListItems[i].setNumber(set[i].value);
		scrollWheel1ListItems[i].invalidate();
	}
}

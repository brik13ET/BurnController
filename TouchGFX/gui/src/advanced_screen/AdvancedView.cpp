#include <gui/advanced_screen/AdvancedView.hpp>

#include <gui/containers/MenuElement.hpp>
#include "main.h"

AdvancedView::AdvancedView()
{
	for(uint16_t i =0; i<rareset_SIZE; i++)
	{
		scrollWheel1ListItems.element[i].Rename(rareset[i].name);
	}
}

void AdvancedView::setupScreen()
{
    AdvancedViewBase::setupScreen();
}

void AdvancedView::tearDownScreen()
{
    AdvancedViewBase::tearDownScreen();
}

void AdvancedView::handleTickEvent()
{

	if(needChangeScreen == 1)
	{
		needChangeScreen = 0;
		if(setMode == 0)
			application().gotoStatusScreenSlideTransitionWest();
		return;
	}
	if(setMode == 0)
	{
		if(enc_value > 0)
		{
			if(cur_pos<rareset_SIZE) cur_pos++;
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
		scrollWheel1ListItems.element[cur_pos-1].setNumber(rareset[cur_pos-1].value);
	}


	enc_value = __HAL_TIM_GET_COUNTER(&htim1);
	enc_value *= -1;
	scrollWheel1.animateToItem(cur_pos-1, 6);
	for(uint16_t i=0; i<rareset_SIZE; i++)
		scrollWheel1ListItems.element[i].setNumber(rareset[i].value);
	scrollWheel1.invalidate();
}

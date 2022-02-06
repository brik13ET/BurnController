#include <gui/screen2_screen/Screen2View.hpp>
#include "main.h"
#include <stdio.h>
#include <string.h>

extern uint8_t needChangeScreen;

struct status{
	struct param val1;
	struct param val2;
	struct param val3;
	struct param val4;
	struct param val5;
}status;

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

	strcpy((char*)"Val1",status.val1.name);
	status.val1.value = 61;

	strcpy((char*)"Val2",status.val2.name);
	status.val2.value = 62;

	strcpy((char*)"Val3",status.val3.name);
	status.val3.value = 63;

	strcpy((char*)"Val4",status.val4.name);
	status.val4.value = 64;

	strcpy((char*)"Val5",status.val5.name);
	status.val5.value = 65;
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}
void Screen2View::handleTickEvent()
{
	if(needChangeScreen == 1)
	{
		needChangeScreen = 0;
		application().gotoScreen1ScreenNoTransition();
	}

	Unicode::snprintf(set1Buffer, SET1_SIZE, "%d",  status.val1.value);
	set1.invalidate();

	Unicode::snprintf(set2Buffer, SET2_SIZE, "%d",  status.val2.value);
	set2.invalidate();

	Unicode::snprintf(set3Buffer, SET3_SIZE, "%d",  status.val3.value);
	set3.invalidate();

	Unicode::snprintf(set4Buffer, SET4_SIZE, "%d",  status.val4.value);
	set4.invalidate();







}

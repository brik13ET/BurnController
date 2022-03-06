#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "main.h"

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
	// update status
	static uint16_t  __k = 0;
	__k++;
	for (uint8_t __tmp = 0; __tmp < status_SIZE; ++__tmp) {
		status[__tmp].value = (__k >> 2) + __tmp;
	}
}

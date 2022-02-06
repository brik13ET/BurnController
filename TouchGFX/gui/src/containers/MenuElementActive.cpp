#include <gui/containers/MenuElementActive.hpp>

MenuElementActive::MenuElementActive()
{

}

void MenuElementActive::initialize()
{
    MenuElementActiveBase::initialize();
}
void MenuElementActive::setNumber(int no)
{
	Unicode::snprintf(valueBuffer, VALUE_SIZE, "%i", no);
	value.invalidate();
}

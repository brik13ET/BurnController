#include <gui/containers/MenuElement.hpp>

MenuElement::MenuElement()
{

}

void MenuElement::initialize()
{
    MenuElementBase::initialize();
}
void MenuElement::setNumber(int no)
{
	Unicode::snprintf(valueBuffer, VALUE_SIZE, "%i", no);
	value.invalidate();
}

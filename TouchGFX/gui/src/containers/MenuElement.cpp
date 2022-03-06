#include <gui/containers/MenuElement.hpp>
#include <stdint.h>

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
}

void MenuElement::Rename(uint16_t* s)
{
	Unicode::strncpy(paramNameBuffer, s, PARAMNAME_SIZE);
}

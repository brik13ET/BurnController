/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/MenuElementActiveBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

MenuElementActiveBase::MenuElementActiveBase()
{
    setWidth(251);
    setHeight(60);
    paramName.setXY(58, 18);
    paramName.setColor(touchgfx::Color::getColorFromRGB(0, 17, 255));
    paramName.setLinespacing(0);
    paramName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_63VS));

    value.setXY(198, 18);
    value.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    value.setLinespacing(0);
    Unicode::snprintf(valueBuffer, VALUE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_XKBD).getText());
    value.setWildcard(valueBuffer);
    value.resizeToCurrentText();
    value.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZP7Q));

    add(paramName);
    add(value);
}

void MenuElementActiveBase::initialize()
{

}


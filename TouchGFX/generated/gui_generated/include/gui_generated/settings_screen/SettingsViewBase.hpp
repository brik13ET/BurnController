/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGSVIEWBASE_HPP
#define SETTINGSVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/scrollers/ScrollWheel.hpp>
#include <gui/containers/MenuElement.hpp>

#include "main.h"

class SettingsViewBase : public touchgfx::View<SettingsPresenter>
{
public:
    SettingsViewBase();
    virtual ~SettingsViewBase() {}
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

    virtual void scrollWheel1UpdateItem(MenuElement& item, int16_t itemIndex)
    {
        // Override and implement this function in Settings
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::ScrollWheel scrollWheel1;
    touchgfx::DrawableListItems<MenuElement, set_SIZE> scrollWheel1ListItems;

private:
    touchgfx::Callback<SettingsViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

};

#endif // SETTINGSVIEWBASE_HPP

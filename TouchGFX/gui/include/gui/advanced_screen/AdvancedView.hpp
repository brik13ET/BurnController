#ifndef ADVANCEDVIEW_HPP
#define ADVANCEDVIEW_HPP

#include <gui_generated/advanced_screen/AdvancedViewBase.hpp>
#include <gui/advanced_screen/AdvancedPresenter.hpp>

#include "main.h"

class AdvancedView : public AdvancedViewBase
{
public:
    AdvancedView();
    virtual ~AdvancedView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void scrollWheel1UpdateItem(MenuElement& item, int16_t itemIndex);
protected:
    uint32_t cur_pos = 1;
    uint8_t sel = 0;
};

#endif // ADVANCEDVIEW_HPP

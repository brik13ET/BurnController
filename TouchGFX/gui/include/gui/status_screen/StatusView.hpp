#ifndef STATUSVIEW_HPP
#define STATUSVIEW_HPP

#include <gui_generated/status_screen/StatusViewBase.hpp>
#include <gui/status_screen/StatusPresenter.hpp>

class StatusView : public StatusViewBase
{
public:
    StatusView();
    virtual ~StatusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    uint32_t cur_pos = 1;
    uint8_t sel = 0;
};

#endif // STATUSVIEW_HPP

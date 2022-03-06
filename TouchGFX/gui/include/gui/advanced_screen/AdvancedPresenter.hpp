#ifndef ADVANCEDPRESENTER_HPP
#define ADVANCEDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AdvancedView;

class AdvancedPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AdvancedPresenter(AdvancedView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~AdvancedPresenter() {};

private:
    AdvancedPresenter();

    AdvancedView& view;
};

#endif // ADVANCEDPRESENTER_HPP

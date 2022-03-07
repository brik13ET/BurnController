#ifndef MENUELEMENT_HPP
#define MENUELEMENT_HPP

#include <gui_generated/containers/MenuElementBase.hpp>

class MenuElement : public MenuElementBase
{
public:
    MenuElement();
    virtual ~MenuElement() {}

    virtual void initialize();

    virtual void setNumber(int no);

protected:
};

#endif // MENUELEMENT_HPP

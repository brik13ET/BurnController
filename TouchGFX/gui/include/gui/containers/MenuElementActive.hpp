#ifndef MENUELEMENTACTIVE_HPP
#define MENUELEMENTACTIVE_HPP

#include <gui_generated/containers/MenuElementActiveBase.hpp>

class MenuElementActive : public MenuElementActiveBase
{
public:
    MenuElementActive();
    virtual ~MenuElementActive() {}

    virtual void initialize();
    virtual void setNumber(int no);
protected:
};

#endif // MENUELEMENTACTIVE_HPP

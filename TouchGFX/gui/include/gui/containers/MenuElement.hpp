#ifndef MENUELEMENT_HPP
#define MENUELEMENT_HPP

#include <gui_generated/containers/MenuElementBase.hpp>
#include <stdint.h>

class MenuElement : public MenuElementBase
{
public:
    MenuElement();
    virtual ~MenuElement() {}

    virtual void initialize();

    virtual void setNumber(int no);

    virtual void Rename(uint16_t* s);

protected:
};

#endif // MENUELEMENT_HPP

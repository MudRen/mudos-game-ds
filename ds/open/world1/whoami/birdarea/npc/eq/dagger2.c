#include <weapon.h>
inherit NEEDLE;

void create()
{
        set_name("短針",({"needle"}) );
        set("long","一根普通的短針，看得出來只是尋常鐵所打造出來的。\n");
        set_weight(800);
        if (clonep() )
        set_default_object(__FILE__);
        else {
              set("unit","根");
              set("value",100);
              set("material", "iron");
        }
        set("wield_msg","$N手上一晃，捏起了一根$n當武器。\n");
        init_needle(8);
        setup();
}


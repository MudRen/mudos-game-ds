#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("匕首",({"dagger"}) );
        set("long","一把普通的匕首，看得出來只是尋常鐵所打造出來的。\n");
        set_weight(800);
        if (clonep() )
        set_default_object(__FILE__);
        else {
              set("unit","把");
              set("material", "iron");
        }
        set("wield_msg","$N手上一晃，拿起了一把$n當武器。\n");
        init_dagger(8);
        setup();
}

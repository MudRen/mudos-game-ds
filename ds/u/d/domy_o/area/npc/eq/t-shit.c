#include <armor.h>


inherit CLOTH;

void create()
{
        set_name("T��",({"t shit","shit"}) );
        set("long","�\�a�u�`������A�A�������C\n");
        set_weight(1200);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
        set("value",500);
          set("armor_prop/armor",3);
        }
        setup();
}


#include <armor.h>
inherit HEAD;

void create()
{
        set_name("制服帽",({"waiter cap","cap"}) );
        set("long","一頂服務生專用的制服帽。\n");
    set_weight(300);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","頂");
      set("value",50);           
      set("armor_prop/armor",2);
        }
        setup();
}



#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("榮耀之靴", ({ "honor boots","boots" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
這是在戰場上立了大功，由國王親自賜予，代表著榮耀的靴子。
LONG
);
                set("unit", "雙");
                set("material", "silver");
                set("armor_prop/shield", 6);
        }
       setup();
}

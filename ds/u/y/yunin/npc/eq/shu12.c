#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR "修羅之盔〥" NOR,({ "shu lo helmet","helmet"}) );
        set("long","四大塔王之一的燕非彥使用的防具。\n");
        set_weight(2400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cold");
                set("unit","頂");
        }
        set("value",4000);
        set("armor_prop/armor",15);
        set("armor_prop/con",1);
             setup();
        set("volume",3);
}


#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(CYN"神武護腿"NOR ,({ "god legging","legging" }) );
        set("long","神武教掌門人所穿戴的護腿。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","雙");
                set("value",2000);
                set("volume",1);
                set("armor_prop/armor", 5);
        }
        setup();
}

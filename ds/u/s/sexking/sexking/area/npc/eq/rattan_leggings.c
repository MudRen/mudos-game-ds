#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("藤護膝",({"rattan leggings","leggings"}) );
        set("long",@LONG
這是一雙用竹藤晒乾做成的護膝，可防水。
LONG
);
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "雙");
        }
        set("armor_prop/armor",4);
        setup();
        set("value",650);
        set("volume", 2);
}


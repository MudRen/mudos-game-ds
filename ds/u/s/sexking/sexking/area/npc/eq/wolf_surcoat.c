#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("天狼戰袍" ,({ "wolf surcoat","surcoat" }) );
        set("long","相傳當年天齊二狼丸去勇闖天狼山，將天狼殺死，並本牠的皮
                 剝下做成了這件戰袍。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",25);
        set("limit_int",10);
        set_weight(9020);
        set("unit", "件" );
       set("value",4500);
        set("armor_prop/armor", 12);
        set("volume",7);
    set("armor_prop/con",1);
        }
        setup();
}


// cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
set_name(HIB"青鱗衣"NOR,({"blue clothes","clothes"}));
set("long", @LONG
這是壹件由許多青色鱗片所編織成的一件衣服, 防禦力似乎不錯。
LONG);
set_weight(3900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "件");
set("value",6300+random(700));
set("limit_lv",34);
set("material", "cloth");
//set("armor_prop/armor",78);
//set("armor_prop/defense",1);
}
        setup();
}



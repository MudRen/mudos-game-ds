#include <ansi.h>

#include <armor.h>

inherit CLOAK;

void create()
{
set_name("綠晶披風",({"green cloak","cloak"}) );
set("long","一件十分華麗的深綠色披風。兩端還繡了幾顆水晶在上面。\n");
set_weight(3400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","cloth");
set("unit", "件");
set("value",5473);
//set("armor_prop/armor",33);
set("armor_prop/dex",1);
set("limit_lv",51);
        }
        setup();
}

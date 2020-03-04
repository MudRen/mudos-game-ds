#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(CYN "青銅獸甲" NOR,({ "copper armor","armor" }) );
        set("long",@LONG
這是一副使用青銅及獸皮做成的獸甲，兼顧了防禦及保暖的作用，最適合
常年在戰場上的人使用。
LONG
);
        set_weight(22500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "silver");
        set("unit", "件" );
        }
        set("limit_con",30);
        set("limit_lv",25);
        set("value", 5000);
        set("armor_prop/armor", 30);
        set("armor_prop/dex", -2);
        set("armor_prop/con",  1);
        setup();
}



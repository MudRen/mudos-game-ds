#include <armor.h>

inherit ARMOR;
void create()
{
        set_name("羊毛軟鎧甲", ({ "gambeson armor","armor" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long","一件具有羊毛襯裡的鎧甲，穿起來不但增強了防禦力，也顧及了舒服。\n");
        set("unit","件");
        set("value",0);
        set_weight(12340);
        set("material","leather");
        set("armor_prop/armor",40);
        set("armor_prop/con",2);
        }
        setup();
}


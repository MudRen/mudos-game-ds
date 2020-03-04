#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIY "日月護星手" NOR ,({ "sun-moon gloves","gloves" }) );
        set("long",@LONG
這是一雙造型非常富有巧思的護手，這雙護手上繡有一幅「日月拱星」
的巧工圖，繡工之精，直把這幅難以繪製的圖發揮到盡善盡美、讚為觀止
的境界，真可謂是巧奪天工也不為過。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "雙");
                set("value",2500);
        }
        set("armor_prop/armor",8);
        set("armor_prop/dex",1);
        setup();
}


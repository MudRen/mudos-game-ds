#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"神聖戰甲"NOR, ({"holy armor", "armor"}) );
        set("long",@LONG
這是一件經過神聖洗禮的鎧甲，穿上它可得到神聖的力量。
LONG
);
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副" );
                set("armor_prop/armor", 25);
                set("armor_prop/str", 4);
                set("armor_prop/con", 2);
                set("armor_prop/shield", 40);
                set("material","silver");
                set("limit_str", 35);
             }
        setup();
}


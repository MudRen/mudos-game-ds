#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(HIY"超級大肉包"NOR,({"super dump","dump"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個很大很大很大很大很大的包子, 你不知道到吃多久才吃得完。\n");
                set("unit", "個");
                set("value",1);
                set("heal_hp",20);
		set("heal_mp",20);
		set("heal_ap",20);
                set("food_remaining",50);
        }
}

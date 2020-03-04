#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("鮪魚湯", ({ "wealfish soup","soup"}) );
        set_weight(190);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "一碗味道清新絕倫的魚湯。");
                set("unit", "碗");
                set("eat_msg","$N喝下一碗鮪魚湯。");
                set("eff_msg",HIG "你感到從腹中傳來一股溫暖的熱流，慢慢的擴散到全身。" NOR );
           }
                set("value", 150);       
                set("heal_mp",30);
                set("water_remaining", 2);
set("cure",([
         "head" : 5,
         "body" : 5,
         "right_arm" : 5,
         "left_arm" : 5,
         "right_leg" : 5,
         "left_leg" : 5,
         ]));
set("no_auc",1);
setup();
}







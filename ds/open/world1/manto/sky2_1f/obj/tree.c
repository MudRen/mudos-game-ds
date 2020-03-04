#include <ansi.h>

inherit ITEM;
void create()
{
    set_name(HIW"天地明桐"NOR,({"sky-ming tree","tree"}));
        set("unit", "顆");
        set("long",@LONG
散發著神聖白光的桐木，相傳當年明教及天地會的前輩們便是
在此樹下歃血為盟聯手抵禦外敵，那英雄輩出的時代，讓你不
由得心神嚮往，想伸手摸(touch)它瞻仰先人。
LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        
        if(arg!="sky-ming tree" && arg!="tree" )
        {
                notify_fail("你要摸什麼?\n");
                return 0;
        }

        message_vision(HIW"$N輕輕摸了$n一下。\n"NOR,me, this_object());
        write(this_object()->name()+""HIC"似乎閃動了一下，隨即又回復了原狀。\n"NOR);
        return 1;
}

inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIC"訊號發射器"NOR,({"massage item"}));
        set("unit","個");
        set("base_unit","個");
                set("value",5000);
set("long","這是一個模擬古代煙火的訊號發射器，你可以用來傳遞(show)消息。\n");
        setup();
}

void init()
{
        add_action("do_show","show");
}

int do_show(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return notify_fail("你要寫上啥字﹖\n");
        message_vision(CYN"\n$N拿起了煙火，指向天空點起星火。\n"NOR,me);
message_vision(HIR"\n碰！一聲，一顆星劃過星空。\n"NOR,me);
        tell_object(users(),
        HIC"\n\t遙遠的天際，突然有一道星光狠狠地劃過閃爍的星空..\n"NOR+
        HIY"\n\t石"NOR+YEL"並"HIR" ∼"HIM"."NOR+MAG". "HIW+BLK"的"NOR"一"HIW"聲"NOR"，"HIW+BLK"這"NOR"顆"HIW"星"NOR"如"HIW+BLK"花"NOR"開"HIW"般"NOR
"，"HIW+BLK"灑"NOR"落"HIW"了"NOR"繽"HIW+BLK"紛"NOR"火"HIW"花"NOR".. \n"NOR+
        HIB"\n\t整片的天空佈"HIW"滿了"NOR+RED"『 "HIY+arg+NOR+RED" 』"HIW"耀眼"HIB"的色彩字..\n\n"NOR);
        destruct(this_object());
    return 1;
}


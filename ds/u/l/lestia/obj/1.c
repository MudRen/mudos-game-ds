#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("東西", ({"test"}));
    set("unit", "個");
    set("long",@LONG
    用來玩的一個東西
LONG);

    set_weight(1);
    set("value",1);
  setup();
}

void init()
{
add_action("do_io","io");
    }
int do_io(string arg)
{
        object me = this_player();
         int i;
me->set("env/msg_clone",HIY"$N"HIY"突然蹲在旁邊的牆角下，"NOR""YEL"把手伸進褲襠裡，"HIY"將$n"HIY"拉了出來。\n"NOR);
me->set("env/msg_mout",HIC"$N"HIC"低頭閉眼，喃喃默念道：「"HIR"永恆的光呀"NOR""RED"∼請賜予信奉"HIR"你的子民移"NOR""RED"動的力量吧！」\n"NOR);        
me->set("env/msg_min",  HIM"一道耀眼的光"NOR""MAG"芒從天上直衝"HIM"而下，$N"HIM"慢慢的從光"NOR""MAG"束中走了出來。\n"NOR);
me->set("env/msg_dest",       HIG"$N"HIG"不削的往$n"HIG"吐了一口痰，結果$n"NOR""GRN"被$N"NOR""GRN"的痰給溶化了。\n"NOR);
       return 1;
}



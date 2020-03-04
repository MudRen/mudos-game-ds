#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(HIY"茶桌"NOR,({"table"}));
     set_weight(99999999); 
     set("long",HIW"悠閒聊天室的主人，用來招乎他的朋友用的，上面有泡到的茶，可以用(take cup)來拿取。\n"NOR);
     set("no_get",1);
     set("no_sac",1);
     set("no_sell",1);
     setup();
}
void init()
{  
     add_action("do_take","take");
}
int do_take(string arg)
{
    object me=this_player(),tcup;
    if(!arg||arg!="cup") return notify_fail("你要拿什麼(cup)?\n");
    message_vision(HIW"$N從茶桌上端了一杯茶••\n"NOR);  
    {
    tcup=new("/u/j/jangshow/tea-cup");
    tcup->move(environment(this_player()));
    me->set_temp("taked",1);
    }
    call_out("stop_taked",10,me);
    return 1;
}
void stop_taked()
{
    object me=this_player();
     tell_object(me,"Wait la.\n");
     me->delete_temp("taked");
     return;
}


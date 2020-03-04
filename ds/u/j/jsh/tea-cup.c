#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(HIY"茶杯"NOR,({"tea cup","cup"}));
     set_weight(999); 
     set("long",HIC"悠閒聊天室的主人，為他的好朋友準的的茶品，請用(taste tea)來品嘗。\n"NOR);
     set("no_sac",1);
     set("no_sell",1);
     setup();
}
void init()
{ 
     add_action("do_taste","taste");
}
int do_taste(string arg)
{ 
    object me=this_player();
    if(me->query_temp("tasted")==1) return notify_fail("你剛剛喝過了，等會兒吧 ^.^\n");
    if(!arg||arg!="tea") return notify_fail("你要喝什麼(tea)?\n"); 
    switch(random(4))
    {
    case 0:
    message_vision(HIW"$N拿起茶杯，『囌∼∼』的喝了一口，整個人都放鬆••真好∼^.^∼\n"NOR,me); 
    me->set_temp("tasted",1);  
    break;
    case 1:
    message_vision(HIW"$N拿起茶杯，細細的品嘗著香醇順口的茶品••嗯∼∼感覺真好∼\n"NOR,me); 
    me->set_temp("tasted",1);
    break; 
    case 2:
    message_vision(HIW"$N拿起茶杯，一邊聞著茶香，一邊慢慢品嘗這高山烏龍茶••\n"NOR,me);
    } 
    call_out("stop_tasted",10,me);
    return 1;
}
void stop_tasted()
{
     object me=this_player();
     tell_object(me,"請喝茶 ^.^\n");
     me->delete_temp("tasted");
     return;
}


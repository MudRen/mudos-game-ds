#include <ansi.h>
inherit ROOM;
void show(object me);
void create()
{
       set("short", HIG"小溪旁"NOR);
       set("long",@LONG
這裡涓涓的小溪旁..你用心的寧聽著小溪的流水聲..心情平靜了許多...
LONG
        );
       set("item_desc",([
 "小溪流":"一條淙淙的小溪流..給人一種安祥平和的感覺,你突然發現裡面好像有什麼生物在動..。\n",
 "小生物":"一個"HIR"紅紅"NOR"的生物..看起來很好吃的樣子，你或許\可找支釣竿將牠釣(angle)起來 。\n",
 "小路":"這條小路可以走(goin)回浪人營。\n",
 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{
 add_action("do_angle","angle");
 add_action("do_goin","goin");
}
int do_angle(string arg)
{
        object me,ccc;
        me = this_player();
        if( !arg ) return 0;
        if( arg!="小生物" )
      {
                notify_fail("你要釣什麼東西?\n");
                return 0;
      }
if( query_temp("anglelobser") )
{
    return 0;
}
if(!objectp(ccc=present("rod",me) ) )
return notify_fail(HIC"沒有釣竿要怎麼釣東西?。\n"NOR);
message_vision(HIG"$N拿起釣竿甩入了小溪裡。\n"NOR,me);
        me->start_busy(8);
        call_out("no",3,me);
        call_out("no2",5,me);
        call_out("delay",1800,this_object());
        return 1;
}
void no(object me)
{
     if(!me) return;
     message_vision(HIC"突然一陣振動..$N趕緊拉起釣竿。\n"NOR,me);
     return;
}
void no2(object me)
{
     object ll;
     ll=new(__DIR__"obj/lobser");
     message_vision(HIY"$N終於釣出了那隻小生物..嚇然一看竟然是一隻大大"HIR"紅紅"NOR"的龍蝦..。\n"NOR,me);
     ll->move(me); 
     set_temp("anglelobser",1);
     this_object()->delete("item_desc");
     set("item_desc",([
 "小溪流":"一條淙淙的小溪流..給人一種安祥平和的感覺。\n",
]));
}
void delay(object room)
{
  delete_temp("anglelobser");
  set("item_desc",([
 "小溪流":"一條淙淙的小溪流..給人一種安祥平和的感覺,你突然發現裡面好像有什麼生物在動..。\n",
]));
        return;
}

int do_goin(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="小路") return 0;
        message_vision("$N開開心心的往小路走了回去...。\n",me);
        me->move(__DIR__"map_2");
        tell_room(environment(me),me->query("name")+"從小路那走了過來。\n",({ me }) );
        return 1;
}


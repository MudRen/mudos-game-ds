#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
   set("short",HIC"北蠻村"NOR"－"HIG"小路"NOR);
   set("long",@LONG
來到這裡，似乎已經走到盡頭了。但是你卻沒有看到什麼猛
獸之類的怪物，只見你眼前有一個十分具大的石頭，但是這塊石
頭要移開似乎要花很大的力氣••
LONG);
   set("exits",([
       "south":__DIR__"town30",
       ]));
   set("objects", ([
       ])); 
   set("item_desc",([
       "大石" :NOR"一顆十分巨大的石塊，要移動(move)看起來很困難。\n"NOR]));     
   set("outdoors","land");
   set("no_clean_up", 0);
   setup();
}     

void init()
 {
   add_action("do_move","move");
 }

int do_move(string arg)
{
   string arg1;
   object me,room;
   me = this_player();
   room = this_object();

     if(!arg) 
        return notify_fail("你要移動什麼？\n");
     if((arg!="大石"))
        return notify_fail("這裡並沒有這種東西。\n");
     if(me->query("str") < 70 )
        return notify_fail(NOR"你的力氣不夠，無法移動石塊。\n"NOR); 
     if(me->is_busy() ) 
        return notify_fail("你正在忙，沒空啦。\n");
     if(arg == "大石" && room->query("open_ok") != 1) 
     {
        message_vision(HIG"$N把大石移開，卻發現地上出現一個大洞！裡面好像有路。\n"NOR,me);
        me->start_busy(3);
        add("exits/down",__DIR__"entrance");
        room->set("open_ok",1);
     }
     else
     { message_vision(NOR"大石已經被移開了...\n"NOR,me); }
 return 1;
}

void reset()
{
    set("exits", ([
        "south"  : __DIR__"town30",
         ]));
    this_object()->delete("open_ok");
    ::reset();
}


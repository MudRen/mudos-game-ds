#include <room.h>
inherit ROOM;

void create()
{
  set("short","鬼之森");
  set("long",@LONG
這裡是陰森詭異的森林，由於鬼怪的棲息使得陰氣凝重，長年濃
霧聚集不散，走在這邊感覺陰陰涼涼的，不時有奇怪的叫聲從森林中
傳來，高度的濕氣使得四周充滿一股腐臭的味道，樹下有一堆腐肉，
腐肉上長了一些蕈類。
LONG);
  set("exits",([ 
      "east":__DIR__"room50",
      "west":__DIR__"room48",
      "south":__DIR__"room44",
      "north":__DIR__"room54",
     ]));
  set("item_desc",([
      "腐肉" : "一堆不曉得是什麼動物的腐肉，散發強烈的屍臭味，腐肉上長了一棵肉芝。\n",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
     ]) );
  setup();
}            

void init()
{
  add_action("do_pick","pick");
}

int do_pick(string arg)
{
  object me=this_player(),fungus;
  fungus = new(__DIR__"npc/eq/carrion-fungus.c");
  if(query_temp("fungus1")) return notify_fail("這棵肉芝還沒長成呢。\n");
  if(arg !="肉芝" )
    return notify_fail("你要找什麼東西呀？\n");
  else
  {
    message_vision("$N捏住鼻子從腐肉上摘下一棵肉芝。\n",me);
    fungus->move(me);
  } 
  set_temp("fungus1",1);
  call_out("delay",600,this_object());
  return 1;
}

void delay(object room)
{
  delete_temp("fungus1");
}

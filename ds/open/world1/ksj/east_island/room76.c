#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short",HIM"櫻花林"NOR);
  set("long",@LONG
這裡是櫻花林中的林徑，四周都是大大小小的櫻花樹，嬌豔美麗
的櫻花隨著微風輕輕搖擺，映照出粉紅色的天空。
LONG);
  set("exits",([ 
      "north":__DIR__"room72",
      "southeast":__DIR__"room78",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  setup();
}           

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("tengu", this_object())) && !me->query("tengu") && !random(3))
  {
    message_vision("$n阻擋在$N的面前說道：哼哼，留下命來吧。\n",me , guard);
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}                               

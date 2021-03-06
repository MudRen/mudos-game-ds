#include <room.h>
inherit ROOM;

void create()
{
  set("short","大柵門");
  set("long",@LONG
這裡是一個木頭築成的柵門，柵門兩旁有拿著武器的村民在站崗
，左側的瞭望臺上也有人擔任警戒，彷彿在防備什麼似的。
LONG);
  set("exits",([ 
      "east":__DIR__"room15",
      "west":__DIR__"room25",
      "north":__DIR__"room36",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/villager-guard":3,
      __DIR__"npc/autarou":1,
      __DIR__"npc/eq/tower":1,
     ]));
  setup();
}           

int valid_leave(object me, string dir)
{
  object guard;
  if( me->query("village") )
  {
    if( dir == "north")
      return notify_fail("");
  }
  if(me->query("level")<26)
  {
    if( objectp(guard=present("villager guard", this_object())) && dir == "north" )
    {
      message_vision("$n阻擋在$N的面前說道：北方危險重重，留在村中比較安全。\n",me , guard);
        return notify_fail("");
    }
  }
  else if( objectp(guard=present("villager guard", this_object())) && dir == "north" )
  {
    message_vision("$n擔心的對$N說道：請萬事小心！！\n",me , guard);
    return ::valid_leave(me, dir);
  }
  return ::valid_leave(me, dir);
}

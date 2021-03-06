#include <room.h>
inherit ROOM;
int i=0;

void create()
{
  set("short","木橋邊");
  set("long",@LONG
站在這裡是河岸邊，旁邊是一座蠻大的木橋，往西可以看到一大
片的櫻花林，以河水湍急的程度看來，沒有橋是絕無法渡河的，一旁
的樹上長了一棵結實累累的野葡萄樹。
LONG);
  set("exits",([ 
      "east":__DIR__"room61",
      "west":__DIR__"room63",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("item_desc",([
      "野葡萄樹" : "一株結實累累的野葡萄樹，可以摘些充飢(pick)。\n",
     ]));
  set("objects",([
      __DIR__"npc/eq/wood-board":1,
     ]) );
  setup();
}            

void init()
{
  add_action("do_pick","pick");
}

int do_pick(string arg)
{
  object me=this_player(),grape;
  grape = new(__DIR__"npc/eq/agrestal-grape.c");
  if( query_temp("grape1") > 3 ) return notify_fail("野葡萄已經被摘完了，剩下都是還沒熟的。\n");
  if(arg !="野葡萄" )
    return notify_fail("你要摘什麼東西呀？\n");
  else
  {
    message_vision("$N小心地摘下一串野葡萄。\n",me);
    grape->move(me);
    set_temp("grape1",i++);
  } 
  call_out("delay",600,this_object());
  return 1;
}

void delay(object room)
{
  delete_temp("fungus1");
  i=0;
}

int valid_leave(object me, string dir)
{
  if( me->query("tengu") )
  {
    if( dir == "east")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}

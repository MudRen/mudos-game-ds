#include <room.h>
inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
這裡是山間一條崎嶇的山路，路上都是碎石子、泥巴和雜草，南
邊的山坳堆了一些落石跟碎冰。
LONG);
  set("exits",([ 
      "east":__DIR__"room97",
      "west":__DIR__"room99",
      "south":__DIR__"room100",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/berserk-huge-pig":1,
     ]) );
  setup();
}            

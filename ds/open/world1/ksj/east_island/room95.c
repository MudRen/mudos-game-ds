#include <room.h>
inherit ROOM;

void create()
{
  set("short","山坳");
  set("long",@LONG
這裡是一處蠻深的山坳，頭頂上光滑的山壁慢慢滴著冰冷的水滴
，落下後滲入地板中，發出滴答滴答的回音，一旁的角落有個用樹枝
乾草做成像是一個大巢的東西。
LONG);
  set("exits",([ 
      "east":__DIR__"room94",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/umaro":1,
     ]) );
  setup();
}            

#include <room.h>
inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
這裡是山間一條崎嶇的山路，路上都是碎石子、泥巴和雜草，兩
旁茂密的草叢和樹林裡可能隨時有什麼動物會跑出來，前方的雜草和
小樹朝兩邊分倒，像是被什麼東西壓過似的。
LONG);
  set("exits",([ 
      "west":__DIR__"room98",
      "southeast":__DIR__"room96",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/berserk-small-bear":2,
     ]) );
  setup();
}            

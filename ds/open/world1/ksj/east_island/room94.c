#include <room.h>
inherit ROOM;

void create()
{
  set("short","山路");
  set("long",@LONG
這裡是山間一條崎嶇的山路，路上都是碎石子、泥巴和雜草，兩
旁茂密的草叢和樹林裡可能隨時有什麼動物會跑出來，西邊是一處山
坳，黑黑暗暗地看不清楚裡面有什麼。
LONG);
  set("exits",([ 
       "west":__DIR__"room95",
       "north":__DIR__"room96",
       "south":__DIR__"room93",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

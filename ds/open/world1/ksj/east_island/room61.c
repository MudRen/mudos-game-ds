#include <room.h>
inherit ROOM;

void create()
{
  set("short","木橋上");
  set("long",@LONG
走到這裡是木橋的中間，透過橋上的破洞可以看到湍急的溪流，
及險峻的河床，橋面受水氣的浸蝕，濕濕滑滑地頗不好走。
LONG);
  set("exits",([ 
      "east":__DIR__"room60",
      "west":__DIR__"room62",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

#include <room.h>
inherit ROOM;

void create()
{
  set("short","林外小路");
  set("long",@LONG
這裡是鬼之森的外圍小路，雖然還是有許多雜草叢生，但總算沒
有鬼之森那種詭異恐怖的氣氛，往東北方可以看到一條山路，北邊則
是一座木橋。
LONG);
  set("exits",([ 
      "south":__DIR__"room52",
      "southwest":__DIR__"room51",
       "north":__DIR__"room60",
       "northeast":__DIR__"room59",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

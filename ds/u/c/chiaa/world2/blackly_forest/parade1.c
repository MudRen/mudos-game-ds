//u/c/chiaa/world2/blackly_forest/parade1.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "訓練區");
  set("long", @LONG
這裡是訓練新手忍者的地方,映入你眼簾的是一些人正進行著
相當嚴苛的訓練,空氣中瀰漫著煙塵與吆喝聲!!
LONG
        );


  set("exits", ([ /* sizeof() == 3 */
 
     "east"  : __DIR__"parade2",          //訓練區2
     "west"  : __DIR__"nivi_road1",       //忍村道路1
     "north" : __DIR__"hut",              //休息所
]));


 setup();
  replace_program(ROOM);
}

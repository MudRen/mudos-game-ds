//u/c/chiaa/world2/blackly_forest/hut.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "休息所");
  set("long", @LONG
這裡是駐守處與訓練區的休息場所!
給那些整天訓練的忍者和入口的駐軍休息的地方!!
LONG
        );


  set("exits", ([ /* sizeof() == 2 */
   
     "west"  : __DIR__"garrison2",       //駐守處2
     "south" : __DIR__"parade1",         //訓練區1
]));


 setup();
  replace_program(ROOM);
}

//u/c/chiaa/world2/blackly_forest/hourse2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "房子");
  set("long", @LONG
 一間普通的平房!!
 供人休息之用!!
LONG
        );


  set("exits", ([ /* sizeof() == 1 */
   
     "east"  : __DIR__"hourse1",     //房子1

]));

setup();
  replace_program(ROOM);
}

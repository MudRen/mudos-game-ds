//u/c/chiaa/world2/blackly_forest/hourse1.c

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


  set("exits", ([ /* sizeof() == 2 */
   
     "north"  : __DIR__"nivi_road4",     //忍村道路4
     "west"   : __DIR__"hourse2",        //房子2
]));

setup();
  replace_program(ROOM);
}

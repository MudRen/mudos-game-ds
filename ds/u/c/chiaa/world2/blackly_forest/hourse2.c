//u/c/chiaa/world2/blackly_forest/hourse2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�Фl");
  set("long", @LONG
 �@�����q������!!
 �ѤH�𮧤���!!
LONG
        );


  set("exits", ([ /* sizeof() == 1 */
   
     "east"  : __DIR__"hourse1",     //�Фl1

]));

setup();
  replace_program(ROOM);
}

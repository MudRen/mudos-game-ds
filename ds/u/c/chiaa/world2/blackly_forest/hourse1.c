//u/c/chiaa/world2/blackly_forest/hourse1.c

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


  set("exits", ([ /* sizeof() == 2 */
   
     "north"  : __DIR__"nivi_road4",     //�ԧ��D��4
     "west"   : __DIR__"hourse2",        //�Фl2
]));

setup();
  replace_program(ROOM);
}

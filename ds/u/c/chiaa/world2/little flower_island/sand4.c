//u/c/chiaa/world2/little flower_island/sand4.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", YEL"�F�y"NOR);
        set("long",@LONG
�o�̬O�p��骺�F�y,�������ɩ祴�ۨF�y,
�F�y�W�����ۦU�رq���W�ƨӪ�����P�U���U��
������,�F�y�W�������@�Ǥp�ͪ������~~

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       
       "south"      : __DIR__"rock1",    //���۰�1
       "southwest"  : __DIR__"rock2",    //���۰�2
  ]));
       
            setup();
replace_program(ROOM);
}

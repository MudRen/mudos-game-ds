//u/c/chiaa/world2/little flower_island/sand6.c

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
        set("exits", ([ /* sizeof() == 3 */
       
       "west"       : __DIR__"sand7",      //�F�y7
       "south"      : __DIR__"forest5",    //�˪L5
       "northwest"  : __DIR__"forest1",    //�˪L1
  
  ]));
       
            setup();
replace_program(ROOM);
}

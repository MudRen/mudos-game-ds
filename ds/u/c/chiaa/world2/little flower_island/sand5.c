//u/c/chiaa/world2/little flower_island/sand5.c

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
        set("exits", ([ /* sizeof() == 1 */
       
         "west"    : __DIR__"forest1",    //�˪L1
  
  ]));
       
            setup();
replace_program(ROOM);
}

//u/c/chiaa/world2/little flower_island/sand7.c

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
       
       "west"    : __DIR__"forest4",    //�˪L4
       "east"    : __DIR__"sand6",      //�F�y6
    
   ]));
       
            setup();
replace_program(ROOM);
}

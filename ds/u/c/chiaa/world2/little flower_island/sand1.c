//u/c/chiaa/world2/little flower_island/sand1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", YEL"�F�y"NOR);
        set("long",@LONG
�o�̬O�p��骺�F�y,�������ɩ祴�ۨF�y,
�F�y�W�����ۦU�رq���W�ƨӪ�����P�U���U�˪�
����,�n����G���@�y�˪L,�z�X�@�ѳ��˪��Pı!!
�F�y�W�������@�Ǥp�ͪ������~~

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "northeast"  : __DIR__"ocean",     //����
       "west"       : __DIR__"sand2",     //�F�y2
       "south"      : __DIR__"forest1",    //�˪L1
  ]));
       
            setup();
replace_program(ROOM);
}

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"��ΰ}��"NOR);

 set("long",@LONG
�Aı�o�|�P�Q������������L���, �J���o�{�o�O�A���߲z�@��, 
�i����A�w�g�P��@�w�{�ת��߷W�N�äF....�A�ߤ����T�Ʊ�P
�֨��X�o�@�ӥO�H�߷W�F�a��....
LONG
    );
 set("exits",([ "west":"/u/f/faceoff/wood1.c",
                "east":"/u/f/faceoff/wood2.c",
                "north":"/u/f/faceoff/wood2.c",
                "south":"/u/f/faceoff/wood4.c",
    ]));

 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
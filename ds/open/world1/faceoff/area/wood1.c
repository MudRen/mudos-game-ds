#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"��ΰ}��"NOR);

 set("long",@LONG
�Aı�o�|�P�Q������������L���, �J���o�{�o�O�A���߲z�@��,
�i����A�w�g�P��@�w�{�ת��߷W�N�äF....�A�ߤ����T�Ʊ�P�֨�
�X�o�@�ӥO�H�߷W�F�a��....
LONG
    );
 set("exits",([ "west":__DIR__"wood2.c",
                "east":__DIR__"wood2.c",
                "north":__DIR__"wood2.c",
                "south":__DIR__"wood2.c",
    ]));

 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

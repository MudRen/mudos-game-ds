#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"��ΰ}��"NOR);

 set("long",@LONG
 
  �Aı�o�|�P�Q������������L���, �J���o�{�o�O�A���߲z�@��,
�i����A�w�g�P��@�w�{�ת��߷W�N�äF....�A�ߤ����T�Ʊ�P�֨�
�X�o�@�ӥO�H�߷W�F�a��....�o�̪�[1;33m�a�W���|�Ӹ}�L[0m...

����                                                 ����
���y��                                             �Ģj��
���y :�j                                         �y: �j��
���y :�j                                         �y: �j��
���y��                                             �âj��
����                                                 ����

LONG
    );
 set("exits",([ "west":__DIR__"wood3.c",
                "east":__DIR__"wood1.c",
                "north":__DIR__"wood2.c",
                "south":__DIR__"wood5.c",
    ]));

 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

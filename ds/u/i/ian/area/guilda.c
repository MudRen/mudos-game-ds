#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�۴Y"NOR);

 set("long",@LONG
�o�������F�ѱ��в�, �H�H����~��, �۴Y�����������q, �۴Y�R��
�۱в����n���n, �A�[�W�Y���Ӧ^�������p�N, ���_�o�X�U��, �_�䪺�j
�۫ǶǨӾ����ë�i�n, �n�䪺�۪����򳬵�, �٬O�z�X�F�@�}�@�}����
��, ��ӥ۴Y�ë�����, ���M�A�w�gݳ��զ�, �������M�L���p�i�A����
�U��, �������I�Z�A�����g.
LONG
    );
 set("exits",([ "east":__DIR__"guild1",
                "west":__DIR__"guildb",
                "north":__DIR__"guilda_1",
                "south":__DIR__"guilda_2",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}


#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�C�۴Y"NOR);

 set("long",@LONG
�V�O���۴Y�����h, �в�, ����V��, ������M�@��A�˪��ѱ��в�
�o�V�h, �V�K��, ���]�V�Y��, �ݨӬO�V�a��ѱ��Ъ����n�a��F, ��
�Ǫ��O�����p�A���n�_�ߤ@��, �U�N���V�ӶV����.
LONG
    );
 set("exits",([ "east":__DIR__"center2",
                "west":__DIR__"center4",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}


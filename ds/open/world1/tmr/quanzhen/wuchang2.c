// wuchang2.c �Z��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Z��");
        set("long", @LONG
�o�̬O���u�Ъ��t�Z���A�a�U���C�j���ӾQ���������A�o
�����D�Q�ֽ�X�F�X�Q�Ӥj�j�p�p���W�|�C�ݪ��X�ӡA�o�̦��~
�֤몺���̤l�׷Ҵx�k�B�k�A�Ѫ���[�A�a�U�N��X�F�W�|�C�Z
�������ߵ۴X�ӽm�\�Ϊ���H�C
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "north" : __DIR__"wuchang1",
                "east" : __DIR__"xiuxishi",
                "southeast" : __DIR__"shantang",
        ]));

        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 4,
        ]));

	set("coor/x", -2750);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
// wuchang1.c �Z��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Z��");
        set("long", @LONG
�o�̬O���u�Ъ��t�Z���A�a�U���C�j���ӾQ���������A�o
�����D�Q�ֽ�X�F�X�Q�Ӥj�j�p�p���W�|�C�ݪ��X�ӡA�o�̦��~
�֤몺���̤l�׷Ҵx�k�B�k�A�Ѫ���[�A�a�U�N��X�F�W�|�C
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "south" : __DIR__"wuchang2",
                "north" : __DIR__"houtang2",
                "southeast" : __DIR__"xiuxishi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2750);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
// houtang2.c ���G�i
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���G�i");
        set("long", @LONG
�o�̬O���u�Ч̤l���`��Q�Z�\���a��A�o�Ӱ󤣤j�A�ѩ�g�`
�n�b�o�̺t�Z�A���ʳs��Ȥ]�����a������h�F�A�o���˥X�F�@�j��
�Ŧa�ӡC
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtang3",
                "west" : __DIR__"houtang1",
                "south" : __DIR__"wuchang1",
                "north" : __DIR__"liangong",
        ]));

	set("coor/x", -2750);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
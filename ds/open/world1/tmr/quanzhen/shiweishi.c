// shiweishi.c �Ƭ���
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ƭ���");
        set("long", @LONG
�o�̬O���u�C�l������౪��~�ǡC�ж��ܤp�A�u�\��F�@�i�ɡB
�@�i�Ѯ�M�@��Ȥl�C�Ѯ�W��ۤ@�����Ѥl���A�u�ݤF�@�b�A�ɤW
�Q�ȧ��|�o�������C
LONG
        );
        set("exits", ([
                "south" : __DIR__"cetang",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/ma" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
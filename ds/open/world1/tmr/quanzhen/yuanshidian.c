// yuanshidian.c ���l��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���l��");
        set("long", @LONG
�o�̬O�ѩ^���l�ѴL���j���C��������·¶�A��������ۤ��l��
�L�������A�����ٶ�۴X��D�ͦp�ӤA�B�ѯd�]�B�����l�B�s�M�l��
�������A���E�b�@�B�ν��Χ��A�δѩί��C
LONG
        );
        set("exits", ([
                "south" : __DIR__"laojundian",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/qi" : 1,
        ] ));

	set("coor/x", -2770);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
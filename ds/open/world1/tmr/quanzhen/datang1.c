// datang1.c �j��@�i
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�j��@�i");
        set("long", @LONG
�o�̬O�j��A�O���u�б��ݫȤH���a��C��ܤj�A�X�Q�i��Ȥ@
�r�ƶ}�]���@��������C�a�U�Q�۾�����C�j�A�X�W�D�������e����
�a�ݯ��e���۩I�ȤH�C
LONG
        );
        set("exits", ([
                "east" : __DIR__"datang2",
                "west" : __DIR__"damen",
                "north" : __DIR__"huizhentang",
                "south" : __DIR__"xianzhentang",
        ]));
        set("objects",([
                __DIR__"npc/daotong" : 1,
                CLASS_D("quanzhen")+"/first" : 1,
        ]));
        set("valid_startroom", 1);
	set("coor/x", -2800);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        "clone/board/quanzhen_b"->foo();
}
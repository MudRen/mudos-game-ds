// rongwutang.c �e����
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�e����");
        set("long", @LONG
�o�̬O���u�C�l���G�ӳB�ݪ��~�ǡA�o���ж����B���M���q����
�~�S����ϧO�A�u�O�@�Ф��V�A��W�ױ��ۤ@���_�C�C
LONG
        );
        set("exits", ([
                "north" : __DIR__"xianzhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/tan" : 1,
        ]));
	set("coor/x", -2800);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
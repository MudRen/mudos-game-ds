// cetang.c ����
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬O�j����䪺�@�Ӱ��U�A�]�O���ݭ��n�ȤH���a��C�U��
�j�A�u�\��ۤ@�i��l�M�X��Ȥl�C��W�\��ۤ@�֫C�Q�s�۪���
���A����W���ۤ@�Ǧr�e�C
LONG
        );
        set("exits", ([
                "east" : __DIR__"guozhendian",
                "west" : __DIR__"huizhentang",
                "north" : __DIR__"shiweishi",
                "south" : __DIR__"datang2",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/li" : 1,
        ]));

	set("coor/x", -2790);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
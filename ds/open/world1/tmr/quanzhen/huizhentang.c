// huizhentang.c �|�u��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�|�u��");
        set("long", @LONG
�o�̬O�j����䪺�@�Ӱ��U�A�]�O���ݭ��n�ȤH���a��C�U��
�j�A�u�\��ۤ@�i��l�M�X��Ȥl�C��W�\��ۤ@�֫C�Q�s�۪���
���A����W���ۤ@�Ǧr�e�C
LONG
        );
        set("exits", ([
                "east" : __DIR__"cetang",
                "north" : __DIR__"wanwutang",
                "south" : __DIR__"datang1",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/cui" : 1,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2800);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
// piandian.c ����
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬O�j����䪺�@�Ӱ��U�A�]�O���ݭ��n�ȤH���a��C�U��
�j�A�u�\��ۤ@�i��l�M�X��Ȥl�C��W�\��ۤ@�֫C�s��������
���A����W���ۤ@�Ǧr�e�C
LONG
        );
        set("exits", ([
                "east" : __DIR__"nairongdian",
                "west" : __DIR__"xianzhentang",
                "north" : __DIR__"datang2",
                "south" : __DIR__"guangning",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/shen" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2790);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
// nairongdian.c �D�e��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�D�e��");
        set("long", @LONG
�o�̬O�j����䪺�@�Ӱ����A�]�O���ݭ��n�ȤH���a��C����
�j�A�u�\��ۤ@�i��l�M�X��Ȥl�C��W�\��ۤ@�֫C�s��������
���A����W���ۤ@�Ǧr�e�C
LONG
        );
        set("exits", ([
                "south" : __DIR__"qingjing",
                "west" : __DIR__"piandian",
                "north" : __DIR__"datang3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/cheng" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
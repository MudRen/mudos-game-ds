// guangning.c �s��~
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�s��~");
        set("long", @LONG
�o�̬O���u�C�l�����q�j�q���׫ǡA�׫ǫܤp�A���F�@�i�p�ɡA
�@�i�p���L�ӥ~�S������O���\�]�C���L�����z���A�J�Ӥ@�ݡA���
�X���O�ξ�����ɵZ�i�����C���L�W�\��۴X�����ѽҳN���ѡA�٦�
�@�ǤR���Ϊ������C
LONG
        );
        set("exits", ([
                "north" : __DIR__"piandian",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/hao" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
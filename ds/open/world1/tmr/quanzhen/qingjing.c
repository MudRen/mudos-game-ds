// qingjing.c �M�b�~
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�M�b�~");
        set("long", @LONG
�o�̬O���u�C�l�����A�]�O�ߤ@���k�̤l�]���G���~�ǡC�o�ж�
�����L�b�A�M�o�X��v�S���׫Ǥj���ۦP�C�ɤW���|�ۤ@��D�T�A�T
�W¸�ۤ@�Ӿu�\�Y�C�o�u�\�Y�i���O�H�K¸���~�H���A�O��~������
���]���G���{�ɡA�e�F�@�ƾu�\�Ϯ׵��o�A�N��O���H�ͭW�u�A�o�D
���w�C�]���G�P���v���A�N�N�o�Ӿu�\�Ϯ�¸�b�ۤv���D�T�W�C
LONG
        );
        set("exits", ([
                "north" : __DIR__"nairongdian",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/sun" : 1,
        ]));

	set("coor/x", -2780);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
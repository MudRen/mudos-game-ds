// houtang1.c ���@�i
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���@�i");
        set("long", @LONG
�o�̬O��󪺤@�i�A�O���`���u�Ч̤l�𮧪��a��C�ѩ���u��
�{�b�s���̤l�A���\�񪺮�Ȥ]���_�W�[�A��o�o�Ӱ�w�g�ܾ���
�F�C
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtang2",
                "west" : __DIR__"laojundian",
        ]));

	set("coor/x", -2760);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
// tongtiandian.c �q�ѷ�
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�q�ѷ�");
        set("long", @LONG
�o�̬O�ѩ^�T�M����--�q�ѱХD���j���A���������Ϥ��Ʃ����C
�b�q�ѱХD����������A��۴X��I�йD�͹����եP�B�k���P�B��
���\���칳�C
LONG
        );
        set("exits", ([
                "north" : __DIR__"laojundian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2770);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
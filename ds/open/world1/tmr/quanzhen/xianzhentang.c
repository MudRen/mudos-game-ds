// xianzhentang.c ��u��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��u��");
        set("long", @LONG
�o�̬O�j����䪺�@�Ӱ��U�A�]�O���ݭ��n�ȤH���a��C�U���j�A
�u�\��ۤ@�i��l�M�X��Ȥl�C��W�\��ۤ@�ְ��s�y�����ִ��A��
���W���ۤ@�Ǧr�e�C�譱���@���ľ��ǡA�O�t�Ī��a��C
LONG
        );

        set("exits", ([
                "east" : __DIR__"piandian",
                "west" : __DIR__"yaojishi",
                "north" : __DIR__"datang1",
                "south" : __DIR__"rongwutang",
        ]));
        set("no_clean_up", 0);
        set("objects",([
                CLASS_D("quanzhen")+"/zhang" : 1,
        ]));

	set("coor/x", -2800);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
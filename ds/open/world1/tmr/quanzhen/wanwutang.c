// wanwutang.c �U����
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�U����");
        set("long", @LONG
�o�̬O���u�C�l�������B�@���~�ҡC�ж����j�A���B��������
��A��W���ۤ@���@�^�M�@�Ǧr�e�A�p�X�W�\��۫ůȩM�����T�@�A
�����D�D�H�O�n�m�r�٬Oø�e�C
LONG
        );
        set("exits", ([
                "south" : __DIR__"huizhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/wangchuyi" : 1,
        ]));

	set("coor/x", -2800);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
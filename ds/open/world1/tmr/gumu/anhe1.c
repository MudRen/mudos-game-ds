// Room: /d/gumu/anhe1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"�t�e"NOR);
	set("long", @LONG
��ӳo���O�@���a�U�t�e�A���B���n�w�O�F�F�A�n�շ����b�H�C�A
�}�U�@�B��šA�K�����y���R�|��C����y�����Ӧۦ�B�A�󤣪��q��
���C
LONG	);

	set("exits", ([
		"northup"  : __DIR__"shishi6",
		"eastdown" : __DIR__"qianliu1",
	]));
        set("objects", ([
                __DIR__"npc/yi-zhi-ping" : 1,
        ]));

	set("no_clean_up", 0);
	setup();
    replace_program(ROOM);
}

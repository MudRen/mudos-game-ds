// Room: /d/gumu/qianliu1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"��y"NOR);
	set("long", @LONG
�A�S�b�����A�uı���լƫ�A�R�o�A�L�k�ߨ��C�A��e���`�A�u�o�̮�N
�����A��u�O�i�h�����C
LONG	);

	set("exits", ([
		"east"   : __DIR__"qianliu2",
		"westup" : __DIR__"anhe1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

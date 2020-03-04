// Room: /u/m/mulder/area/naboo/jungle/jungle17.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�˪L"NOR);
	set("long", @LONG
�o�̪������i��ѪŤ��A�𸭿@�K�A�B�\�F�j�����������C�O��o
�̳����˴ˡC�A�J�Ӥ@�ݡA�oı�a�W�G���j�p���P���}�L�C�A���_�Mı�o
�o�̦s�b�@�ǥͪ��D�D�D�D�D
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jungle10",
  "south" : __DIR__"jungle14",
  "north" : __DIR__"jungle19",
  "east" : __DIR__"jungle13",
]));
		 set("objects",([
  __DIR__"npc/nuna":1,
__DIR__"npc/pekopeko":1,
 ]));

	set("world", "undefine");
	set("outdoors","forest");
	set("no_map",1);
	set("no_recall",1);
	set("no_clean_up", 0);
	



	setup();
	replace_program(ROOM);
}

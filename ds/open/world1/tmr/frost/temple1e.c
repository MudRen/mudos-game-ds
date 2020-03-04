// Room: /open/world1/tmr/frost/temple1e.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�q�D");
	set("long", @LONG
�A�����b�D�[�����q�D�A�[�������ҲM�զӦw�ԡA�L�����D�H�]�O�@
�ƻP�@�L�����w�ֻ��C�Ů��j���ۤ@���ȭ����A�H�H�M���ä����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"temple1e2",
  "west" : __DIR__"temple1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

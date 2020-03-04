// Room: /open/world1/tmr/frost/temple1e2.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�q�D");
	set("long", @LONG
�A�����b�D�[�����q�D�A�[�������ҲM�զӦw�ԡA�L�����D�H�]�O�@
�ƻP�@�L�����w�ֻ��C�Ů��j���ۤ@���ȭ����A�H�H�M���ä����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"court1",
  "east" : __DIR__"temple2",
  "west" : __DIR__"temple1e",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

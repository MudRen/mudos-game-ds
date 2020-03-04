// Room: /open/world1/tmr/frost/temple1.c

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
  "south" : __DIR__"temple3",
  "west" : __DIR__"temple",
  "east" : __DIR__"temple1e",
]));
	set("current_light", 2);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

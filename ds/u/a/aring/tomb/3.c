// Room: /u/a/aring/tomb/3.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�Х۪O�D");
	set("long", @LONG
�o�̬O�j�Ӷ餤���@���۪O�D�A���W���s�P�������۪O�A���_��
�������Z�A�۪O�P�۪O�������F����������A����o�|���|���D
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"2.c",
  "east" : __DIR__"4.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

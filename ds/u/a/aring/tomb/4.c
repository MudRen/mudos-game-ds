// Room: /u/a/aring/tomb/4.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�Х۪O�D");
	set("long", @LONG
�o�̬O�j�Ӷ餤���@���۪O�D�A���W���s�P�������۪O�A���_��
�������Z�A���F�䨫�O�j�Ӷ骺�F���j���C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"3.c",
  "east" : __DIR__"5.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

// Room: /u/a/aring/tomb/2.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�Х۪O�D");
	set("long", @LONG
����o�̬O�j�Ӷ餤���@���۪O�D�A���W���s�P�������۪O�A���_��
�������Z�A�i�H�Q���H�e�o�̬O���[���R�G�m������Ӷ�C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3.c",
  "west" : __DIR__"1.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

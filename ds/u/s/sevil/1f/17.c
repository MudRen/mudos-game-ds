// Room: /u/s/sevil/1f/17.c

inherit ROOM;

void create()
{
	set("short", "�Ƨ��~��");
	set("long", @LONG
�o�̬O�@���Ƨ��~���A�\���F�U���U�˪��Ƨ��~�A���̥��������H��
�b�O�i�A�]�\�A���Ӱݰݩ����A������A�X�A���Ƨ��~�C

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"12.c",
  "west" : __DIR__"18.c",
  "north" : __DIR__"22.c",
  "east" : __DIR__"16.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

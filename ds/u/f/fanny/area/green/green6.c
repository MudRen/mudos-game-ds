// Room: /u/f/fanny/area/green/green6.c

inherit ROOM;

void create()
{
	set("short", "���k���");
	set("long", @LONG
�o�̪�����o�S���S�K�A�ܤְ��L�`�H����Y�H�W�A��ʤW����
�x���A�����ٷ|�Q�󵹲̭ˡA���F�C�C���}��e�i���~�A�]�S��L��
�n����k�F�C
LONG
	);
	set("world", "undefine");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"green9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/f/fanny/area/green/green2.c

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
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"green1",
  "north" : __DIR__"green1",
  "west" : __DIR__"green1",
  "east" : __DIR__"green3",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

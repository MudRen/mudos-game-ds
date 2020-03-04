// Room: /u/s/superbug/train/6.c

inherit ROOM;

void create()
{
	set("short", "�k�Z��");
	set("long", @LONG
�o�̬O�@���k�Z�ҡA�@��i�o�̧A�N�D��@�ѯ���A�q���a�U���ݨ�
�A�w���@�}�l�S�H�ӲM���F�A��W�������]�H���b�a�W�A�A�o�p���l�l��
�H�K���A�A�u�Q�������}�o�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"4.c",
]));
        set("world", "future");
        set("light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

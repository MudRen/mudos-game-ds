// Room: /u/l/lestia/area/sn12.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG

�A���i�@�����t���˪L���A�o���p�|���F�A���~�S����L���H�ΰʪ��A
�X�ʰ��j�����W�����F��Ž�A�q��K�W���b�A�����e�A�A�`�`���l
�F�@�f��A�[��}�B���e���h�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn11",
  "south" : __DIR__"sn13",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

// Room: /u/l/lestia/area/sn6.c

inherit ROOM;

void create()
{
 set("short", "�_��j�˪L");
	set("long", @LONG
�A���i�@�����t���˪L���A�o���p�|���F�A���~�S����L���H�ΰʪ��A
�X�ʰ��j�����W�����F��Ž�A�q��K�W���b�A�����e�A�A�`�`���l
�F�@�f��A�[��}�B���e���h�C
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("objects", ([ 
	__DIR__"npc/troll":2,
	__DIR__"npc/troll2":1,
	__DIR__"npc/troll3":1,
	]));


	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn5w",
  "south" : __DIR__"sn7w",
]));

	setup();
	replace_program(ROOM);
}

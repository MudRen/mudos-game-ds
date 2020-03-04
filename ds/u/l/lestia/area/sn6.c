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
__DIR__"npc/bear":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"sn5",
  "down" : __DIR__"sn7",
]));

	setup();
	replace_program(ROOM);
}

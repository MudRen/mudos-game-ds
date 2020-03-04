// Room: /u/l/lestia/area/map_7_2.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�j�����U");
	set("long", @LONG

�o�̬O�F�۱Ъ��j�����U�A�o�̬O���N���ѶǱªZ�\�M�������n�H����
�a��A�b�S�O���ɭԥ��`���Ю{�άO�ȫȳ��O�Q�T��i�J���A�o���\�ۤ@��
���סA���פ��W���^�F���N�F�۱Ъ��Ѫ��P��A��ǳq���۫ݶQ���~���[
�СC

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_7_3",
  "north" : __DIR__"map_6_2",
  "south" : __DIR__"map_8_2",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

// Room: /u/f/fanny/area/forest/forest6.c

inherit ROOM;

void create()
{
	set("short", "�Q��L");
	set("long", @LONG
��F�o�A���ѩǤO�q�ΥO�H���H�ӷX���±�����w�����p�ɡA��
��L�̤]�i�H�ݨ쨺�ǳV�������p�ʪ��A�ݨӤw�g���X�F���ӥO�H��
�ͤ��֪��d��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"forest5",
  "east" : __DIR__"forest7",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

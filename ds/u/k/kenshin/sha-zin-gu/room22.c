// Room: /u/k/kenshin/sha-zin-gu/room22.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�p���x��[0m");
	set("long", @LONG
�Ө�F�x���A�ݨ�\�h�H�ѫ��p���ǯ��A�u�O���H�q�ؤT���A�٦�
�x�����\�]�]�O���M���ǡA���ͪ��p���ͮ�s�M�C
LONG
	);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room23",
  "south" : __DIR__"room21",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

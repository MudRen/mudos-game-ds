// Room: /u/k/kenshin/sha-zin-gu/room23.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�j���_��[0m");
	set("long", @LONG
�o�N�O�p���x�������B�߽Ҫ����Ƴ��Ңw�j���_���F�A��F�o��
�춯�����򹳡A���T���H�]�o���ӥL��T�U�C
LONG
	);
	set("light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room22",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

// Room: /u/k/king/area/47.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m������");
	set("long", @LONG
�q���ӳ����j�p�D���A���Q�h�h�K�L�ʰ_�A��������A�ӳ��W�ƨ��
���P�~���_���F���Y
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"48",
  "south" : __DIR__"46",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

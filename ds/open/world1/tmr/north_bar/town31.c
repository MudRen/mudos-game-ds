// Room: /open/world1/tmr/north_bar/town31.c

inherit ROOM;

void create()
{
	set("short", "�_�Z��-�۾��}�f");
	set("long", @LONG
�Ө�o�̡A���G�w�g������Y�F�C���e���G�O�@�B�}�ޡA
���ӴN�O�_�Z���������ߪ��d�~�}�ޡA�ǻD�̭����Y�H����
���A�C�~�`���X�ӭ˷����~���i�h�}�̡A�N�S���A�X�ӹL�F�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town30",
  "enter" : __DIR__"entrance",
]));
	set("no_clean_up", 0);
	set("current_light", 3);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

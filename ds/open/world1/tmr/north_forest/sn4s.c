// Room: /u/l/lestia/area/sn4.c

inherit ROOM;

void create()
{
 set("short", "�_��j�˪L-�a���}�ޤJ�f");
	set("long", @LONG
�A���b�@��������𪺪L�l�̡A���Y�ݨ����O�@�K���K���A�C�Y�ݨ쪺
�O�a�֤@��p�p�������C�A�`�N��e�����@�Ӧa���}�ޡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sn4",
  "enter" : __DIR__"cave1",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

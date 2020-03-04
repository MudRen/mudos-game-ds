// Room: /open/world1/tmr/unquiet_manor/grave5.c

inherit ROOM;

void create()
{
	set("short", "�L�礧�X");
	set("long", @LONG
�A���b���L����骺�a�U�ӹD���A�ӥޫͮ�X�ʦ~�����y�ʡA�A
�u�l�J�X�f�N�wı�o�Y�����ȡA�u�Q�n�������}�o�Ӧa��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"g1",
  "up" : __DIR__"map_4_8",
]));
	set("no_clean_up", 0);
	set("current_light", 3);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/grove-ghost" : 2,
]));

	setup();
	replace_program(ROOM);
}

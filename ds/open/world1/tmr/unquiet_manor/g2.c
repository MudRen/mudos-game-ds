// Room: /open/world1/tmr/unquiet_manor/g1.c

inherit ROOM;

void create()
{
	set("short", "�L�礧�X-�ӹD");
	set("long", @LONG
�A���b���L����骺�a�U�ӹD���A�ӥޫͮ�X�ʦ~�����y�ʡA�A
�u�l�J�X�f�N�wı�o�Y�����ȡA�u�Q�n�������}�o�Ӧa��C�ӹD���S
�S���@�����u�A�R�q����^�����M�a�ӵ��檺���߷P�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"g3",
  "south" : __DIR__"g1",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}

// Room: /open/world1/tmr/north_bar/town35.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Х���");
	set("long", @LONG
�o���Τl�Q��²�����¡A�s�U�B�ɳ��|�|���A�θ̰}�]�]��
�����áA�ݼˤl�D�H���G�S���ž�z�A�άO�ڥ��o�N�O���ūΡC
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"town34",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

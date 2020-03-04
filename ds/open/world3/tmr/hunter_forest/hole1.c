// Room: /open/world3/tmr/hunter_forest/hole1.c

inherit ROOM;

void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A���Y�b�o�Ӥs�}���}�f�A�ǵ۷L�z�����u�A�j�j��ݨ�e����F�T
���q�D�C
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"hole4",
  "north" : __DIR__"hole3",
  "out" : __DIR__"forest6",
  "northwest" : __DIR__"hole2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

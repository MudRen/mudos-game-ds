// Room: /open/world1/tmr/north_bar/town18.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Х���");
	set("long", @LONG
�o�̽�۳\�h���~�A���񦳳\�h�H�b�ƶ��R�F��A�o�̪��F 
�賣�O�������G�A�B���W��S��A�����~�a�H�h���߷R�C
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"shop",
  "west" : __DIR__"town19",
  "east" : __DIR__"town12",
  "southwest" : __DIR__"bank",
]));
	set("outdors", "land");
	set("current_light", 2);
	set("outdoors", "land");
	set("light", 1);

	setup();
	replace_program(ROOM);
}

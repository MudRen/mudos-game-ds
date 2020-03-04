// Room: /u/s/suez/fall.c

inherit ROOM;

void create()
{
	set("short", "�����r��");
	set("long", @LONG

�r������M�D�������O�Aı�o�ܵΪA�A�b�A���᪺�O
�@����N�s�M���˫ΡAť����L�r���N�|�i�J��᷽
�@�몺�@�ɡC
LONG
	);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 4 */
  "area1" : __DIR__"area/hotel_hall",
  "area2" : __DIR__"grave/kiosk",
  "area3" : __DIR__"port/port_24",
  "in" : __DIR__"workroom",
]));
	set("no_clean_up", 0);
	set("world", "world1");

	setup();
	replace_program(ROOM);
}

// Room: /open/world1/dragoncity/southgate1.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�o�̬O�Y�s�����n�������������A�u�������W��O�T�Ӥj�r�C

[1;36m                      ������
[0m
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "southup" : __DIR__"walls1",
  "south" : __DIR__"southgate2",
  "north" : __DIR__"south_din",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

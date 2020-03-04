// Room: /open/world1/dragoncity/eastgate1.c

inherit ROOM;

void create()
{
	set("short", "�C�s����");
	set("long", @LONG
�o�̬O�Y�s�����n�������������A�u�������W��O�T�Ӥj�r�C

[1;36m                      �C�s��
[0m
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 4,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"eastgate2",
  "eastup" : __DIR__"walle1",
  "west" : __DIR__"east_din",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

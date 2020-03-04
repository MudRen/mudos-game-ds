// Room: /open/world1/tmr/hasake/caoyuan9.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sheep" : 2,
  __DIR__"npc/hasake" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"caoyuan2",
  "south" : __DIR__"caoyuana",
  "east" : __DIR__"caoyuan7",
]));

	setup();
	replace_program(ROOM);
}

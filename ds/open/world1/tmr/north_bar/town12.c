// Room: /open/world1/tmr/north_bar/town12.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�o�̪�����O�����A���\�h�u�c���s���n�H�γټM�n�A���� 
�̦��˦��椣�֤g���A����]�����ľQ�C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/villager" : 2,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town10",
  "east" : __DIR__"town6",
  "north" : __DIR__"town14",
  "west" : __DIR__"town18",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

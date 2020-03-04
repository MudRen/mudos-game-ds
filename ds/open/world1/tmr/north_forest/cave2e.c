// Room: /open/world1/tmr/north_forest/cave2e.c

inherit ROOM;

void create()
{
	set("short", "�a���}��");
	set("long", @LONG
�A���B�b�@�Ӧa���}�ޤ��A�ѩ󶧥��L�k�Ӯg�i�ӡA�ҥH�|�g�ɬO�º�
�����@���A�A�u��j�j���۩������e�i�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 5);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/troll5" : 2,
  __DIR__"npc/troll4" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cave2en",
  "west" : __DIR__"cave2",
]));

	setup();
	replace_program(ROOM);
}

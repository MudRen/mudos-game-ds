// Room: /u/c/cominging/past/death/underground8.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"underground5",
  "west" : __DIR__"underground7",
  "east" : __DIR__"underground9",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}

// Room: /u/c/cominging/past/death/hotel9.c

inherit ROOM;

void create()
{
	set("short", "�ũж�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"hotel8",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}

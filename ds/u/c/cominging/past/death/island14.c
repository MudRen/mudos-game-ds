// Room: /u/c/cominging/past/death/island14.c

inherit ROOM;

void create()
{
	set("short", "�p�q�W");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("current_light", 2);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"island7",
  "west" : __DIR__"island13",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
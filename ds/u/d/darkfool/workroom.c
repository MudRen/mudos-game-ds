// Room: /u/d/darkfool/workroom.c

inherit ROOM;

void create()
{
	set("short", "[1;32mdarkfool[2;37;0m");
	set("long", @LONG
���դ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "morral" : "/u/m/morral/workroom",
  "east" : "/u/d/darkfool/area1/1",
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}

// Room: /u/a/acme/area3/p12.c

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�@����e�F�誺���Y�A���Y���\��F�\�h�p�֮�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p16",
  "west" : __DIR__"p5",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

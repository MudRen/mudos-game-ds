// Room: /u/a/acme/area3/p5.c

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�@����e�F�誺���Y�A���Y���\��F�\�h�p�֮�A�b�_��O���j
�U�A���n�h�q���x�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"p12.c",
  "north" : __DIR__"p10",
  "west" : __DIR__"p13.c",
  "south" : __DIR__"p4",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

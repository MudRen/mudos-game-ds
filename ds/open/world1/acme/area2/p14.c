// Room: /u/a/acme/area3/p14.c

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�@����e�F�誺���Y�A���Y���\��F�\�h�p�֮�A�n��O������
�A���F�h�i�q���x�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p13",
  "south" : __DIR__"p15",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

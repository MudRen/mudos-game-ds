// Room: /u/a/acme/area3/p18.c

inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�A�����b���D���A�o�O�q���שЪ��p�D�A���a�O���L�t�A�_��I����
�שСA�n��h�O�ȩСA���F�i�ܮx�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p19",
  "east" : __DIR__"p3",
  "south" : __DIR__"p20",
]));
        set("light",1);
set("objects",([
  __DIR__"npc/aw2" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

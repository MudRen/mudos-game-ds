// Room: /u/a/alickyuen/area/dr27.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�A�Ө�F��|�T�Ӫ��n��A�o�䨫�Y�O�q���@�Ǥu�@�ǩM�𮧫ǡC�A
�ݨ��A�k�䪺�ж����W�g����ͥ𮧫Ǫ��P�l�G�ۡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dr16",
  "south" : __DIR__"dr28",
  "enter" : __DIR__"dr30",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

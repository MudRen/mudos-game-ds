// Room: /u/d/darkfool/area1/shop2.c

inherit ROOM;

void create()
{
	set("short", "���q�Ϋ~��");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"s3",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/f/fanny/area/towninn1f.c

inherit ROOM;

void create()
{
	set("short", "�d�B�ȴ�");
	set("long", @LONG
�o�O�@������]�S�����ũж��C
LONG
	);
	set("world", "undefine");
	set("shoet", "�d�B�ȴ�");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"town2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

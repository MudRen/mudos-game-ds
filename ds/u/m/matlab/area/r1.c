// Room: /u/m/matlab/area/r1.c

inherit ROOM;

void create()
{
	set("short", "�_����");
	set("long", @LONG
�o�ت����u��[���t�F�A�n��������N�O�H�ɷ|���@��A
�����ئ��۲H�H���v�l�A�����a�̰ʵۡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r2.c",
  "south" : __DIR__"start.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

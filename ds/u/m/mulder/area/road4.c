// Room: /u/m/mulder/area/road4.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �s���j�D");
	set("long", @LONG
�u�A�A�b�o�غC�C�a�V�_��A�A�N�i�H��o�����V�m�ҡD�i
��Ҧ��V�m�Ӵ��ɧA���ޥ��D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road3",
  "north" : __DIR__"road7",
]));
	set("no_clean_up", 0);
set("outdoors", "road");

	setup();
	replace_program(ROOM);
}

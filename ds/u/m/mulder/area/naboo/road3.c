// Room: /u/m/mulder/area/road3.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̬O�@����������D�A�q�o�̩��譱�i�H���@�����]�A
�Ӧb�F�䦳�@���s�a�C�A�i�H�ݨ��o�̪��������b���L�a�u�@
�C���_�ONaboo���������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
  "north" : __DIR__"middle",
  "west" : __DIR__"inn",
  "east" : __DIR__"bar",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

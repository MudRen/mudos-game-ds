// Room: /u/s/sonicct/area/road4.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�̪��������b���L�a�u�@�A�ӧA���Ǭ�M���X�F�@�Ӥp��
�~�o�A��e����A��Ө��Ӥp�ĥ��M��L�p�Ī����g�áC��M�A
���@������b�A�P�����L�C�o�̩��_���i�H��F�Ӯc�j���C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"shop2",
  "west" : __DIR__"shop3",
  "north" : __DIR__"road5",
  "south" : __DIR__"middle",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

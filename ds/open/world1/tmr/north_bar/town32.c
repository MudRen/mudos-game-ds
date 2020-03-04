// Room: /open/world1/tmr/north_bar/town32.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�Ө�o�̡A�A�o�{�o������G�O��v�ϡA���䳣�O�@�ǥ���
�A���O����o�����۷���ª��ЫΡA�S�O�ޤH�`�N�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"town33",
  "west" : __DIR__"town11",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

// Room: /u/s/sonicct/area/road1.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�b�o�̧A�i�H�ݨ�_�����j��Q���c�a�A��ť����x���H�s
�n�C�n���i�H�����ӪŲ���L�a��h�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road2",
  "south" : __DIR__"gate1",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

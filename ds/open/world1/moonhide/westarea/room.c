// Room: /open/world1/moonhide/westarea/room.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�̬ݰ_�ӬO�@�������A�s�j�L��A���O���������ݪ���A����
�������A���@�ӥW�ѡA���O�@���������A���F�o�ӡA�N�S���䥦����
���S�x�F�C
LONG
	);
	set("outdoors", "land");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"way7",
  "northeast" : __DIR__"room9",
  "northwest" : __DIR__"room8",
]));
	set("no_clean_up", 0);
	set("light", 1);

	setup();
	replace_program(ROOM);
}

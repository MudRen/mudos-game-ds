// Room: /u/a/acme/area/hills3.c

inherit ROOM;

void create()
{
	set("short", "���F��");
	set("long", @LONG
�o�̴N�O���F���F�A�b�A�}���ɬO���C�⪺�ӨF�A���B���O�o�󤣥�
�ƬO�j�ǡA���ߤ����ðݫo�w�Q���ߩҨ��N�A�u���F�a�����Ӥ����W���F
��bį�ʵۡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hills",
  "south" : __DIR__"portal",
  "east" : __DIR__"hills2",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}

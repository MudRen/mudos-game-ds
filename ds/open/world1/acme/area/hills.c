// Room: /u/a/acme/area/hills.c

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
  "west" : __DIR__"pathway9",
  "south" : __DIR__"hills3",
  "east" : __DIR__"hills1",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}

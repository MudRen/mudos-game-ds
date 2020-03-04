// Room: /open/world1/tmr/north_bar/town23.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Юx�|");
	set("long", @LONG
�o�̬O�����a���e���x�|�A�̭��ص۳\�h��A�ݨӧ���
�����W���y�ڻᰪ�A�x��������󤫵M���ǡA���ݸ����j
��A��ݫo�O���n���P�A���Z�������_�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town22",
  "north" : __DIR__"town25",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

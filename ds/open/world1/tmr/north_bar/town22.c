// Room: /open/world1/tmr/north_bar/town22.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"town23",
  "east" : __DIR__"town22e",
  "west" : __DIR__"town21",
]));
	set("objects", ([ ]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}

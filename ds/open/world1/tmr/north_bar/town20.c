// Room: /open/world1/tmr/north_bar/town20.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Ч����a��");
	set("long", @LONG
�o�̬O�_�Z�������a���j���A�S�Q������a�~�M����j
�A��@�몺��v�j�W�T���A���L�������H�M���A�]�O�D�`�w
��~�ȶi�h�����C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"town21",
  "west" : __DIR__"town13",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}

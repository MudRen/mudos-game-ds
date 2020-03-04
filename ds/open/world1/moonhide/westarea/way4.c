// Room: /open/world1/moonhide/westarea/way4.c

inherit ROOM;

void create()
{
	set("short", "����-�����q�D");
	set("long", @LONG
�A���b�����W�����D�A�}�U�򪺬O�ιΥժ�᪺�����A�A�]���M
���H���i�௸�b���W�A�o���T�O�Ӥ��Ѥ��g�C�o�̬O�B�Q�r���f�A
�������|���K����i�ӥh�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"way3.c",
  "south" : __DIR__"way5.c",
  "east" : __DIR__"hall2",
  "west" : __DIR__"hall1.c",
    "down" : __DIR__"way4d.c",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}

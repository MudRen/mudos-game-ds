// Room: /open/world1/tmr/goat_maze/tree1.c

inherit ROOM;

void create()
{
	set("short", "�B�L��}");
	set("long", @LONG
�A�����b�B�L�Ѥ쪺��}���A�}�ǺɬO�G�䪺��d�ڡA�٦��X�Q����
�����W���θ���ΡA���b�d�ڤ��p���p�h�A�Ʀ��٦��X������A���y�W��
�I�W�A�d���A�߸̵o��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"maze10",
  "north" : __DIR__"tree2",
]));
        set("objects", ([
                __DIR__"npc/bug" : 1 + random(3), 
        ]) );

	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

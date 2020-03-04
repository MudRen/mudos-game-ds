// Room: /open/world1/tmr/goat_maze/tree2.c

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
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/toad-king" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tree1",
]));
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}

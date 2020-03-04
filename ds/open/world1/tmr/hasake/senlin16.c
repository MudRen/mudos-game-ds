// Room: /open/world1/tmr/hasake/senlin14.c

inherit ROOM;

void create()
{
	set("short", "�w���L");
	set("long", @LONG
�o�O����Ѥs�}�U���@���w���L�A�L�����~���s�A���a�Q�\�۫p�p�@
�h�P�w�C��_�誺�@�y���q���s�߫K�O�Ѥs�F�A�s�W�צ~�n���A�s�U�o�O
��𦨽��C���F�n���K�O�j���A�����Ԫ����ħJ�ڤH�b���̩񪪡C
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"senlin4",
]));

	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wolf2" : 2,
  __DIR__"npc/wolf3" : 2,
]));
	setup();
	replace_program(ROOM);
}

// Room: /u/s/slency/area/ugelan/farm7.c

inherit ROOM;

void create()
{
	set("short", "�p�T��");
	set("long", @LONG
�o���T�Ϊ���W�����䱾���F�ܦh���A�Ѥu��A�@�ݴN���D�O�o��
���A�̪���ҡA�̭�������ͬ��Ϋ~�A�O�H�Pı��m�������𮧡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"farm6",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}

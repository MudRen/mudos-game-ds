inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�A���b�@�����q�����и̡A���e������\�]���A�۫H�������D�H
�u�O�@�ӥ��Z�������A�ݵ���}���ѥФu��M���Y�A�ݨӳo�̪��D�H
�u�@�۷�ԾġC
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"burg2",
	]));
	set("objects",([
		__DIR__"npc/random.c":1,
	]));

	setup();
	replace_program(ROOM);
}

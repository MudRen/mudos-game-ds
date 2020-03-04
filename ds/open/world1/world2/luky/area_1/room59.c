// Modify with AreaMaker1.0
// Room59.c

inherit ROOM;

void create()
{
	set("short","��L��t");
	set("long", @LONG
�A�����b��L�̡A�o�̪����������C�@�ǡC�L�����j�A�𸭵o
�X�@�}�F�F�F���n���C���䦳�Ӥp����A�Ѧ�ˬM�b�����W�Q���g�N
�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room49",
		"east": __DIR__"room60",
		"south": __DIR__"room69",
		"northwest": __DIR__"room48",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
		__DIR__"npc/bird0" : 2,
		__DIR__"npc/pig1" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}


// Modify with AreaMaker1.0
// Room98.c

inherit ROOM;

void create()
{
	set("short","�����");
	set("long", @LONG
�A���b���L���䪺�@�O��襤�C�o�̨�B���O�M�A�@�˰�����
�A�A�ڥ��ݤ��M���o�̦�����X���C���������L�����G���@�ǲ�
�L���n���A���`�Nť�O�����o�{���C
LONG
	);
	set("hide_exits", ([
		"north": __DIR__"room88",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pig0" : 4,
		__DIR__"npc/pig2" : 1,
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}


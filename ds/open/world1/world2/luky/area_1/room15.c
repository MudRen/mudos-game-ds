// Modify with AreaMaker1.0
// Room15.c

inherit ROOM;

void create()
{
	set("short","��L���");
	set("long", @LONG
�o�̥|�P���O�M�H�@�˰�����A�A�����ݨ���̦����i���C�_��
�O���q�������A�n��h�O�@�ʫܰ��ܰ����j��C
LONG
	);
	set("exits", ([
		"west": __DIR__"room14",
	]));
	set("hide_exits", ([
		"east": __DIR__"room16",
 	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pig0" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}


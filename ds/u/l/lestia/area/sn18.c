// Room: /u/l/lestia/area/sn18.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG

��A����o�̡A�A�o�{��Ǫ����󤤦��G���ﳱ�˴˪������n�ۧA�ݡA
���ѩ�����ư��A�A�]�ݤ��X�өҥH�M�ӡA�u���q�q���~��V�`�B���h�A�A
�Pı�A�V���`�B���A���������������]��ۧA�@�_���A���G�O�H�ɦ��H�b�A
�����k�A�@�شH�N���Pı�q�A���Y«�_�A�ϧA���ѱo���F�ӧNŸ�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/dog":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn19",
  "south" : __DIR__"sn17",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}

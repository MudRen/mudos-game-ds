// Room: /d/xiangyang/xinluofang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�sù�{");
	set("long", @LONG
�sù�{�A�U�W��q�O���sù�H���a��A���L���{�b�s
ù�w�g�Q���R�ҷ����A�o�����ӥs�����R�{���C�i�O�j�a�w�g
�ߺD�F�A��O�K�ٳo��s�C�o�̦�۳\�h���R�ӤH�A�]���ǰ�
�R���Ϧڶi�F�ʫ����L�����A�K�]��b�o�̡C�o�̪����R�ӤH
�`���ܦh�ܦn���f���A�j�a�����w�ӶR�A��O�o�̴N�D�`����
�x�F�C
LONG );
	set("exits", ([
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/gaoli" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


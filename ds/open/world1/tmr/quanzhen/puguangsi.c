// /d/quanzhen/puguangsi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�����x");
	set("long", @LONG
�o�O�@�Ӧ��׫n�s�U���p�x�q�A�q�����B�g�� "�����x" �T��
�j�r�C�ѩ󦹼q�O�W�׫n�s�����g�����A�j�h�ƪ��C�ȳ��|�b�����}
�𮧡A�]�]�����B�����]�ᬰ�����C�q�e���X��Q��U�A�ߵۤ@����
�O(shibei)�A�X�G�ֳQ�P�򪺪��󵹾B���F�C���訫�O�@���p��.
LONG
	);
	set("outdoors", "zhongnan");
	set("exits", ([
		"west" : __DIR__"shanlu4",
	]));

	set("coor/x", -3120);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

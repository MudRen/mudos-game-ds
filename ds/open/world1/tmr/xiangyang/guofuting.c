// Room: /d/xiangyang/guofuting.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�������U");
	set("long", @LONG
�o�̬O���������U�C�U�����j�A�o�G�m�������P�C�F���a
���ۥ|�T�̱��Aø���O������˥|�ت�c�F����a�����O�K�L
��V�C���U�~�����O�@�i�K�P��C��W�ݩ�ۤ@�M����A���
�\��ۥ|�i�ȭ��ȡA��o�����j��C�U���U�\��ۤ@�֨d����A
���G���o�̱a�Ӥ@���x�N�C�_�����𪺯��Ψѩ^�������e���A
�W���O�@����T�A�W�ѡ��٧ڪe�s���C
LONG );
	set("exits", ([
		"south" : __DIR__"guofuyuan",
		"north" : __DIR__"guofuhuayuan",
	]));
	set("objects", ([
//          __DIR__"task/guo" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

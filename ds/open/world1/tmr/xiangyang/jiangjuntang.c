// Room: /d/xiangyang/jiangjuntang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�N�x���j��");
	set("long", @LONG
�o�̬O�N�x�����j��A���׫�ݧ��ۤ@�ӫ²r���N�x�A��
�@�y�h�ΡA�ݨө��ԭ��k���ҼˡC�j������\�ۧL���[�A�[�W
�W�b���d���A�M�۬[�᪺�ԺX�A���~ģ���C��Z�N���A����
�Х��~�A�����ө����A�ƬO�����C
LONG );
	set("exits", ([
		"south" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
		__DIR__"npc/zuo" : 1,
		__DIR__"npc/pian" : 1,
		__DIR__"npc/ya" : 1,
		__DIR__"npc/pi" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
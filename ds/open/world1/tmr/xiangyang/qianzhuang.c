// Room: /d/xiangyang/qianzhuang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�̬O�����������A�]���o�̰ӷ~�۷�o�F�A�U�a���Ӹ�
���M�o�̦��ȿ��ө��C�����̦��ܦh�H�b�s�����A�]���H�b�I
���Ȩ�C�ݵ۳o��h�����]�u�Ӻu�h�A�u�O���H���a�ڡC����
�U�j�ķ�e�A�����@�P��m���L�C�������~�ȥѵؤs�̤l���ޡA
�䴩�j�L���t�M���ҤH�C��W�K�ۤ@�ӵP�l(paizi)�C
LONG );
	set("item_desc", ([
		"paizi" : @TEXT
     ���������ѥH�U�A�ȡG
      �s��        deposit
      ����        withdraw
TEXT
	]));
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/huangzhen" : 1,
	]));
	setup();
	replace_program(ROOM);
}


// Room: /d/xiangyang/tiejiangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�K�K�Q");
	set("long", @LONG
�o�̭�ӬO�@�a����²�����K�K�Q�C��~�ӻX�j�j�x��
�i�������A�o�a�K�K�Q�Q�x���x�ΡA�@���x��@�{�C�ثe�W��
�ܤj�A�@��ΨӬ������u�x���y�Z�ҡB�L�����A��Ӧ]������
�w�Ʀu������A�^���ҤH���R�]�Ͳ��@���K??�B�K��B����
�Y���C�u���X�Q���K�K���m�m����a���Ӥ����C
LONG );
	set("exits", ([
		"west" : __DIR__"southjie3",
	]));
	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�ĺ��Ĵ��s��");
	set("long",@LONG
�o�̤w�g�W�L�F�쥻�ĺ��Ĵ����d��A�O�����s�}�o���ϰ�C�۹��
�´�ϡA�o�̸g�L�۷��W���Ϋس]�A�q�o�̩��n�O�D�n���ӷ~�ϡA����
�O�ӰȽX�Y�A���F�h�O�۷��[���שԤj�D�C�s�o���a�U���D���}�f�]�b
���A�ӤH�̺ٳo�Ƿs�}�o���ϰ쬰�u�N�s�G�H�]�|�Į����]�p�v�C���L�o
�ǰϰ쪺�H�X�G���O�~�Ӫ̡A�쥻�ĺ��Ĵ����~���ϦӤ����w�o�̡C
LONG 
);
	set("exits",([
	    "north":__DIR__"port_11",
	    "east":__DIR__"port_20",
            "west":__DIR__"port_15",
	    "south":__DIR__"port_23",
		]));
	set("objects",([
	    __DIR__"npc/ad_wm":2,
	    __DIR__"npc/ad_mn":3,
		]));
	set("item_desc",([
	    "�a�U���D":"�o�̦��ӤJ�f�A�i�H�q���ĺ��Ĵ����a�U���D�C(�ϥΫ��Oenter)\n"
	]));
	set("world","world1");
	set("outdoor","land");

	setup();

}
void init()
{
	add_action("do_enter","enter");
}
void do_enter()
{
	this_player()->move(__DIR__"port_b1");
	return;	
}
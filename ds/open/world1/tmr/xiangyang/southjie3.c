// Room: /d/xiangyang/southjie3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�n�j��");
	set("long", @LONG
�o�̬O�������n�j�󪺫n�Y�C�n���N�O���������A�_��D
�`���x�C�F��O���������u�x�����Z�ҪZ�����L���Q�C�Q�l�~
�ӡA�ѩ�X�j�x���I�ǡA�m�m�������K�n���N�@���T�Ӥ����C
�譱�O���������n�L��A������ť���̭��ǨӪ��L�h�̪��޽m
�n�C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"tiejiangpu",
		"west"  : __DIR__"bingying3",
		"south" : __DIR__"southgate1",
		"north" : __DIR__"southjie2",
	]));
	set("coor/x", -500);
	set("coor/y", -540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/xiangyang/southjie1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�n�j��");
	set("long", @LONG
�o�O�@���e�諸�C�۪O��D�A�V�n�_���Y�����C�n��N�O
�������A�_���O�����s���A�譱�O�����A�F���O������������
�@�@�a�ǰ�C���M�����Ԥ����_�A�A����ť��ǰ�̶ǨӾǥ�
�̮ԮԦaŪ���n�C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"xuetang",
		"west"  : __DIR__"qianzhuang",
		"south" : __DIR__"southjie2",
		"north" : __DIR__"guangchang",
	]));
	set("coor/x", -500);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
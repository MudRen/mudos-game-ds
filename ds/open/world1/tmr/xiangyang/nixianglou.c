// Room: /d/xiangyang/nixianglou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�V����");
	set("long", @LONG
�������̨S�������D���V���ӡ����C���O�ܾԮɴ��A�ө�
���ȫo�h�A����͸�]�I�A�ͷN�Ϩ������C�ӤU�G�m²���A�U
�Ȧh�O�^�^����H�A�R�I�]�l�B���L�B�̰s�N�����h�F�C�ӤW
�O���y�C�ܾԴ����A�F��`���A���\���N�A�N�Sԣ�ͷN�A�u�n
���F�C
LONG );
	set("exits", ([
		"west" : __DIR__"southjie2",
	]));
	set("objects", ([
//         __DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

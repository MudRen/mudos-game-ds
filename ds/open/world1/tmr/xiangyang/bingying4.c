// Room: /d/xiangyang/bingying3.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�L��");
	set("long", @LONG
�o�̬O�L��A�K�K�³¨�B���O�x�L�A�����b�Z�N������
�U�C���޽m�A�����W�ۦb�m�\�A�������ۡB���ۥ��b�𮧡C�n
��U���ۥD�ӡA�����n��a�M���ۥ|�P�C�ݨ�A�i�ӡA�L�̥�
���V�A���j�����n�ۧA�C
LONG );
	set("item_desc", ([
		"dong" : "\n",
	]));

	set("exits", ([
		"south" : __DIR__"westjie3",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -540);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


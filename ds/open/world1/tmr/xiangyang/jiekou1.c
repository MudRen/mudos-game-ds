// Room: /d/xiangyang/jiekou1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�j��f");
	set("long", @LONG
�]���o��O�Q�r��f�A�ҥH�D�`���x�C�p�Ӥp�c�̦b�V��
�H�[�ܵۡA�°�L�̪��ӫ~�C���M���������X�j�x�I�Z�A���o
��ݤ��X�H�̦����@����i�A�n���L�̤w�q�Ũ��D�B�ߥH���`
�F�C�_���M�譱�O�J�P�A�\�h���������Ѧʩm��b�̭��A�F��
�M�n���O�C�۾Q�N���j��C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"northroad1",
		"south" : __DIR__"westroad2",
		"west"  : __DIR__"hutong1",
		"north" : __DIR__"hutong2",
	]));
	set("objects", ([
	//	"/d/village/npc/seller" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
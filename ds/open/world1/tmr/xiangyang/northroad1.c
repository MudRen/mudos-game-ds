// Room: /d/xiangyang/northroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�_���j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j�D�C�u���_���O�@���Q���ܤj��
���f�Q�Ať���̭���R��\�h�F��C�V�F�N�O�B�r��f�A�譱
�]�O�@�Ӥj��f�A�A�n���ݨ�@���j��q�V�n���C�n���O�@��
�W�\����[���˪�����A�̭��O�����w���ϧf��w�w�Ƶ��L��
����ȭ�B�H�ٳ��j�L���t������C
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"jiekou1",
		"east"  : __DIR__"dingzi",
		"north" : __DIR__"xinluofang",
	]));
	set("coor/x", -520);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
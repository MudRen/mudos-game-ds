// Room: /d/xiangyang/northroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�_���j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j�D�C�u���_�����ɪ����������b
�ӥX�A���A�_���O����C�V��N�O�B�r��f�A�F���]�O�@�Ӥj
��f�A�A�n���ݨ�@���j��q�V�n���C�n���O�@���W�\����[
���˪�����A�̭��O�����u���j�N��������C
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"jiekou2",
		"west"  : __DIR__"dingzi",
	]));
	set("coor/x", -500);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

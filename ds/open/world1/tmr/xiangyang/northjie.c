// Room: /d/xiangyang/northjie.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�_�j��");
	set("long", @LONG
�o�O�@���e�諸�C�۵�D�A�V�n�_���Y�����C�_���O�ȪZ
�����A�n����o���c���C�F��O�@���]�A�@���W�ѡ���������
�n�b���������a�n���ۡA�@�Ѫѯ��������ӨӡC�譱�O������
���_�L��A������ť���̭��ǨӪ��޽m�n�C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"dingzi",
		"west"  : __DIR__"bingying1",
		"north" : __DIR__"northgate1",
	]));
	set("coor/x", -510);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
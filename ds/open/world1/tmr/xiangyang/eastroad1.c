// Room: /d/xiangyang/eastroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�F���j��");
	set("long", @LONG
�o�O�@���C�۾Q�N���j��C�譱�O�@���\�۬���[���˪�
����A�̭��O�����u���j�N��������j�|�C�F���O�O�@�y��
���A�_���O�ΫC�۾Q���j��D�C�n���O�@�Ӥj���Q�r��D�A�u
���H�ӤH���A�D�`���x�C
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"biaoju",
		"south" : __DIR__"eastjie2",
		"north" : __DIR__"eastroad2",
	]));
	set("coor/x", -480);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
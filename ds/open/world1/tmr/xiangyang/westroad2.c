// Room: /d/xiangyang/westroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�褺�j��");
	set("long", @LONG
�o�O�@���C�۾Q�N���j��C�_���O�Q�r��f�C�����a���
���n���O�@�y�ܰ����m�ӡA�F���O�@���\�۬���[���˪�����A
�̭��O�����j�|�C�譱�O���������s�}���@�a�ѩ��Ať���̭�
��R��ܦn���ѡC
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"shudian",
		"south" : __DIR__"westroad1",
		"north" : __DIR__"jiekou1",
	]));
	set("coor/x", -530);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
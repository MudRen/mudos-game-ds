// Room: /d/xiangyang/dingzi.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�B�r��f");
	set("long", @LONG
�o�̬O�������_�����B�r��f�C�V�_�@���q�V�ȪZ���A�F
���M�譱�O�@���������C�ۤj��A�q�V�����C�n���O�@���W�\
����[���˪�����A�̭��O�����w���ϧf��w������C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"northroad2",
		"west"  : __DIR__"northroad1",
		"north" : __DIR__"northjie",
	]));
	set("coor/x", -510);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
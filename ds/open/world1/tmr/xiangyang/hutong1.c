// Room: /d/xiangyang/hutong1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�J�P");
	set("long", @LONG
�o�̬O���������Ѧʩm���~��ϡC�u���J�P����O���Ǥp
�����A���̦�B�p���f�Q���C�@�ǩ~���q�o�̶i�i�X�X�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east" : __DIR__"jiekou1",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 1,
		__DIR__"npc/boy" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


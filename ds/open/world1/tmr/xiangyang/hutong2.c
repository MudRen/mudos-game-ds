// Room: /d/xiangyang/hutong2.c
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
		"south" : __DIR__"jiekou1",
	]));
	set("objects", ([
		__DIR__"npc/girl" : 2,
	]));
	set("coor/x", -530);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


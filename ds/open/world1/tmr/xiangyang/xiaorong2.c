// Room: /d/xiangyang/xiaorong2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�J�P");
	set("long", @LONG
�o�̬O���������Ѧʩm���~���ϡC�u���p�˨���O���Ǥp
�����A���̦�B�p���f�Q���C�@�ǩ~���q�o�̶i�i�X�X�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"jiekou2",
	]));
	set("objects", ([
		__DIR__"npc/boy"  : 1,
		__DIR__"npc/girl" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
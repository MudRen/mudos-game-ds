// Room: /d/xiangyang/xiaorong1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�J�P");
	set("long", @LONG
�o�̬O���������Ѧʩm���~��ϡC�u���p�˨���O���Ǥp
�����A���̦�B�p���f�Q���C�@�ǩ~���q�o�̶i�i�X�X�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west" : __DIR__"jiekou2",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 2,
	]));
	set("coor/x", -480);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/xiangyang/guofuhuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�o�̬O����������A�餺���s�L�ߡA����صۤ@�ǫC�ˡA
�F��O�X�ʪK���Z�����쵧���C�A�@���i�ӡA�N�D��@�}�}
�M�s���B�H�H���᭻�C
LONG );
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"guofuwoshi",
		"west"  : __DIR__"guofukefang",
		"south" : __DIR__"guofuting",
		"north" : __DIR__"guofushufang",
	]));
	set("objects", ([
		__DIR__"npc/huang" : 1,
	]));
	set("coor/x", -520);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// shanjiao.c �׫n�s�}
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�׫n�s�}");
	set("long", @LONG
�o�̬O�׫n�s���s�}�A�׫n�s���٦�_���Ĥ@�s�A�H�s�թ_�m�A
���ҲM�յۺ١C�o�̪��s���٫ܥ��w�A�@�D�۶��d��q���s�W�C���e
�O�@�y���s�A�p�P���Ѥ@�W�봡�V�ѪšA�ҥH�j�H���֥y�������׫n
�@�W�������k�C
LONG
	);
	set("outdoors", "zhongnan");
	set("exits", ([
		"north"    : __DIR__"shanlu4",
		"westdown" : __DIR__"shanlu3",
	]));
	set("objects",([
		__DIR__"npc/youke" : 1,
		__DIR__"npc/xiangke" : 2,
		"/clone/misc/dache" : 1,
	]));

	set("coor/x", -3130);
	set("coor/y", -10);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

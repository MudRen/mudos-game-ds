// Room: /d/xiangyang/walle5.c
// Date: Jan. 8 1999 by Winder
// Modified by Zeratul Jan 15 2001,����F�ƨg����

inherit __DIR__"wall.c";

void create()
{
	set("short", "�۶�");
	set("long", @LONG
�o�O�n�V���Y���۶��A�]������ܰ��A�ҥH�ܰ~�C�۶���
�����i�ѩԨ��W�U���שY�D�C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"southup"   : __DIR__"walle7",
		"northdown" : __DIR__"walle3",
	]));
	set("coor/x", -450);
	set("coor/y", -530);
	set("coor/z", 30);
	setup();
}
// Room: /d/xiangyang/wallw1.c
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
		"northup"   : __DIR__"wallw3",
		"southdown" : __DIR__"westgate1",
	]));
	set("coor/x", -550);
	set("coor/y", -490);
	set("coor/z", 10);
	setup();
}
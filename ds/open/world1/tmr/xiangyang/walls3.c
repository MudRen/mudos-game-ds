// Room: /d/xiangyang/walls3.c
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
		"westup"   : __DIR__"walls5",
		"eastdown" : __DIR__"walls1",
	]));
	set("coor/x", -520);
	set("coor/y", -550);
	set("coor/z", 20);
	setup();
}
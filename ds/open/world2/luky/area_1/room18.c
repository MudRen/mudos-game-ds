// Modify with AreaMaker1.0
// Room18.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
��B���O���j�����A�A�o�{�o�̪����ܱj�A�s��W�����l�X�G
���Q�j���@���]�S���F�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room19",
		"south": __DIR__"room28",
		"west": __DIR__"room17",
		"northeast": __DIR__"room9",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}


int valid_leave(object me, string dir)
{
	if( dir=="northeast" )
		return notify_fail("���̪����ӱj�F�H�ܩ�A�L�k���L�h�C\n");
	return ::valid_leave(me, dir);
}

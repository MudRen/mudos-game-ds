// Modify with AreaMaker1.0
// Room30.c

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�o�̬O�������쪺�F�_���A�A������O�@�j����L�C�o�̤@�~�|
�u���j�۱j�l���g���A�ѩ�j���������F����A�ҥH�\�h�Ӫ����L�k
�b�o�̥ͪ��A�b�o�̧A�����C���Y�~��j�j�i�}�����C
LONG
	);
	set("exits", ([
		"north": __DIR__"room20",
		"west": __DIR__"room29",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir=="north" )
		return notify_fail("���̪����ӱj�F�H�ܩ�A�L�k���L�h�C\n");
	return ::valid_leave(me, dir);
}

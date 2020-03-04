// Modify with AreaMaker1.0
// Room19.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�j�j�������_���q�F�_��j�ӡA�g���ϧA�����C�}�����ݲM���o
�̦��Ǥ���F��C��ۦp�l�u�르�b�A���ֽ��W���A�k�h���@�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room9",
		"east": __DIR__"room20",
		"south": __DIR__"room29",
		"west": __DIR__"room18",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir=="east" || dir=="north" )
		return notify_fail("���̪����ӱj�F�H�ܩ�A�L�k���L�h�C\n");
	return ::valid_leave(me, dir);
}

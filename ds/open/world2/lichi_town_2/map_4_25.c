inherit ROOM;
void create()
{
	set("short", "���]�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_26",
	"south" : __DIR__"map_5_25",
	"north" : __DIR__"map_3_25",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
}


int valid_leave(object me, string dir)
{
	if( dir=="north" )
	{ 
		if(!me->query_temp("malo/inn") ) return notify_fail("��A����Ъ��ɡA��Ǭ�M���X�\\�h�]��צ�F�A���h���C\n�j�U�̬�M�ǨӮ��]�p�j���n���G�o���U�ȽХ����d�i�q�СC\n");
		if(this_object()->query("full")) return notify_fail("��A����Ъ��ɡA�o�{�̭��w�g���H�F�A�A�u�n���@���F�C\n");
	}
	return ::valid_leave(me, dir);
}

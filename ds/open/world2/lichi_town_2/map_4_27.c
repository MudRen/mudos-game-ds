inherit ROOM;
void create()
{
	set("short", "���]�j�U");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_27",
	"north" : __DIR__"map_3_27",
	"west" : __DIR__"map_4_26",
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
}

int valid_leave(object me, string dir)
{
	if( dir=="north" )
	{ 
                if(!me->query_temp("malo/inn") ) 
	{
	tell_object(me,"��A����Ъ��ɡA��Ǭ�M���X�\\�h�]��צ�F�A���h���C\n�j�U�̬�M�ǨӮ��]�p�j���n���G�o���U�ȽХ����d�i�q�СC\n");
		return notify_fail("");
	
}
                if(this_object()->query("full")) 
	{
tell_object(me,"��A����Ъ��ɡA�o�{�̭��w�g���H�F�A�A�u�n���@���F�C\n");
		return notify_fail("");
}
// edit by alick
	}
	return ::valid_leave(me, dir);
}

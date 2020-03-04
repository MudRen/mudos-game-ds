// Room: /d/xiangyang/juyichufang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o��O�E�q�]���p�СA�@��u���դѦ��X�ӿN���v�Ŧb�N
�������A�����]serve�^�뭹�A��F�ߤW�N�ݧA���B��F�C
LONG );
	set("exits", ([
		"north" : __DIR__"juyihuayuan",
	]));
	set("objects", ([
		__DIR__"npc/shaofanshifu" : 1,
	]));
	set("no_fight", 1);
	set("ricewater", 30);
	set("coor/x", -530);
	set("coor/y", -505);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("�N���v�����ۤ@���ǲ��G�Y���F�n�µۨ��ڡH\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
        if(present("rice",this_player()) ) 
		return notify_fail("�N���v�ŹD�G�Y���F�A���A�O���O�����C\n");
        if(present("rice",this_object()) ) 
		return notify_fail("�N���v�ŹD�G�Y���F�A���A�O���O�����C\n");
	if (query("ricewater")>0)
	{
		message_vision("�N���v�ŵ�$N�@�J���d�̶��M�@�J������C\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("�N���v�Ź�$N�p�n�D: �١A�Y���ܪ����S�F�C\n",me);
	return 1; 
}
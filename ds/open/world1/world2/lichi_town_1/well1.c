inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�o�Ӥ����G���F�ܤ[�A�������F�\�h����������C
LONG
);
	set("exits",([
		"west" : __DIR__"well2",
	]));
        set("item_desc",([      
        "����" : "�o����(wall)���O�|�}�M�ʤf�A�ݨӤ����k��(climb)�C\n",
        "wall" : "�o����(wall)���O�|�}�M�ʤf�A�ݨӤ����k��(climb)�C\n",
        ])      );

    set("objects", ([
       __DIR__"../npc/beast_frog_3" : 1,
    ]));
	set("outdoors","land");
	set("no_weather",1);
        setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	if(!arg) return notify_fail( "�A�Q��(climb)����?\n");
	if(arg=="wall" || arg =="����")
	{
		message_vision("$N�u�ۤ����p���l�l�����F�W�h�C\n",this_player());
		this_player()->move(__DIR__"map_5_6");
		if(!this_player()->query_temp("invis"))
			tell_room(environment(this_player()),this_player()->name()+"�q�������F�W�ӡC\n",({this_player()}));
		return 1;
	}
	write("�A�Q��(climb)����?\n");
	return 1;
}

int room_effect(object me)
{
	object room=find_object(__DIR__"map_5_6");
	return room->handle_well_effect(me);
}

int valid_leave(object me, string dir)
{
	object room=find_object(__DIR__"map_5_6");
	if( dir=="west" && room->query_well())
	{
		if(random(me->query_skill("swim"))<15) return notify_fail("�A����a�ޥ��Ӯt�A�夣�L�h�C\n");
	}
	return ::valid_leave(me, dir);
}
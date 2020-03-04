inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�o�Ӥ����G���F�ܤ[�A�������F�\�h����������C
LONG
);
	set("exits",([
		"east" : __DIR__"well1",
		"up" : __DIR__"well3",
	]));

    set("objects", ([
       // __DIR__"../npc/beast_frog_3" : 1,
    ]));
        setup();
}

int room_effect(object me)
{
	object room=find_object(__DIR__"map_5_6");
	return room->handle_well_effect(me);
}

int valid_leave(object me, string dir)
{
	object room=find_object(__DIR__"map_5_6");
	if( dir=="east" && room->query_well())
	{
		if(random(me->query_skill("swim"))<15) return notify_fail("�A����a�ޥ��Ӯt�A�夣�L�h�C\n");
	}
	return ::valid_leave(me, dir);
}
inherit ROOM;
void create()
{
        set("short", "�p��");
        set("long", @LONG
�|�g���F�����A��_�F�ƭӧ֤�H�����F��C
LONG
);
        set("exits",([
                "north" : __DIR__"map_5_9",
                "south" : __DIR__"map_7_9",
        ]));
        set("objects",([
                __DIR__"npc/bandit":2,
        ]));
        set("detail",([
                "�F��" : "�o��|�P�ﺡ�ƭӨF��A�䤤�٦��ӻ�j���F�ޡA�����ण��i���h...\n",
        ]));
        set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        ::init();
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me = this_player();
        if(!arg || arg!="�F��" ) return 0;
        if( me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��䥦���ơC\n");
        message_vision("$N�@�s�y�i�h�F�@�B�F��....\n",me);
        me->move(__DIR__"cave_enter.c");
        tell_room( environment(me) , me->name() + "�q�~�����F�i��", ({ me }) );
    return 1;
}


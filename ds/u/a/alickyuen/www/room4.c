#include <ansi.h>
inherit ROOM;
string *exit = ({
       __DIR__"becloud1", __DIR__"becloud2",
       __DIR__"becloud3", __DIR__"becloud4",
       __DIR__"becloud5", __DIR__"becloud6",
       __DIR__"becloud7"
});

void create()
{
    set ("short", HIW"�@��"NOR);
    set ("long", @LONG
�Ҩ��|�g�ɬO�@�������A�@�p���������H���������D
�n����B���C
LONG);
    set("exits", ([
        "south"   : __DIR__"room2"]));
    set("outdoors","forest");
    set("no_map", 1);
    set("no_horse_member",1);
    set("no_clean_up", 0);
    setup();
}

void init()
{
    object me = this_player();
    if(interactive(me) && !me->query_temp("safe") && random(10) == 1)
    { 
        message_vision(HIY"��M�j�Ӥ@�}�j�j�����A�w�O��$N�j���C\n"NOR,me);
        tell_room(__DIR__"room2",HIY"��M�@�}�j���j�L�A"+me->query("name")+"���n���U�C\n"NOR);
        me->receive_damage("hp",50+random(100));
        me->start_busy(2);
        me->move(__DIR__"room2");
        write(HIR"�A�Q�������L��a�W�I\n"NOR);
    }
    set("exits", ([
        "south" : exit[random(sizeof(exit))],
        "north" : exit[random(sizeof(exit))],
        "east"  : exit[random(sizeof(exit))],
        "west"  : exit[random(sizeof(exit))]
    ]));
    return;
}

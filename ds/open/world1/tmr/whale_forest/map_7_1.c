inherit ROOM;
void create()
{
        set("short", "�L����a");
        set("long", @LONG
�L���p�|��F�o�̡A�N�����b�@�O����襤�C
LONG
);
        set("exits",([
        "east" : __DIR__"map_7_2",
        ]));
        set("detail",([
        	"����":"�@�ﰪ�i�θy������A�����O�_���V(pass)�L�h..\n"
        ]));
        set("map_long",1);     //show map as long
        set("outdoors","forest");
                set("objects", ([ /* sizeof() == 1 */
                          __DIR__"npc/bear" : 3,
                ]));

        setup();
}

void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me=this_player();        if(!arg || arg!="����")
                return notify_fail("�A�n��V���̡H\n");
        if(me->is_busy())               return notify_fail("�A�{�b�S���šC\n");        message_vision("$N���}���󨫤F�i�h...\n",me);   me->move("/d/whale_river/map_5_19");                    tell_room(environment(me),me->name()+"�q�����̨��F�L�ӡC\n",me);
        return 1;
}


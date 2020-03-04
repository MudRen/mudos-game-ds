inherit ROOM;
void create()
{
        set("short", "��q�W���p��");
        set("long", @LONG
�A�`�N��_��L�Ϫ�����令���W�h��½��{���A���G�O���H�^�^��
�L�ӽ��a���ˤl�C
LONG
);
        set("exits",([
        "west" : __DIR__"map_8_8",
        "east" : __DIR__"map_8_10",
        "south" : __DIR__"map_9_9",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_pass","pass");
}
int do_pass(string arg)
{
        object me=this_player();
        if(!arg || arg!="�����")
                return notify_fail("�A�n�q�L���̡H\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�Х����U���䪺�Ƨa�C\n");
                message_vision("$N���⼷�}�F����A���F�L�h.....\n",me);
                me->move(__DIR__"thief_room");
                tell_room(environment(me),me->query("name")+"��L�����A���F�L�ӡC\n",me);
        return 1;
}




inherit ROOM;
void create()
{
        set("short", "���D");
        set("long", @LONG
���D�q��F�o�̡A���M�N�Q�@���j�۾�����F�A�]�����٦��S�����i���C
LONG
);
        set("exits",([
                "north" : __DIR__"map_12_15",
                //"east" : __DIR__"map_13_16",
        ]));
         set("detail",([
                "�۾�":"�@����p���۾��A�W�Y�S�g�줰��F�l�A���G�`���H�񪺼ˤl�C\n"
        ]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        ::init();
        add_action("do_push" , "push" );
}

int do_push(string arg)
{
        object me=this_player();
        if(!arg || arg!="�۾�")
                    return notify_fail("�A�n������H\n");
        if(me->is_busy())
               return notify_fail("�A�{�b�S���šC\n");
        message_vision("$N���}�۾����F�i�h...\n",me);
        tell_object( me , "�A���M�}�U�@�ӽ�šA���L�U�h��@�ӪŬ}�ޤF..\n" );
        me->move(__DIR__"down_maze1");
        tell_room(environment(me),"�P�q�@�n�A" + me->name()+"�q�W�Y�L�F�U��...\n",me);
        return 1;
}


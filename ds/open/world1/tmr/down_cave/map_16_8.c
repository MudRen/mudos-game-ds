inherit ROOM;
void create()
{
        set("short", "���D");
        set("long", @LONG
���D�q��F�o�̡A���M�N�Q�@���j�۾�����F�A�]�����٦��S�����i���C
LONG
);
        set("exits",([
                "north" : __DIR__"map_15_8",
                //"west" : __DIR__"map_16_7",
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
        message_vision("$N���}�F�۾����F�i�h...\n",me);
        me->move(__DIR__"map_16_7");
        tell_room(environment(me),me->name()+"���}�F�۾����F�L�ӡC\n",me);
        return 1;
}


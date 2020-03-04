inherit ROOM;
void create()
{
        set("short","�ۥx");
        set("long",@LONG
�o�̿��W���ۥx�A������M�N�b���e�A�o�Q����i�J����k�A�O�A
�P��Q������A�ۥx�W���ۤ@�ӥ۸O�A�ݨөM��񤣤ӷf�աA���ӬO���
�W�ߪ��A���a���𳺵M�j���D�`�A���O���b���a�N�ϧA�G�ۤ��w�A�F���M
�譱���O��񪺥۶��A�۶��W���ۤ@�өǩǪ��Y�W�C
LONG);

        set("item_desc", ([
        "�Y�W" : "�@�Ӥp�p�Y�_�Ӫ��W�l�A���G�i�H���ʥ�?\n",
        ]));
        set("objects",([
        __DIR__"gravestone" : 1 
        ]) );
  
        set("exits", ([
            "east" : __DIR__"zk21",
            "west" : __DIR__"zk20",   
        ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init()
{
        add_action("do_push","push"); 
}

int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="�Y�W")
        return notify_fail("�Q������r?�ݲM���b��\n");        
        set("exits/down",__DIR__"fodoor");
        message_vision("$N�N�Y�W����F�@�ǡA�a�W��{�X�F�@���X��\n",me);
        return 1;
}


void reset()
{
        object gravestone;
        gravestone = present("fong-evil gravestone", this_object());
        delete("exits/down");
        if( gravestone )
                if( gravestone->query_zombie() )
                        return;
        ::reset();
}










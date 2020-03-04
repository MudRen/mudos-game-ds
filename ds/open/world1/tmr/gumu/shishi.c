// shishi.c �۫�
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�۫�");
        set("long", @LONG
�o�O�@���۫ǡA�Ǥ��I�ۿO���C�۫ǩ_�p�A��H���ۡA�ਭ�N�ܤ�
�e���A�ǳ��S�G�A�������u�A�X�i�I��C�b�۫Ǩ��������@�u���j����
�U(bag) �A÷���j�۳U�f�Aįį�ӰʡA�����D�O����F��C
LONG );
        set("exits", ([
                "north" : __DIR__"mudao16",
        ]));
        set("item_desc", ([
                "bag": "�@�u�¥��U�A������įį�ӰʵۡA�����D���}(open bag)�|������F��H\n"
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_open", "open");
        add_action("do_zhua", "catch");
}

int do_open(string arg)
{
        object obj, me=this_player();
        if( !arg || arg != "bag" )
        {
        return notify_fail("�A�n���}����H\n");
        }
        if ( query("opened") ) {
                                write("���U�w�Q���}�F�C����ԣ�]�S���F�C\n");
                return 0;
        }
        message_vision("$N�����b�۫Ǩ��������_�@�u���U�A�Ѷ}���b�U�f��÷���A����U�l�@�ݡA���X�ӤT�u�³��C\n",me) ;
                set("opened", 1);
                
        obj=new(__DIR__"npc/maque");
        obj->move(this_object());
        obj=new(__DIR__"npc/maque");
        obj->move(this_object());
        obj=new(__DIR__"npc/maque");
        obj->move(this_object());
        return 1;
}

int do_zhua(string arg)
{
        object me=this_player();
        int sk;

        sk=(int)me->query_skill("dodge", 1);
        if( !arg || arg != "bird" ) return notify_fail("�A�n�줰��H\n");
        if( !objectp(present("maque bird", environment(me))))
                return notify_fail("�o���S���³��a�H\n");
        if( me->query("ap") < 30 )
                return notify_fail("�Aı�o�Ӳ֤F�A���p���|�a�H\n");
        if( me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ů��³��C\n");
        
        me->add_busy(1);
        me->receive_damage("ap", 5 + random(10));
        if ( sk < 10)  {
                me->improve_skill("dodge", 1);
        }
        if( random(sk) < random(30) )
        {
                message_vision("$N���L�h�N��C�i�O�³��F�K���`�A�F���輳�A$N��ݦS�S�A�ֱo���Y�j���A�O������A�s�Ф�]�I����@�ڡC\n", me);
                return 1;
        }
        
        message_vision("$N�����a�_�A����B�A���n�e��@�u�³��C\n", me);
        if ( sk < 10)  {
                me->improve_skill("dodge", random(me->query_dex()));
        }
        return 1;
}



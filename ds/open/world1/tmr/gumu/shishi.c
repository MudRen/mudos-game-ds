// shishi.c 石室
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "石室");
        set("long", @LONG
這是一間石室，室中點著燈火。石室奇小，兩人站著，轉身就很不
容易，室頂又矮，伸長手臂，幾可碰到。在石室角落里有一只不大的布
袋(bag) ，繩索綁著袋口，蠕蠕而動，不知道是什麼東西。
LONG );
        set("exits", ([
                "north" : __DIR__"mudao16",
        ]));
        set("item_desc", ([
                "bag": "一只舊布袋，里面還蠕蠕而動著，不知道打開(open bag)會有什麼東西？\n"
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
        return notify_fail("你要打開什麼？\n");
        }
        if ( query("opened") ) {
                                write("布袋已被打開了。里面啥也沒有了。\n");
                return 0;
        }
        message_vision("$N俯身在石室角落里提起一只布袋，解開縛在袋口的繩索，倒轉袋子一抖，飛出來三只麻雀。\n",me) ;
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
        if( !arg || arg != "bird" ) return notify_fail("你要抓什麼？\n");
        if( !objectp(present("maque bird", environment(me))))
                return notify_fail("這里沒有麻雀吧？\n");
        if( me->query("ap") < 30 )
                return notify_fail("你覺得太累了，不如歇會吧？\n");
        if( me->is_busy() )
                return notify_fail("你正忙著，沒有空捉麻雀。\n");
        
        me->add_busy(1);
        me->receive_damage("ap", 5 + random(10));
        if ( sk < 10)  {
                me->improve_skill("dodge", 1);
        }
        if( random(sk) < random(30) )
        {
                message_vision("$N撲過去就抓。可是麻雀靈便異常，東飛西撲，$N氣喘吁吁，累得滿頭大汗，別說捉到，連羽毛也碰不到一根。\n", me);
                return 1;
        }
        
        message_vision("$N輕輕縱起，伸手處，正好逮住一只麻雀。\n", me);
        if ( sk < 10)  {
                me->improve_skill("dodge", random(me->query_dex()));
        }
        return 1;
}



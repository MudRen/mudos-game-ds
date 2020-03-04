// cexiang.c 側廂
// Java Oct.10 1998
#include <ansi.h>
        
inherit ROOM;
void back(object me);
void init();
int do_sleep(string arg);

void create()
{
        set("short", "側廂");
        set("long", @LONG
這里是古墓中的側廂房。房間里面黑呼呼的，什麼東西都沒有，只
有一條細繩(rope)，在室東的一根鐵釘上系住，拉繩橫過室中，繩子的
另端系在西壁的一口釘上，繩索離地約莫一人來高。
LONG );

        set("exits", ([
                "west" : __DIR__"mudao14",
        ]));
        set("item_desc", ([
                "rope" : "一條細麻繩，看來是古墓弟子們睡眠之所。\n"
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        ::init();
        add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
        object room, *ob, me=this_player();
        int i, j;

        if( !(room = find_object(__DIR__"rope")) )
                room = load_object(__DIR__"rope");
        
        if( !arg || arg != "rope" )
        {
                return notify_fail("你要睡在哪兒？\n");
        }
        
        if(me->is_busy() )
                return notify_fail("你正忙著，沒有空做這件事。\n");
        
        if((int)me->query_skill("dodge",1) < 10)
        {
                message_vision("$N的基本輕功\不夠嫻熟，跳不上繩去。\n",me) ;
                return 1;
        }
        me->receive_damage("ap",10+ random(20));
        ob = all_inventory(room);
        j = 0;
        for(i=0; i<sizeof(ob); i++)
                if( living(ob[i]) && ob[i] != me ) j++;
        if (j > 0)
        {
                message_vision("$N輕輕縱起，發現繩上有人，只好飛身下地。\n",me);
                return 1;
        }
        message_vision("$N輕輕縱起，橫臥繩上，以繩為床，睡起覺來。\n", me);
        me->move(room) ;
        me->start_busy(3);
        call_out("back", 6 , me);
        return 1 ;
}

void back( object me )
{
        int sk;
        me->move(__DIR__"cexiang");
        message_vision("$N一覺醒來，飛身躍下繩來。\n",me);
        sk=me->query_skill("dodge",1);
        if (sk < 20)
        {
             me->improve_skill("dodge",me->query("int"));
                tell_object(me,HIC "你的基本輕功\進步了!\n" NOR);
        }
}


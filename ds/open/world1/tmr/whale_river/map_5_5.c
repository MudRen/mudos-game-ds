inherit ROOM;
void create()
{
          set("short", "河岸");
        set("long", @LONG
你站在河岸邊，往西邊望去是一片水藍藍的大湖，鳥叫聲充斥耳底
，成群魚兒不時望出水面，要是身上有根釣竿，倒也想在這兒享受
釣魚(fishing)的寧靜。
LONG
);
	set("exits",([
	"east" : __DIR__"map_5_6",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/fisher":2,
	__DIR__"npc/obj/rod":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_fishing","fishing");
}

int do_fishing(string arg)
{
        object me,rob;
        string type;
        
        me=this_player();
        rob = present("_OBJECT_ROD_", me);      // 判斷身上是否釣竿
        if( me->is_fighting() || me->is_busy() )
                                return notify_fail("你正忙著，沒有空釣魚。\n");
    if( !rob )  return  notify_fail("你並沒有釣竿，不知如何釣魚。\n");
    if( !(type = rob->query("equipped")) )
                                return notify_fail("你必須把釣竿拿在手裡，才能釣魚。\n");
        if( me->query_temp("whale_river/is_fishing") )
                                return notify_fail("你已經在釣魚了。\n");
        if( me->query_stat("gin") < 10)
                                return notify_fail("你的精神狀況不好，無法專心釣魚。\n");
        me->set_temp("whale_river/is_fishing",1);
        switch(random(3))
        {
        case 0:
                message_vision("$N用力把釣線甩到湖中央，一屁股坐在岸邊，開始等著魚上鉤...\n",me);
                break;
        case 1:
                message_vision("$N隨手從地上找了幾條蚯蚓當成魚餌，一甩釣線到湖中去，開始釣起魚來...\n",me);
                break;
        default:
                message_vision("$N把釣線理了理，綁上了幾塊饅頭屑，隨即甩了出去，開始釣起魚來...\n",me);
                break;
        }
        // 進入釣魚 function
        call_out("fishing_2",3+random(3),me);
        return 1;
}

void fishing_2(object me)
{
        object fish;
        /* 角色不存在 or 非釣魚狀態 */
        if(!me || !me->query_temp("whale_river/is_fishing") 
           || environment(me)!= this_object()       )

        {
                me->delete_temp("whale_river/is_fishing");
                return;
        }
        /* 角色忙碌中 or 角色戰鬥中 */
        if(me->is_busy() || me->is_fighting() )
        {
                message_vision("$N正忙著不得開支，只好放棄釣魚的動作了。\n",me);
                me->delete_temp("whale_river/is_fishing");
                return;
        }
        switch(me->query_temp("whale_river/is_fishing") )
        {
        case 1:         /*      中場休息        */
                switch(random(3) )
                {
                case 0:
                        message_vision("$N猛著一個「鳳點頭」，原來是釣魚釣到打嗑睡了....\n",me);
                        break;
                case 1:
                        message_vision("$N站起身來動了幾下手腳，又坐在岸邊，開始釣起魚來....\n",me);
                        break;
                default:
                        message_vision("$N發出一陣鬼吼鬼叫，看來是等魚上鉤等著不耐煩了....\n",me);
                        break;
                }
                me->add_temp("whale_river/is_fishing",1);
                call_out("fishing_2",3+random(3),me);
                break;
        case 2: // 釣到 or Not ?
                if(random(100) > 70) {
                        switch(random(3))
                        {
                        case 0:
                                message_vision("$N一扯手上的釣竿，才發現魚餌已經被吃光光了...\n",me);
                                break;
                        case 1:
                                message_vision("$N收回了釣線，結果一條魚都沒有釣到...\n",me);
                                break;
                        default:
                                message_vision("$N急急忙忙的收回釣線，結果魚兒一陣掙扎，逃脫去了...\n",me);
                                break;
                        }
                
                } else 
                {
                        message_vision("$N手中的釣線一緊，原來是魚兒上釣了！！\n",me);
                        fish=new(__DIR__"fishs/fish");
                        message_vision("$N好整以暇慢慢著收回釣線，最後釣上一條$n了...\n",me,fish);
                        if(!fish->move(me))
                                fish->move(environment(me));
                }
                me->delete_temp("whale_river/is_fishing");
        break;  
        }
}

int valid_leave(object ob)
{
        /*      角色離開，清除釣魚記錄  */
        ob->delete_temp("whale_river/is_fishing");
    return 1;
}


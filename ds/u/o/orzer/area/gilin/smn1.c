inherit ROOM;
void create()
{
        set("short","山崖上");
        set("long",@LONG
你跳上了山崖上，山崖上可以看到許多的風景，你發現山崖後方原
來還有一片森林，只是寒氣也特別濃厚，還有著詭異的吼聲，讓你不由
自主的猶豫起來要不要下去瞧瞧，山崖上面有著許多的大石頭。
LONG
        );
        set("exits", ([
  "down" : __DIR__"t27",
]));
        set("item_desc", ([
            "石頭" : "一個蠻大的石頭，看來非常穩固，也許\可以用什麼東西綁住(ties_up)它？\n",
         ]));  
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}


void init()
{
 add_action("do_ties_up","ties_up");
 add_action("do_slip","slip");
}


int do_ties_up(string arg)
{
        object me,obj,ob;
        ob=this_object();
        me=this_player();
        if(me->is_busy()) return notify_fail("你正忙著，沒空作其他事。\n");
        if(arg!="石頭" || !arg )
             return notify_fail("你要綁住什麼?\n");
        if(query("tiesup_rope"))
             return notify_fail("上面已經綁好麻繩了\n");         
        if(obj=present("rope",me))
        {
                              
                  message_vision("$N將$n牢牢的綁上了石頭上面。\n",me,obj);
                  destruct(obj);
                  set("item_desc", ([
                      "石頭" : "一個蠻大的石頭，看來很穩固，上面綁了麻繩也許\可以滑下(slip down)山崖。\n",
                      ]));
                  ob->set("tiesup_rope",1);  //設標記                 
                  return 1;
        }
         else
        {
                tell_object(me,"你身上沒有可以綁住的東西喔\n");
                return 1;
        }
}
 
int do_slip(string arg)
{        
        object me; 
        me=this_player();
        if (!query("tiesup_rope"))
        return 0;
        if (!arg || arg =="" || arg!="down")
        return notify_fail("你要滑到哪？\n");  
        if( me->is_busy() )
               return notify_fail("你還在忙！\n");
        message_vision("$N很勇敢的抓起麻繩往山崖下滑！",me); 
        if (me->query_dex() >= 50){  
        message_vision("，$N十分俐落的從山崖滑了下去\n",me);
        me->move(__DIR__"t29"); 
        tell_room(environment(me), "山崖上有人影下降，原來是"+me->name()+"從山崖上滑下來，姿勢輕靈！\n", ({ me }));
        return 1;
        } 
            message_vision("，$N一個不小心從山崖掉落了下去\n",me);
            me->receive_wound("left_leg",5+random(20));
            me->receive_wound("right_leg",5+random(20));
            me->receive_wound("left_arm",5+random(20));
            me->receive_wound("right_arm",5+random(20));
            me->receive_wound("head",5+random(20));
            me->receive_wound("body",5+random(20));             
             me->receive_damage("hp",me->query("hp")*1/3);
            me->move(__DIR__"t29.c");
           
            tell_room(environment(me), "砰的一聲，"+me->name()+"從山崖上掉了下來，看來受傷不淺！\n", ({ me }));            return 1;
}

void reset()
{
        set("item_desc", ([
            "石頭" : "一個蠻大的石頭，看來非常穩固，也許\可以用什麼東西綁住(ties_up)它？\n",
         ]));
        delete("tiesup_rope");       
        return ::reset();
}








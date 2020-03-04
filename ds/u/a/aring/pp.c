inherit ROOM;
int do_add(string arg);
int do_add2(string arg);
int do_add3(string arg);
int do_add4(string arg);
void create()
{
        set("short", "河邊小路");
        set("long", @LONG
你正走在河邊小路，沿途可看到不少村婦拿著木棒蹲在河邊槌打一些
衣物，也有不少釣客正在享受垂釣的樂趣。此河也被引用通到村外的農田
的溝渠，每當乾旱之時，此河的水卻仍泉湧不絕，堪稱一絕，你留意到河
邊的水裡有個不小的【黑洞】。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "northeast" : __DIR__"vroad3",
           ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_add","add");
        add_action("do_add2","add2");
        add_action("do_add3","add3");
        add_action("do_add4","add4");
}

int do_add(string arg)
{
          object me;
          me=this_player();
            me->add("exp", 1000000);
            me->add("mud_age", 251232);
            me->add("mks",1432);
            me->add("bank",1500000);
          
            return 1;
}


int do_add2(string arg)
{
          object me;
          me=this_player();
            message_vision("$N往黑洞的方向游了過去。\n",me);
            me->add("combat_exp", 5000);
            me->add("magic_exp", 250000);
                     
            return 1;
}

int do_add3(string arg)
{
          object me, ob, ob2;
          me=this_player();
          ob=this_object();
          ob2=this_object();
            
            ob = new("/obj/saveeq/small_luckbag");
            ob2 = new("/obj/saveeq/symbolbag");
            ob->move(me);
            ob2->move(me);         
            return 1;
}

int do_add4(string arg)
{
        object ob,ppl;
        int i;
        
        ppl = this_player();
                        for ( i=0;i<30;i++ )
                        {
                                ob = new("/obj/symbol/symbol_piece");
                                ob->do_setpiece();
                                ob->move(ppl);
                                message_vision("一片$N掉到$n身上!\n",ob,ppl);
                        }
               
                              return 1;
        }



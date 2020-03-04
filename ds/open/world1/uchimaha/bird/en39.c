inherit ROOM;
void create()
{
set("short","東北澤林");
set("long", @LONG
你終於走出了沼澤區, 你感覺到萬分的幸運, 這裡有
些高大的樹木和花朵, 你看到樹上有一個如頭顱般大的蜂
巢, 附近還有些虎頭蜂在徘徊.
LONG
        );
        set("exits",(["south":__DIR__"en38",
                      "northwest":__DIR__"en40",
               ]));
        
        set("item_desc",([
        "蜂巢":"這是一個有頭顱般大的蜂巢，如果你心情不好，你可以用力踢它兩腳(kickkick)。\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{ 
         add_action("do_kickkick","kickkick");
}
int do_kickkick(string arg)
{
          object me;
          me=this_player();
          if(arg != "蜂巢")
            return 0;
          else {
            message_vision("$N突然心情很不爽，想去踢蜂巢兩腳。\n\n",me);
            message_vision("$N用力的往蜂巢上踹了下去，當場蜂巢掉了下來，蜜蜂源源不絕的從蜂巢裡湧出。\n",me);
            message_vision("一大群蜜蜂往$N的身上亂戳，痛的$N哇哇大叫，頓時遍體鱗傷。\n",me);
            me->receive_wound("head",2);
            me->receive_wound("body",2);
            me->receive_wound("left_leg",2);
            me->receive_wound("right_leg",2);
            me->receive_wound("left_arm",2);
            me->receive_wound("right_arm",2);
            return 1;
          }
}


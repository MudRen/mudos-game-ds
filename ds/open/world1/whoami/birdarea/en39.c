#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIW"東北"NOR"澤林");
set("long", @LONG 
你終於走出了沼澤區, 你感覺到萬分的幸運, 這裡有些高大
的樹木和花朵, 你看到樹上有一個如頭顱般大的蜂巢, 附近還有
些虎頭蜂在徘徊.
LONG
        );
        set("exits",(["south":__DIR__"en38",
                      "northwest":__DIR__"en40",
               ]));
        
        set("item_desc",([
        "蜂巢":"這是一個有頭顱般大的蜂巢，把他摘下似乎可以賣到不錯的價錢•\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="south" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
void init()
{ 
         add_action("do_pick","pick");
}
int do_pick(string arg)
{
          object me;
          me=this_player(); 

        if (!arg || arg =="")
        return notify_fail("你要摘下什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
          if(arg != "蜂巢")
            return 0;
          else {
            message_vision("$N貪念一起，妄想把蜂巢摘下..\n\n",me);
            message_vision("當$N動手摘下蜂巢時，突然蜂巢掉了下來，蜜蜂源源不絕的從蜂巢裡湧出。\n",me);
            message_vision("一大群蜜蜂往$N的身上亂戳，痛的$N哇哇大叫，頓時遍體鱗傷。\n",me); 
            me->start_busy(3+random(3));            switch(random(100)){
            case 1..20:
            me->receive_wound("head",2+random(5));
            me->receive_wound("body",2+random(5));
            me->apply_condition("blooding", me->query_condition("blooding")+(random(3)+2));
            break;
            case 21..40:
            me->receive_wound("left_leg",2+random(5));
            me->receive_wound("right_leg",2+random(5)); 
            me->apply_condition("blooding", me->query_condition("blooding")+(random(3)+2));
            break;            case 41..60:
            me->receive_wound("left_arm",2+random(5));
            me->receive_wound("right_arm",2+random(5)); 
            me->apply_condition("blooding", me->query_condition("blooding")+(random(3)+2));
            break;
            case 61..80: 
            message_vision("\n$N"HIW"被蜜蜂刺到，臉色不太正常，看來是"MAG"中毒"HIW"了•\n"NOR,me);
            me->apply_condition("poison", me->query_condition("poison")+random(10));
            break;
            default:
            message_vision("\n$N"HIW"被蜜蜂刺到，臉色不太正常，看來是"MAG"中毒"HIW"了•\n"NOR,me);
            me->apply_condition("poison", me->query_condition("poison")+random(20));
            break;
            }
            return 1;
          }
}



#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"焦岩釣魚台"NOR);
        set("long", @LONG
你走進這裡，哇，有好多的人在這裡釣魚呀！不時的傳來興
奮的喊叫聲，這肯定又是有誰釣到了大魚，看到他們忙忙碌碌興
奮的樣子，你還有什麼值得猶豫的，趕快拿好你的魚杆開始釣魚
(hook)吧？
LONG );
        set("exits", ([
                  "out" :"/open/world1/wu_sha_town/seacoun42",
                ]));
        set("no_fight", 1);
        set("no_recall", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        
        add_action("do_hook", "hook");
}

int do_hook(string arg)
{

        object me,ob;
        me = this_player();
        ob=new("/obj/money/coin");

        if (me->query("exp") > 9999)
                return notify_fail("你的經驗滿滿 . . . 還是別釣魚吧！\n");
        else
                message_vision("$N吹著口哨拿著魚杆坐在大石頭上釣起魚來……。\n", me);
        if (me->is_busy())
                return notify_fail ("你的動作還沒完成！\n");

                switch(random(10)) {
                        case 0 :
                             message_vision("$N猛一提杆，釣到了一條"+ HIR "大鯉魚"NOR +"，恭喜，恭喜。 \n\n",me);
                               me->add("exp",20+random(10));
                             me->add("ap",-30);
                           break;
                        case 1 :
                             message_vision("$N猛一提杆，釣到了"+ CYN "一個破草帽"NOR +"，晦氣，晦氣。  \n",me);
                             message_vision(HIW "$N用力的踩了破草帽幾腳 ! ! !  \n\n" NOR,me);
                             me->add("ap",-50); 
                             me->add("exp",-220);                           break;
                       
 case 2 :
                             message_vision("$N看到魚漂晃動，$N內心一喜，猛的一提杆，$N釣到了"+ RED "一件紅色的小褲褲。 \n"NOR,me);
                             message_vision(HIB "$N連聲嘆氣：晦氣，晦氣。 \n\n" NOR,me);
                             me->add("ap",-40); 
                             me->add("exp",-200);                           break;
                        case 3 :
                             message_vision("$N一提杆，釣到了一條 "+ HIC "鯰魚"NOR +"，恭喜，恭喜。 \n\n",me);
         me->add("exp",20+random(10));
                             me->add("ap",-35);
                           break;
                        case 4 :
                  message_vision("$N一提杆，釣到了一條"+ HIG "鯽魚"NOR +"，恭喜，恭喜。 \n\n",me);
               me->add("exp",20+random(10));
                             me->add("ap",-35);
                           break;
                        case 5 :
                             message_vision("$N一提杆，釣到了一條"+HIY" 黃魚"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break; 
case 6 :
                             message_vision("$N一提杆，釣到了一條"+HIG" 錦魚"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 7 :
                             message_vision("$N一提杆，釣到了一條"+HIW" 白帶魚"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 8 :
                             message_vision("$N一提杆，釣到了一條"+HIR" 章魚"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 9 :
                             message_vision("$N一提杆，釣到了一條"+HIW" 吻仔魚(小條)"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 10 :
                             message_vision("$N一提杆，釣到了一條"+HIB" 鏝魚"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
                        case 11 :
                             message_vision("$N一提杆，釣到了一條"+ HIB "鱘魚"NOR +"，恭喜，恭喜。 \n\n",me);
me->add("exp",20+random(10));
                             me->add("ap",-35);
                           break;
                        case 12 :
                             message_vision("$N猛一提杆，釣到了"+ HIR "一隻死掉的龍蝦"NOR +"，晦氣，晦氣。 \n",me);
                             message_vision(HIW"$N用力的踩了死掉的龍蝦幾腳 ! ! ! \n\n"NOR,me);
                             me->add("ap",-50); 
                             me->add("exp",-300);                           break;
                          case 13 :
message_vision("$N魚漂晃動，$N心裡一急，猛的一提杆，$N釣到了"+ HIM "一個錢包! \n"NOR,me);
                             message_vision(HIW "$N見四周沒人注意，鬼鬼祟祟的打開錢包，想取出裡面的錢。沒想到竟然沒錢，使勁的丟回海裡！ \n\n" NOR,me);
                             me->add("ap",-50); 
                             me->add("exp",-200);                             ob->move(me);
                           break;
                           case 14 :
                             message_vision("$N猛的一提杆，扯的太急了，線斷了，魚跑了，可惜，可惜。 \n",me);
                             message_vision(HIC "$N不由的在心裡大罵:@#%%#X&。 \n\n" NOR,me);
                             me->add("ap",-35); 
                             me->add("exp",-100);                           break; 
case 15 :
                             message_vision("$N一提杆，釣到了一條"+HIW" 吻仔魚(大條)"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
case 16 :
                             message_vision("$N一提杆，釣到了一條"+HIW" 吻仔魚(不大不小 -.-#)"NOR +"，恭喜，恭喜。 \n\n",me);
            me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
                        default 
:
                             message_vision("$N一提杆，釣到了一條"+ HIC "娃娃魚"NOR +"，恭喜，恭喜。 \n\n",me);
me->add("exp",20+random(10));
                             me->add("ap",-40);
                           break;
                                 }
                         me->start_busy(2);

        return 1;
}


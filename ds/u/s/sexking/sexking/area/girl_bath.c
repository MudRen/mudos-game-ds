#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIC"大浴池裡"NOR" ");
        set("long", @LONG
你已經進到大浴池裡面了，這裡濃霧陣陣，四周香噴噴的，但由於
水的溫度很高你一時無法適應因此還不敢將全身泡(suds)進去，還
是等你適應水溫後，在將全身泡(suds)進去享受泡澡之樂吧。
LONG
        );
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clean_up", 0);
      setup();
}
void init()
{
        add_action("do_suds","suds");
        add_action("do_up","up");
}

int do_suds()
{
        object me;
        me=this_player();
       if( me->query_temp("suds") <= 0 )
        {
                write("如果想在享受一次泡澡的滋味的話請出去再付一次帳吧！\n");
                return 1;
        }
        if(me->query_temp("is_busy/sudsing"))
        {
                write("妳泡澡實在太舒服了，已不想做其它事了。\n");
                return 1;
        }
    
        message_vision(HIW "妳快快樂樂的跑向大浴池旁將腳伸了進去。\n" NOR, me);
        tell_object(me, HIR "起初妳感到很燙但妳慢慢的適應了.....\n" NOR );
        tell_object(me, HIB "妳將身子全放到浴池裡，感到無比的舒適感...\n" NOR );
        me->disable_player_cmds("妳泡澡實在太舒服了，已不想做其它事了。\n");
        me->set_temp("is_busy/sudsing","妳泡澡實在太舒服了，已不想做其它事了。");
        me->start_busy(10);
        call_out("suds1",3,me);
        call_out("suds2",8,me);
        call_out("sudsup",15,me);

return 1;
}

void suds1(object me)
{
        if(!me) return;
    tell_object(me,HIY"由於實在是太舒服了..，妳忍不住兩手放在兩旁扶手，上閉上了眼....\n"NOR);
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("ap",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void suds2(object me)
{
        if(!me) return;
        tell_object(me,HIG"不知不覺中妳已進入了快樂無比的世界...妳漸漸睡著了...\n"NOR);
me->receive_heal("hp",me->query_con()*6);
        return;
}

void sudsup(object me)
{
        if(!me) return;
        message_vision(HIW"$N突然睜開眼睛，似乎很滿足的樣子，正準備站(up)起來離開浴池。\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sudsing");
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        me->add_temp("suds",-1);
        return;
}
int do_up()
{
        object me;
        me=this_player();
        if( me->is_busy() )
        return notify_fail("妳還在忙不能站起來...\n");
        message_vision("$N從浴池站了起來..一付滿足的樣子。\n",me);
        me->start_busy(2);
        me->move(__DIR__"boy_suds");

    return 1;
}


#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "客房");
        set("long", @LONG
這是寒冰客棧的客房，裡面擺了好幾張的寒冰床，這是本客棧的
最大特色，你可以找的順眼的寒冰床去休息，床的前面都會立一張牌
子，上面都會教你怎麼練功回氣，其實不教，大家也應該會吧 !(qk) 
LONG
        );
        set("exits", ([
  "out" : __DIR__"hotel.c",
]));
        set("light", 1);
        set("no_clean_up", 0);  
        set("no_fight", 0); 
        set("valid_startroom", 1);
        setup();
}

void init()
{
        add_action("do_qk","qk");
}

int do_qk()
{
        object me;
        me=this_player();
        if( me->query_temp("qk") <= 0 )
        {
                write("你休息的次數沒嚕 ~ ~！\n");
                return 1;
        }
        if(me->query_temp("is_busy/qking"))
        {
                write("你正在睡覺。\n");
                return 1;
        }
        message_vision(HIW "$N找了一張順眼的[36m寒冰床[0m，跳到上面去休息了∼\n\n" NOR,me);
        tell_object(me, HIC "你運起內功\，化寒冰之氣為內力.....\n\n\n\n" NOR );
        tell_object(me, HIR "你的屁股似乎凍傷了..... :)\n\n\n" NOR );
        me->disable_player_cmds("你正在休息。\n");
        me->set_temp("is_busy/qking","你正在休息。");
        me->start_busy(5);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
    tell_object(me,HIG"你將二脈之氣漸漸回穩，準備收功\∼\n"NOR);
        me->receive_heal("hp",me->query_con()*1);
        me->receive_heal("ap",me->query_con()*3);
        me->receive_heal("mp",me->query_int()*2);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIG"你的雙手左右的劃了幾圈，眼皮一開，精神恢復了不少\n"NOR);
        me->receive_heal("hp",me->query_con()*3);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIB"$N提吸一口氣，伸個懶腰，從[36m寒冰床[0m上走了下來[33m。[0m\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/qking");
        me->receive_heal("hp",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*1);
        me->receive_heal("ap",me->query_con()*10);
        me->add_temp("qk",-1);
        return;
}


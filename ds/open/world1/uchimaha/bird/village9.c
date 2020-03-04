#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小棧亭二樓");
        set("long", @LONG
你現在站在小棧亭的樓上, 在這裡只有幾張床和兩
張窗戶, 你可以到床上去睡覺(sleep)。
LONG
        );
        set("exits", ([
  "down" : __DIR__"village8.c",
]));
        set("light", 1);
        set("no_fight", 1);
        set("no_cast", 1);
        set("no_exert", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
}
void init()
{
        add_action("do_sleep","sleep");
}

int do_sleep()
{
        object me;
        me=this_player();
        if( me->query_temp("sleep") <= 0 )
        {
                write("你所能休息的次數已用光了！\n");
                return 1;
        }
        if(me->query_temp("is_busy/sleeping"))
        {
                write("你正在睡覺。\n");
                return 1;
        }
        message_vision(HIG "$N揉了揉眼睛，眼皮似乎被瞌睡蟲給找上了，忍不住往床上一躺∼\n\n" NOR, me);
        tell_object(me, HIG "眼睛一閉，隨即就在香軟錦美的床上睡著了.....\n\n" NOR );
        tell_object(me, HIB "ｚＺｚＺＺＺｚＺＺＺＺＺｚｚＺＺｚ\n\n\n" NOR );
 me->disable_player_cmds("你正在睡覺。\n");
        me->set_temp("is_busy/sleeping","你正在睡覺。");
        me->start_busy(10);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
        tell_object(me,HIY"你漸漸進入了夢鄉，見到了你心愛的皮卡丘∼:>\n"NOR);
        me->receive_heal("hp",me->query_con()*4);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIB"你什麼也不想了，眼前一黑，沉沉的睡了下去∼∼ｚｚｚ\n"NOR);
 me->receive_heal("hp",me->query_con()*5);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIG"$N突然被旁邊的小二的敲門聲給吵醒，揉了揉眼睛醒了過來。\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sleeping");
        me->receive_heal("hp",me->query_con()*7);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        me->add_temp("sleep",-1);
        return;
}

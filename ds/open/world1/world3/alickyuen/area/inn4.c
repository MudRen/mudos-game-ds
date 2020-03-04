// Room: /u/a/alickyuen/area/inn4.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ST．SOFT＠Sleepingroom");
	set("long", @LONG
這裡是這間旅館的客房，你從窗口看出去，看到一片美麗景色，這裡
還有一張床（ｂｅｄ），你可以睡在這張床上休息。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"inn2",
]));
set("light",1);
set("no_exert",1);
set("no_cast",1);
set("no_fight",1);
set("no_kill",1);
	set("world", "future");
	set("no_clean_up", 0);

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
        if( me->query_temp("pushpass") <= 0 )
        {
                write("你所能休息的次數已用光了！\n");
                return 1;
        }
        if(me->query_temp("sleeping"))
        {
                write("你正在睡覺。\n");
                return 1;
        }
        message_vision(HIW "$N一下跳到床上，就朦頭大睡∼\n\n" NOR, me);
       // tell_object(me, HIW "眼睛一閉，隨即就在香軟錦美的床上睡著了.....\n\n" NOR );
       // tell_object(me, HIB "ｚＺｚＺＺＺｚＺＺＺＺＺｚｚＺＺｚ\n\n\n" NOR );

        me->disable_player_cmds("你正在睡覺。\n");
        me->set_temp("sleeping","你正在睡覺。");
        me->start_busy(10);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
        call_out("wakeup",15,me);
        return 1;
}

void sleep1(object me)
{
        if(!me) return;
 //       tell_object(me,HIG"你漸漸進入了夢鄉，見到了你懷念以久的小豬頭∼\n"NOR);
        me->receive_heal("hp",me->query_con()*4);
        me->receive_heal("ap",me->query_con()*2);
        me->receive_heal("mp",me->query_int()*3);
        return;
}
void sleep2(object me)
{
        if(!me) return;
  //      tell_object(me,HIB"你什麼也不想了，眼前一黑，沉沉的睡了下去∼∼ｚｚｚ\n"NOR);
        me->receive_heal("hp",me->query_con()*5);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        message_vision(HIW"$N突然被旁邊的小鬧鐘吵醒了，醒了過來。\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("sleeping");
me->delete_temp("pushpass");
        me->receive_heal("hp",me->query_con()*7);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
//        me->add_temp("sleep",-1);
        return;
}
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", " "HIC"抓狂之間"NOR" ");
        set("long", @LONG
這裡是sexking抓狂到累的時後所休息的地方,
當然如果你也想試試看抓狂的體驗...就睡(sleep)
在這看看吧..地板有很多地方給你睡ㄛ。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"workroom3",
        ]));
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
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
        message_vision(HIW "$N將衣服拖光光跳到了抓狂塌塌米的上面...。\n" NOR, me);
        message_vision(HIC "$N感到全身冰冰涼涼的很舒服...\n" NOR, me);
        message_vision(HIR "$N突然發現自己開始抓狂...但抓狂的感覺真好...\n" NOR, me);
        me->start_busy(8);
        call_out("sleep1",3,me);
        call_out("sleep2",8,me);
       call_out("sleepup",15,me);

return 1;
}

void sleep1(object me)
{
        if(!me) return;
    tell_object(me,HIY"你抓狂了一陣子後累了...於是你將身體扭曲成一個抓狂的模樣，閉上了眼....\n"NOR);
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("ap",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        return;
}

void sleep2(object me)
{
        if(!me) return;
        tell_object(me,HIG"接著你就開始抓狂的做著抓狂的夢.......\n"NOR);
me->receive_heal("hp",me->query_con()*6);
        return;
}

void sleepup(object me)
{
        if(!me) return;
        message_vision(HIW"$N漸漸的睜開眼睛...只見$N口水流的滿臉都是..好好笑。\n" NOR,me);
        me->enable_player_cmds();
        me->delete_temp("is_busy/sleeping");
        me->receive_heal("hp",me->query_con()*6);
        me->receive_heal("mp",me->query_int()*3);
        me->receive_heal("ap",me->query_con()*3);
        return;
}


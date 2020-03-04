#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "法院");
        set("long", "？？？？？？");
        set("objects", ([
                __DIR__"judge":1,
]));
        set("exits", ([
                "down":        "/open/world1/tmr/area/hotel.c",
        ]) );
        set("light",1);
        setup();
}
void init()
{
        add_action("do_cmds","");
        add_action("do_list","list");
}
int do_list()
{
        write("\n\n

顏色代碼列表：

                "HIG"█"NOR"：g\t\t"HIY"█"NOR"：y\n
                "HIR"█"NOR"：r\t\t"HIM"█"NOR"：m\n
                "HIW"█"NOR"：w\t\t"HIC"█"NOR"：c\n
                "HIB"█"NOR"：b\n

回答時請輸入 answer <數字+顏色> (EX：answer 12345b)

\n\n");
        return 1;
}
int do_cmds(string arg)
{
        object me = this_player();

        if(wizardp(me)) return 0;
        if(userp(me) && present("ice judge", this_object()))
        {
                if((string)query_verb() == "i"  || (string)query_verb() == "say"
                || (string)query_verb() == "l"  || (string)query_verb() == "look"
                || (string)query_verb() == "sc" || (string)query_verb() == "quit"
                || (string)query_verb() == "hp" || (string)query_verb() == "answer"
                || (string)query_verb() == "sk" || (string)query_verb() == "inventory")
                return 0;
                else
                {
                        write(HIC"冰判官冷冷的說道：你想幹啥？別輕舉妄動喔！\n"NOR);
                        return 1;
                }
        }
        else return 0;
}
void test_me(object me)
{
        me->set_temp("old_starroom", me->query("valid_startroom"));
        me->set("valid_startroom", __FILE__);
        me->set_temp("last_location", base_name(environment(me)));
        message_vision("忽然一陣閃光罩住了$N。\n", me);
        me->move(this_object());
}


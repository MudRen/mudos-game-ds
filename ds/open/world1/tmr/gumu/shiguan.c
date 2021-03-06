// Room: /d/gumu/shiguan.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIB"石棺內"NOR);
        set("long", @LONG
棺蓋內側似乎寫得有字，凝目瞧去，果見是十六個大字：「玉女心
經，技壓全真。重陽一生，不弱于人。」這十六個字以濃墨所書，筆力
蒼勁，字體甚大。其時棺蓋只推開了一半，但斜眼看去，仍是清清楚楚。
LONG    );
        set("exits", ([ 
                "out" : __DIR__"lingshi",
        ]));
        set("no_clean_up", 0);
        set("no_fight",1);
        setup();
}

void init()
{
        add_action("do_dian", "use");
        add_action("do_turn", "turn");
        add_action("do_ti", "pull");
        add_action("do_search","search");
}

int do_dian(string arg)
{
        object ob,me=this_player();

        if ( arg == "fire")
        {
                if(!objectp(ob = present("fire", me)))
                        return notify_fail("你沒有火折，點什麼？\n");
                message_vision(HIR"只聽見“呲 ---”的一聲，$N點亮了手中的火折。\n\n"NOR,me);
                        write(HIY"再看那十六個字時，只見其後還寫得有許\多小字：破解玉女心經之法，吾置之于此室之下，後人有緣，一觀便知 ......重陽真人 .....\n"NOR);

                me->set_temp("marks/古墓1", 1);
                return 1;
        }
        return 0;
}

int do_search()
{
        object me = this_player();

        if (!me->query_temp("marks/古墓1")) return 0;
        if (me->query_temp("tomb_search") < 8)
        {
                message_vision(HIY"$N點亮火折，仔細地在石棺內四下摸索。\n"NOR,me);
                me->add_temp("tomb_search",1);
                return 1;
        }
        message_vision(HIR"$N覺得手下一沉，果然摸到個可容一手的凹(ao)處，不知道是否可以轉動(turn)。\n"NOR,me);
        me->delete_temp("marks/古墓1");
        me->delete_temp("tomb_search");
        me->set_temp("marks/古墓2", 2);
        return 1;
}

int do_turn(string arg)
{
        object me=this_player();
        string dir;
        if (!me->query_temp("marks/古墓2")) return 0;
        if (!arg||arg=="") return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        if( arg=="ao" )
        {
                write("你要把凹處往哪里轉？\n");
        }
        if( sscanf(arg, "ao %s", dir)==1 )
        {
                if( dir=="left")
                {
                        message_vision(HIG"$N將凹處往左轉動幾下，果然有些鬆動，你或許\會想要把它提(pull)起來看看。\n"NOR, me);
                        me->delete_temp("marks/古墓2");
                        me->set_temp("marks/古墓3", 1);
                }
                else
                        message_vision(CYN"$N將凹處胡亂轉了幾下，結果什麼也沒發生。\n"NOR, me);
        }
        return 1;
}

int do_ti(string arg)
{
        object me =this_player();

        if (!me->query_temp("marks/古墓3")) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");
        if ( arg =="up")
        {
                message_vision(YEL "$N緊緊握住了凹處向上一提，只聽喀喇一響，棺底石板應手而起，$N猝不及防，翻身跌入下層石室。\n"NOR,me);
                me->delete_temp("marks/古墓3");
                me->move(__DIR__"shishi6");
                return 1;
        }
        return notify_fail("你往哪里提？\n");
}


// Room: /d/gumu/woshi1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",HIC"小臥室"NOR);
        set("long", @LONG
這里是楊過當年的臥室，房中空空洞洞。一塊長條青石作床，床上
鋪了張草席，一幅白布當作薄被，此外除了一根人高的繩索橫過室中，
別無他物。
LONG    );
        set("exits", ([
                "west" : __DIR__"mudao20",
        ]));
        set("objects", ([
                __DIR__"obj/bed" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_zuo", "sleep");
}

int do_zuo(string arg)
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著哪！\n");

        if (arg == "bed" )
        {
                if( me->query_skill("force", 1) < 10)
                {
                        message_vision("$N現在的內功\承受不住寒玉床的寒冰之氣。\n", me);
                        me->start_busy(1);
                        return 1;
                }

                if( me->query("hp") < 50
                || me->query("ap") < 50
                || me->query("mp") < 50 )
                {
                        message_vision("$N現在的身體無法承受不住寒玉床的寒冰之氣。\n", me);
                        me->start_busy(1);
                        return 1;
                }

                 message_vision("$N躺上了寒玉床，開始潛運內功\，使內息遍行大小周天。\n", me);
                 me->receive_damage("ap", 50 );
                 me->receive_damage("hp", 50 );
                 me->receive_damage("mp", 50 );
                 if (random(10) > 2)
                 {
                        message_vision(HIC"$N調息完畢，只覺得精神健旺，渾身充滿勁力。\n"NOR, me);
                        if( me->query_condition("blooding") && random(3) ) {
                                message_vision(HIW"$N身上流血的傷口，竟然奇跡式地快速癒合了。\n"NOR, me);
                                me->apply_condition("blooding", 1);
                        }
                        me->receive_curing("all", 2 );
                  } else
                        message_vision(CYN"$N躺上寒玉床，只覺得冰冷刺骨，「啊」的一聲狼狽不堪地跳了起來。\n"NOR, me);
                me->start_busy(4);
                return 1;
        }
        
        return notify_fail("你要坐在哪里？\n");
}


#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
     set_name(HBK"無寧冥卒"NOR, ({ "obscure solider", "soldier", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
這是一位守護莊園的冥卒，身形高瘦，臉色蒼白不似人樣，一張口竟然
隱隱吐出腥黑色的氣體，中人欲嘔。
LONG);

    set("age", 500);
    set("level",42+random(5));
    set("race","celestial");
    set("attitude", "aggressive");
        set("title",HIG"無寧莊園"NOR);
    /* 人物動作 */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),        
    }) );
    setup();
      set_temp("apply/armor", 150);
    set_temp("apply/damage",100);
    set_temp("apply/hit", 100);
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 50 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 50 ) carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/blood_meat");
        carry_object(__DIR__"obj/yellow-skin")->wear();
        carry_object(__DIR__"obj/obscure-pike")->wield();
}


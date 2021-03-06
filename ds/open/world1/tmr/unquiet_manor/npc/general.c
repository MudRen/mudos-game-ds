#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name(HIC"無寧將軍"NOR, ({ "obscure general", "general", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
無寧將軍是統領無寧莊園的主要人物，擁有一身橫練功夫，加上
精明果斷，尋常人等根本就不配做為其對手。無寧將軍長的孔武威猛
，脖子上有條繞頸而過的刀疤，一呼一吸之間刀疤也在蠢蠢欲動。
LONG);

    set("age", 500);
    set("level",50+random(5));
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
      (: do_fight_help :),
    }) );
    setup();
      set_temp("apply/armor", 150);
    set_temp("apply/damage", 200);
    set_temp("apply/hit", 100);

    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 80 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 80 ) carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/blood_meat");
        carry_object(__DIR__"obj/yellow-skin")->wear();
        carry_object(__DIR__"obj/obscure-pike")->wield();
}


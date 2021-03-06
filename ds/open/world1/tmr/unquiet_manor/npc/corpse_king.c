#include <ansi2.h>
#include <skill.h>

inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
     set_name(HIR "無寧屍仙" NOR, ({ "unquiet corpse-king", "king", "corpse", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
無寧屍仙是無寧莊園的主人，存在有八百年了，沒有人知道他的來歷。
你無法看清楚無寧屍仙的面貌，待看仔細點這才發現屍仙原來不只是一具屍
身，而是屍身被一群不知名的鬼蟲控制著，鬼蟲密密麻麻地爬滿屍身，還不
時滲出血水。
LONG);

    set("title", HIC"無寧莊園"NOR);
      set("race", "celestial");
    set("age", 800);
    set("level",60 );
    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),
      (: do_fight_help :),
    }) );
    set("attitude", "aggressive");
    set("max_hp", 40000);

    setup();
      set_temp("apply/armor", 500);
      set_temp("apply/hit", 300);
    set_temp("apply/damage",300);
    set_temp("apply/shield",300);
    set_living_name("_UNQUIET_MANOR_NPC_");
    set_temp("apply/bar", 10);
    set_temp("apply/wit", 3);   
    
    carry_object(__DIR__"obj/q_plate");
    carry_object(__DIR__"obj/q_plate");
    carry_object(__DIR__"obj/q_plate");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/yellow-skin")->wear();
        carry_object(__DIR__"obj/pagoda-claw.c")->wield();
        if(random(100)<5)
                carry_object(__DIR__"obj/unquiet-ring")->wear();
        else
                carry_object(__DIR__"obj/unquiet-ring2")->wear();
}

void die()
{
       object ob;

        if( this_object()->query("pill") < 2 ) {
            message_vision(HIR"$N"HIR"屍身上暴射出數道血雨，良久方停，無寧屍仙又站了起來。\n"NOR, this_object());
            set("hp", this_object()->query("max_hp"));
            add("pill", 1);
            return;
        }


        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        message("world:world1:vision",
           HIR"\n【奧特蘭克】"+HIG"戰場英雄《"+ob->name(1)+"(" + ob->query("id") + ")》費盡九牛二虎之力，終於完全誅滅掉無寧屍仙了！！\n\n" NOR
        ,users() );
        ob->add("popularity", 4);
        tell_object(ob,HIG"你獲得４點聲望。\n"NOR);

        ::die();

        return;
}


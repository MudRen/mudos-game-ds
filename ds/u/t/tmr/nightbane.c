#include <ansi2.h>
#include <skill.h>

inherit NPC;

void create()
{
     set_name(HBK "骨龍 "HIR"夜禍" NOR, ({ "nightbane dragon", "nightbane", "dragon", "_BLOOD_FIELD_NPC_" }) );
    set("long", @LONG
無寧屍仙是無寧莊園的主人，存在有八百年了，沒有人知道他的來歷。
你無法看清楚無寧屍仙的面貌，待看仔細點這才發現屍仙原來不只是一具屍
身，而是屍身被一群不知名的鬼蟲控制著，鬼蟲密密麻麻地爬滿屍身，還不
時滲出血水。
LONG);

    set("title", HIM"血腥領主"NOR);
      set("race", "celestial");
    set("age", 800);
    set("level",60 );
    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
//      (: do_fight_issue :),
//      (: do_fight_help :),
    }) );
    set("attitude", "aggressive");
    setup();
        set("hp",30000);
        set("max_hp",30000);
      set_temp("apply/armor", 500);
      set_temp("apply/hit", 300);
    set_temp("apply/damage",300);
    set_temp("apply/shield",300);
    set_living_name("_UNQUIET_MANOR_NPC_");
    set_temp("apply/bar", 10);
    set_temp("apply/wit", 3);   
    

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
           HIR"\n【奧特蘭克】"+name()+HIG"在臨死之際發出怒吼，隨即被"+HIG"戰場英雄《"+ob->name(1)+"(" + ob->query("id") + ")》催毀到灰飛煙滅，形體不再！！\n\n" NOR
        ,users() );
        ob->add("popularity", 4);
        tell_object(ob,HIG"你獲得４點聲望。\n"NOR);

        ::die();

        return;
}



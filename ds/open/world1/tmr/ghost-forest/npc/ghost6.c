#include <ansi.h>

inherit NPC;
inherit __DIR__"ghost-forest";

void create()
{
        set_name(CYN "形鬼" NOR ,({"sing ghost","ghost"}) );
        set("long",@LONG
形鬼看來瘦骨嶙峋，弱不禁風之樣，雙眼透露著綠光，粗重的呼吸顯
示它沉重的殺意。形鬼為鬼王　無妄座下十二鬼將排名第六，擅用長槍，
招招奪人性命。
LONG
);
        set("age",60);
        set("race","人類");
        set("title","鬼眾");
        set("level",28);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
                (: ghost_heal,this_object() :),
        }) );



        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",80);
        set_skill("fork",110);
        setup();
    carry_object(__DIR__"wp/pike")->wield();
       set_living_name("ghost-forest-war-ghost");
}

void init()
{
        ::init();

if(this_player()->query("level") > 20 && userp(this_player() ) && this_object()->visible(this_player()))
        {
        message_vision("\n$N"+NOR+"狂喝一聲，開始攻擊$n！！\n" NOR,this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
}
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }

        ob->add("ghost_forest_war",1);
          if(ob->query("ghost_forest_war") > 2 )
        {
                tell_object(ob,HIG"你得到一點聲望。\n" NOR);
                ob->add("popularity",1); //聲望
                ob->set("ghost_forest_war",0);
        }
        ::die();
        return;
}


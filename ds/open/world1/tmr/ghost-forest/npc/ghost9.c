#include <ansi.h>

inherit NPC;
inherit __DIR__"ghost-forest";

void create()
{
        set_name(CYN "影鬼" NOR ,({"shadow ghost","ghost"}) );
        set("long",@LONG
影鬼看來肌肉橫張，身長八尺有餘，兩眼透露著紅光，粗重的呼吸顯
示它沉重的殺意。影鬼為鬼王　無妄座下十二鬼將排名第九，擅用巨斧，
力可開山劈石。
LONG
);
        set("age",60);
        set("race","人類");
        set("title","鬼眾");
        set("level",25);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
                (: ghost_heal,this_object() :),
        }) );


        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",80);
        set_skill("axe",110);
        setup();
    carry_object(__DIR__"wp/axe")->wield();
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


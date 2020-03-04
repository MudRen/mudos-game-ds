#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "屍妖" NOR ,({"corpse demon","demon"}) );
        set("long",@LONG
屍妖是由屍氣所聚集而成，因此需要大量屍體維生，所以常在墓地行
動，後來敗給殭屍王　戾絕，便加入屍軍，其十分嗜殺，常常一值渴
望有大量屍體使其力量加強。
LONG
);
        set("age",60);
        set("race","beast");
        set("unit","隻");
        set("title","屍將");
        set("level",35);
        set("str",90);
        set("attitude", "peaceful");
        add("addition_armor",100);
        set("gender", "雄性" );
        set("chat_chance",5);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
                (: zombie_heal,this_object() :),
                (: zombie_bite,this_object() :), 
        }));                 
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",100);
        setup();
       carry_object(__DIR__"../eq/demon_waist")->wear();
       set_living_name("zombie-war-mob");
       set("actions", (: call_other, __FILE__, "query_action" :));
}

 mapping query_action()
{
        return s_action[random(sizeof(s_action))];
}
void init()
{
        ::init();

if(this_player()->query("level") > 20 && userp(this_player() ) && this_object()->visible(this_player()))
        {
    message_vision("\n$N"+NOR+"一看到$n便立刻發出攻擊！！\n" NOR,this_object(),this_player() );
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

        ob->add("zombie_kill_war",1);
          if(ob->query("zombie_kill_war") > 2 )
        {
                tell_object(ob,HIG"你得到一點聲望。\n" NOR);
                ob->add("popularity",1); //聲望
                ob->set("zombie_kill_war",0);
        }
        ::die();
        return;
}








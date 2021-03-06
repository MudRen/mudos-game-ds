#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "成谷", ({ "cheng gu","cheng","gu" }) );
        set("level",30);
        set_skill("dodge",65);
        set_skill("parry",65);
        set_skill("sword",70);
        set("long" ,"他是掌管朝廷禁軍的副將，也是大將軍成陸之弟，他\n"
                    "跟隨成陸南爭北討，為皇上打下不少江山，亦得皇上\n"
                    "的賞識才有今日之地位。\n"
           );
        set("chat_chance", 10);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("sky_city_war", 1);
        set("age",47);
        set("title",HIG"禁軍"+HIR+"副將"NOR);
        setup();
        set_living_name("skycitywar");
        carry_object(__DIR__"wp/sword")->wield();
        carry_object(__DIR__"eq/surcoat")->wear();
}
void init()
{
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 9 && userp(this_player()) )
        {
          this_object()->kill_ob(this_player());
        }
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        i=ob->query_temp("skycitywar");
        ob->set_temp("skycitywar",i+2);
        if(ob->query_temp("skycitywar")>2) 
        {
          ob->add("popularity",1); //聲望
          tell_object(ob,HIW"(因為你殺死了成谷，所以你得到了 1 點聲望。)\n"NOR);
          ob->delete_temp("skycitywar");
        }
        ::die();
        return;
}

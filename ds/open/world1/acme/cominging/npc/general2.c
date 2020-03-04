#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "裨將", ({ "bi general","bi","general" }) );
        set("level",28);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("sword",70);
        set("long" ,"他是在禁軍裡官階為中低的將士。\n");
        set("age",45);
        set("title",HIG"禁軍"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("sky_city_war", 1);
        setup();
        set_living_name("skycitywar");
        carry_object(__DIR__"wp/sword")->wield();
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
        ob->set_temp("skycitywar",i+1);
        if(ob->query_temp("skycitywar")>2) 
        {
          ob->add("popularity",1); //聲望
          tell_object(ob,HIW"(因為你殺死了裨將，所以你得到了 1 點聲望。)\n"NOR);
        }
        ::die();
        return;
}

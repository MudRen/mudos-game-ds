#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIG"凌"HIW"魂"NOR, ({ "lin soul"}) );
        set("level",40);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("fork",100); 
        set_skill("unarmed",100);  
        set("long" ,"九天雲魂的大總管。\n");
        set("age",350);
        set("title",HIR"九天雲魂"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: command("wield pike") :),  
        (: command("wield pike") :), 
        }));
        setup();
        set_living_name("westwar");
        carry_object(__DIR__"pike")->wield();
}
void init()
{
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 1 && userp(this_player()) )
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
        i=ob->query_temp("westwar");
        ob->set_temp("westwar",i+1);
        if(ob->query_temp("westwar")>2) 
        {
          ob->add("popularity",1); 
          tell_object(ob,HIW"(你得到 2 點聲望。)\n"NOR);
          ob->delete_temp("westwar");
        }
        ::die();
        return;
}


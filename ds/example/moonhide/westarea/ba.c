#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIG"�Q"HIW"��"NOR, ({ "ba soul"}) );
        set("level",42);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("sword",100); 
        set_skill("unarmed",100);          set("long" ,"�E�Ѷ���Y�Y�C\n");
        set("age",400);
        set("title",HIR"�E�Ѷ���"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: command("wield sword") :),  
        (: command("wield sword") :),        }));         setup();
        set_living_name("westwar");
        carry_object(__DIR__"sword")->wield();
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
          tell_object(ob,HIW"(�A�o�� 3 �I�n��C)\n"NOR);
          ob->delete_temp("westwar");
        }
        ::die();
        return;
}


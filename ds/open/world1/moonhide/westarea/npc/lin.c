#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC"���"NOR, ({ "lin soul", "soul"}) );
        set("level",40);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("fork",100); 
        set_skill("unarmed",100);  
        set("long" ,"�E�Ѷ���j�`�ޡC\n");
        set("attitude", "aggressive");
        set("age",350);
        set("title",HIR"�E�Ѷ���"NOR);
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
        carry_object(__DIR__"obj/pike")->wield();
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
          ob->add("popularity",2); 
          tell_object(ob,HIW"(�A�o�� 2 �I�n��C)\n"NOR);
          ob->delete_temp("westwar");
        }
        ::die();
        return;
}

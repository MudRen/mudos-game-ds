#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "����", ({ "cheng lu","cheng","lu" }) );
        set("level",35);
        set_skill("dodge",75);
        set_skill("parry",75);
        set_skill("sword",80);
        set("long" ,"�L�O�x�޴§ʸT�x���j�N�x�A�j�p�ԧг��O�ѥL���U���A\n"
                    "��ة_�\\�B�`�o�ӤW�����ѡA�G��W�F�j�N�x�@¾�C\n"
           );
        set("age",49);
        set("title",HIG"�T�x"+HIR+"�j�N�x"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
            (: random_move :),
        }) );
        set("sky_city_war", 1);
        setup();
        set_living_name("skycitywar");
        carry_object(__DIR__"wp/sword")->wield();
        carry_object(__DIR__"eq/armor")->wear();
        carry_object(__DIR__"eq/surcoat")->wear();
        carry_object(__DIR__"eq/boots")->wear();
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
          ob->add("popularity",1); //�n��
          tell_object(ob,HIW"(�]���A�����F�����A�ҥH�A�o��F 1 �I�n��C)\n"NOR);
          ob->delete_temp("skycitywar");
        }
        ::die();
        return;
}

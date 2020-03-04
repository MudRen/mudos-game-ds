#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "����", ({ "cheng gu","cheng","gu" }) );
        set("level",30);
        set_skill("dodge",65);
        set_skill("parry",65);
        set_skill("sword",70);
        set("long" ,"�L�O�x�޴§ʸT�x���ƱN�A�]�O�j�N�x�������̡A�L\n"
                    "���H�����n���_�Q�A���ӤW���U���֦��s�A��o�ӤW\n"
                    "�����Ѥ~�����餧�a��C\n"
           );
        set("chat_chance", 10);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("sky_city_war", 1);
        set("age",47);
        set("title",HIG"�T�x"+HIR+"�ƱN"NOR);
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
          ob->add("popularity",1); //�n��
          tell_object(ob,HIW"(�]���A�����F�����A�ҥH�A�o��F 1 �I�n��C)\n"NOR);
          ob->delete_temp("skycitywar");
        }
        ::die();
        return;
}

#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�ʤҪ�", ({ "chief" }) );
        set("level",30);
        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("sword",80);
        set("long" ,"�L�O�b�T�x�̯���λ�ʧL���j�N�C\n");
        set("age",50);
        set("title",HIG"�T�x"NOR);
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
          ob->add("popularity",1); //�n��
          tell_object(ob,HIW"(�]���A�����F�ʤҪ��A�ҥH�A�o��F 1 �I�n��C)\n"NOR);
        }
        ::die();
        return;
}
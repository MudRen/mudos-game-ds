#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�h�L", ({ "soldier"}) );
        set("level",20);
        set_skill("dodge",25);
        set_skill("parry",25);
        set_skill("sword",30);
        set("long" ,"�L�O�b�T�x�̰V�m�������h�L�C\n");
        set("age",40);
        set("title",HIG"�T�x"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("sky_city_war", 1);
        setup();
        set_living_name("skycitywar");
        carry_object(__DIR__"wp/sword2")->wield();
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
          tell_object(ob,HIW"(�]���A�����F�h�L�A�ҥH�A�o��F 1 �I�n��C)\n"NOR);
          ob->delete_temp("skycitywar");
        }
        ::die();
        return;
}

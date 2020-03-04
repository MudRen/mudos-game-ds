#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "�ͧ�" NOR ,({"corpse demon","demon"}) );
        set("long",@LONG
�ͧ��O�ѫͮ�һE���Ӧ��A�]���ݭn�j�q������͡A�ҥH�`�b�Ӧa��
�ʡA��ӱѵ��L�ͤ��@�ѵ��A�K�[�J�ͭx�A��Q���ݱ��A�`�`�@�ȴ�
�榳�j�q����Ϩ�O�q�[�j�C
LONG
);
        set("age",60);
        set("race","beast");
        set("unit","��");
        set("title","�ͱN");
        set("level",35);
        set("str",90);
        set("attitude", "peaceful");
        add("addition_armor",100);
        set("gender", "����" );
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
    message_vision("\n$N"+NOR+"�@�ݨ�$n�K�ߨ�o�X�����I�I\n" NOR,this_object(),this_player() );
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
                tell_object(ob,HIG"�A�o��@�I�n��C\n" NOR);
                ob->add("popularity",1); //�n��
                ob->set("zombie_kill_war",0);
        }
        ::die();
        return;
}








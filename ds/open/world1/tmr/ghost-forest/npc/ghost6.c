#include <ansi.h>

inherit NPC;
inherit __DIR__"ghost-forest";

void create()
{
        set_name(CYN "�ΰ�" NOR ,({"sing ghost","ghost"}) );
        set("long",@LONG
�ΰ��ݨӽG���b�}�A�z���T�����ˡA�����z�S�ۺ���A�ʭ����I�l��
�ܥ��I�������N�C�ΰ��������@�L�k�y�U�Q�G���N�ƦW�Ĥ��A�եΪ��j�A
�۩۹ܤH�ʩR�C
LONG
);
        set("age",60);
        set("race","�H��");
        set("title","����");
        set("level",28);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
                (: ghost_heal,this_object() :),
        }) );



        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("unarmed",80);
        set_skill("fork",110);
        setup();
    carry_object(__DIR__"wp/pike")->wield();
       set_living_name("ghost-forest-war-ghost");
}

void init()
{
        ::init();

if(this_player()->query("level") > 20 && userp(this_player() ) && this_object()->visible(this_player()))
        {
        message_vision("\n$N"+NOR+"�g�ܤ@�n�A�}�l����$n�I�I\n" NOR,this_object(),this_player() );
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

        ob->add("ghost_forest_war",1);
          if(ob->query("ghost_forest_war") > 2 )
        {
                tell_object(ob,HIG"�A�o��@�I�n��C\n" NOR);
                ob->add("popularity",1); //�n��
                ob->set("ghost_forest_war",0);
        }
        ::die();
        return;
}


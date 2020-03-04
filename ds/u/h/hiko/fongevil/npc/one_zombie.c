#include <ansi.h>

inherit NPC;
inherit __DIR__"zombiekill";

void create()
{
        set_name(CYN "�W����" NOR ,({"one-eye zombie","zombie"}) );
        set("long",@LONG
�W���ͼˤl�����ªZ�A�ݨӤQ�����Z�A���W���۫ܰ��Z���C�W���ͬO
�Q�L�ͤ��@�ѵ��ҫH��������A�����ۤ��L���鳣�������ӡA�ͫe
�ӬO�@�W�Ѵ¤j�N�A���۱j�j��աC
LONG
);
        set("age",60);
        set("race","�H��");
        set("title","�ͱN");
        set("level",38);
        set("Merits/bio",6);
        set("Merits/bar",6);
        set("str",90);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        add("addition_armor",90);
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
        set_skill("fork",100);
        setup();
       carry_object(__DIR__"../wp/funeral_pike")->wield();
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
    message_vision("\n$N"+NOR+"�@�ݨ�$n�K���X���������I�I\n" NOR,this_object(),this_player() );
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
        tell_object(ob,HIG"�A�o��@�I�n��C\n" NOR);
        ob->add("popularity",1); //�n��
        ::die();
        return;
}







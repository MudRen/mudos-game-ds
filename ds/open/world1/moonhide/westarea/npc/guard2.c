#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�v��̨ͽ�", ({ "sun-follow guard", "guard"}) );
        set("level", 40);
        set("long" ,"�v��̨ͽìO�����X����^�A�t�d���@���ݪ��M���C\n");
        set("age", 250);
        set("title",HIR"�E�Ѷ���"NOR);    
        set("chat_chance", 10);
        set("attitude", "aggressive");
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        setup();
        set_living_name("westwar");
        set_temp("apply/armor", 50);
        set_temp("apply/shield", 50);
        set_temp("apply/damage", 50);
        carry_object(__DIR__"obj/guard-whip")->wield();
        carry_object(__DIR__"obj/guard-surcoat")->wear();
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
        ob->add("popularity",1); 
        tell_object(ob,HIW"(�A�o�� 1 �I�n��C)\n"NOR);
        ::die();
        return;
}


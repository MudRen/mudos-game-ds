#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC"��I��"NOR, ({ "ai-nieer thunder", "thunder"}) );
        set("level", 55);
        set("long",@LONG
��I���O�E�Ѷ����D�A�֦�����p������O�A
�ǻD�L���O�Z�H�A�ӬO�q����@���C
LONG
		);
        set("age", 40);
        set("attitude", "aggressive");
        set("title", HIY"�p��"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (: command("wield sword") :),  
    	    (: command("wield sword") :),        }));         
		setup();
        set_living_name("westwar");
        carry_object(__DIR__"obj/sword")->wield();
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
        ob->add("popularity", 3); 
        tell_object(ob,HIW"(�A�o�� 3 �I�n��C)\n"NOR);
        ::die();
        return;
}


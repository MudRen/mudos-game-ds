#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���-��������", ({"VH0319", "vh0319","vh"}) );
        set("race", "�����H");
        set("gender", "�k��"); 
        set("age", 22);
        set("attitude", "heroson");
        set("level", random(3)+2);
        set("evil", -99);
        set("combat_exp",200);
        set("chat_chance", 1 );    
        set("chat_msg", ({   
        (:command("say hi"):),
        (:command("say �A�n��"):),
        (:command("say �A����"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command(""):),
        (:command(""):),
        }) );
        setup(); 
}


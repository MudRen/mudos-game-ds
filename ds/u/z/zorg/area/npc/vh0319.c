#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ＶＨ-０３１９", ({"VH0319", "vh0319","vh"}) );
        set("race", "機器人");
        set("gender", "女性"); 
        set("age", 22);
        set("attitude", "heroson");
        set("level", random(3)+2);
        set("evil", -99);
        set("combat_exp",200);
        set("chat_chance", 1 );    
        set("chat_msg", ({   
        (:command("say hi"):),
        (:command("say 你好阿"):),
        (:command("say 你哪位"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command(""):),
        (:command(""):),
        }) );
        setup(); 
}


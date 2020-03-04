#include <ansi.h>
inherit NPC;

void create()
{
        set_name("馬洛", ({"Were Wolf", "wolf","WF"}) );
        set("long", "力大無窮身手靈敏,而且具有人類的智慧,在滿月時更能發揮神秘的力量！\n
聽說只有銀製的武器才能殺的了他!\n");
        set("race", "妖魔");
        set("gender", "男性"); 
        set("age", 83);
        set("attitude", "heroson");
        set("level", 5);
        set("evil", 99);
        set("combat_exp",500);
        set("chat_chance", 2);    
        set("chat_msg", ({   
        (:command("say 我的名子馬洛!!!"):),
        (:command("hehe"):),
        "馬洛看著月亮大笑...... 口圭 口合 口合 口合 ∼∼∼\n",
        (:command("say 月圓!!月圓!!"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        "馬洛爆吼道:殺∼∼殺∼∼殺∼∼\n",
        (:command(""):),
        }) );
        setup(); 
}


#include <ansi.h>
inherit NPC;

void create()
{
        set_name("米伽勒", ({"michel"}) );
   set("long", "你眼前就是四大熾天使中的大天使長米伽勒!擁有兩千天使兵團的權力,
曾與墮落天使抗衡並大獲全勝\n");
        set("race", "人類");
        set("gender", "女性"); 
        set("age", 3000);
        set("attitude", "heroism");
        set("level",70);
        set("evil", -999);
        set("combat_exp",5000);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("poken", 100);
        set_skill("cloudsteps", 100);
        set_skill("thundersword", 100);
        set_spell("god-benison", 100);
        set_skill("unarmed",100);
        set("title",HIW"【"HIR"熾天使"NOR" "HIG"火"NOR" "HIC"大天使長"HIW"】"NOR);
        set_skill("parry", 100);  
        set("chat_chance", 3);  
        set("chat_msg", ({     
        "米伽勒面無表情的說道:人類是必需毀滅的,人類是罪惡的根源.\n"
}) ); 
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({ 
        (:command("[32mdefend [0muriel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert thundersword"):), 
        (:command("exert poken"):), 
        (:command("exert cloudsteps"):), 
        "米伽勒一臉怒火的說道:人類是罪惡的根源\n"
        }) );
        setup();  
        carry_object("u/z/zorg/obj/sword2.c")->wield();
}


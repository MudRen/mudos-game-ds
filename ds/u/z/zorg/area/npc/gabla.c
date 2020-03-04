#include <ansi.h>
inherit NPC;

void create()
{
        set_name("葛不勒", ({"gabla"}) );
   set("long", "你眼前就是四大熾天使中的生命天使！擁有三對羽翼的最高級神聖天使\n");
        set("race", "人類");
        set("gender", "男性"); 
        set("age", 2000);
        set("attitude", "heroism");
        set("level",100);
        set("str",100);   
        set("con",100);
        set("int",100);
        set("dex",100);
        set("evil", -999);
        set("combat_exp",5000);
        set("title",HIW"【"HIR"熾天使 "HIG"水 "HIC"生命天使"HIW"】"NOR);
        set_skill("unarmed",100);
        set_skill("parry", 100);  
        set_skill("mirage-steps", 100);  
        set_skill("sword", 100);  
        set_skill("poken", 100);  
        set_skill("dodge", 100);  
        set_skill("sorgi_sword", 100);  
        set("env/wimpy", 10);        
        set("chat_chance", 1);      
        set("chat_msg", ({   
       "葛不勒面無表情的說道:人類的罪是會遺傳,人類是罪惡的根源.\n"
}) );
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({  
        (:command("[32mdefend [0mmichel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert poken"):), 
        (:command("exert sorgi_sword"):),
        (:command("exert mirage-steps"):),
        "葛不勒一臉怒火的的說道:人類是罪惡的根源\n"
        }) );
        setup(); 
        carry_object("/u/z/zorg/obj/sword2.c")->wield();
        carry_object("/u/z/zorg/obj/dagger1.c")->wield();
}





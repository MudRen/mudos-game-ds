#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N使出『神明─修羅技 之※破字訣』，擊向$n的$l",
                "attact_type":  "bar",       
                "damage_type":  "擊傷",
        ]),
        ([      "action":               "$N使出『神明─修羅技 之※分字訣』，劃向$n的$l",
                "attact_type":  "bar",
                "damage_type":  "割傷",
        ]),
        ([      "action":               "$N使出『神明─修羅技 之※闇字訣』，打向$n的$l",
                "attact_type":  "bar",
                "damage_type":  "內傷",
        ]),
        ([      "action":               "$N使出『神明─修羅技 之※熅字訣』，衝向$n的$l",
                "attact_type":  "bar",
                "damage_type":  "撞傷",
        ]),
});
void create()
{
        set_name(HIR"修羅王"NOR,({"shiro king", "shiro","king" }) );
        set("long",@LONG
上古的霸王，因為太強了，被天神封印在神殿裡，
擁有人類難以想像的力量。
LONG
);
        set("title",HIC"神明"NOR);
        set("limbs", ({
                "頭部", "頸部", "胸口", "後腰", "腰間", "腹部", "左腳","右腳",
        }) );
        set("age",200);
        set("level",70);
        set("race","human");
        set("addition_armor",300);
        set("addition_damage",300); 
        set_spell("shiro-spell",100);
        set_skill("force",100);
        set_skill("dodge",200);
        set("chat_msg_combat", ({
                (:command("cast shiro-spell"):),
         }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object(__DIR__"obj/shiro-king-armor")->wear(); 
        carry_object(__DIR__"obj/shiro-king-spear")->wield();
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        {
                ::die();
                return;
        }
        message("world:world1:vision",
        HIB"\n【英雄物語】"+HIC""+ob->name(1)+""+HIW"成功\的挑戰了"+HIR"修羅王\n\n"+NOR
        ,users());
        ob->add("popularity",10); //聲望
        ::die();
        return;
}


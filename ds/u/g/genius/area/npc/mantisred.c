//mantisred
#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":"$N兩把銳利的刀鋒席捲而來，狠狠地向$n身上劃去。",
                "attact_type":  "bar",
                "damage_type":  "斬傷",
        ]),
});
void do_clean();

void create()
{
        set_name(RED"紅螳螂怪"NOR,({"red mantis","red","mantis"}) );
        set("long",@LONG
眼前是一隻暗紅色的超大型螳螂，巨大的身軀令人毛骨悚然。
LONG
);
        set("limbs", ({
                "頭部","胸口","背後","腹部","前腳","後腳",
        }) );
        set("age",3);
        set("level",25);
        set("gender","雄性");
        set("race","monster");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
"紅色的大螳螂揮動利刃，表達不滿的情緒。\n",
"紅色大螳螂低下頭部，用力地搖動著。\n",
        }));
        set_skill("mob_bite", 85);
        set("addition_armor",40);
        set("addition_damage",40);

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

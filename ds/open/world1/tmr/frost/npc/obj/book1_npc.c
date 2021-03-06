#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$n細讀道德部「老君指歸」一章，苦思不得其解",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "道德部中一行「夫物之所以生，功\之所以成，必生乎無形，形由乎無名」，$n苦思良久仍然無法領會",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n仔細鑽研「物從道生」的涵義，但苦思良久，仍不知其所指",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n細讀「大道隱，世教衰，天下方大亂」的文字，但卻越讀越心煩意燥",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "內傷",
        ]),
});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void do_die() {
         message_vision(CYN "$N化作一陣輕煙消失了...\n" NOR, this_object() );
         destruct(this_object());
}

// 幫主人補血
void do_heal() {
        object ppl;
        ppl = query("owner");
        if( !ppl || this_object()->is_fight(ppl) ) {
                message_vision(CYN "$N化作一陣輕煙消失了...\n" NOR, this_object() );
                destruct(this_object());
                return;
        }

        if( ppl->query("hp") > ppl->query("max_hp")/4*3 ) return;
        if( environment(ppl) != environment(this_object()) ) return;
                
        message_vision(YEL "$N翻開「明君守始」篇，只見其中的文字散發出光芒...\n" NOR, this_object(), ppl);
        add("times", 1);
        if(ppl->is_fighting() )
                ppl->receive_heal("hp", 1 + ppl->query("max_hp")/30 );
        else
                ppl->receive_heal("hp", 1 + ppl->query("max_hp")/20 );

        tell_object(ppl, HIG "(你覺得自已的生命力又更旺盛了。)\n" NOR);
        if( query("times") >= 50 ) do_die();
}

void create()
{
        set_name("道德部",({"morality book" ,"book"}));
        set("gender", "男性");
        set("long",@LONG
這是道派道藏中最有名「雲笈七籤」中的道德部。裡頭開宗
明義寫著「太上之象，莫高乎道德；其次莫大乎神明；其次莫大
乎太和；其次莫崇乎天地；其次莫著乎陰陽；其次莫明乎大聖。
夫道德，所以可道而不可原也」。
LONG
        );
        set("level", 15);
        set("age",5);
        set("title","雲笈七籤");
        set_skill("parry", 50);
        set_skill("block", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("fly",1);

        set("chat_chance",30);
        set("chat_msg",({
                (: do_heal() :),
        }) );

        setup();
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
}


#include <ansi.h>
inherit NPC;
mapping *combat_action = ({
        ([      "action":              "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIY+"伏魔訣"+NOR+""+CYN+"】"+NOR+"一道金光閃過$n的$l!",

                "attact_type":  "sou",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+MAG+"天罡\訣"+NOR+""+CYN+"】"+NOR+"一道紫光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIR+"破邪訣"+NOR+""+CYN+"】"+NOR+"一道紅光閃過$n的$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIC+"凍妖訣"+NOR+""+CYN+"】"+NOR+"一道藍光閃過$n的$l!",
                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIM+"詠日訣"+NOR+""+CYN+"】"+NOR+"一道橙光閃過$n 的
$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+GRN+"劍氣訣"+NOR+""+CYN+"】"+NOR+"一道綠光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIW+"滅殺訣"+NOR+""+CYN+"】"+NOR+"一道白光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+WHT+"四傲訣"+NOR+""+CYN+"】"+NOR+"一道灰光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+YEL+"地土訣"+NOR+""+CYN+"】"+NOR+"一道褐光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
              
  "damage_type":  "灼傷",
        ]),
});

void create()
{
        set_name(CYN"霧獸"NOR,({"wo"}) );
        set("long",@LONG
據說牠是最早追隨奇倪遁入黑暗的神獸之一,除此之外沒有太多的記載.
LONG
);
        set("title",HIR"「渾沌階級」"NOR);
        set("age",1000+random(50));
        set("level",60);
        set("gender","雄性");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "霧獸忽然被一股火光所包圍，痛苦的大吼一聲.....。\n",
        }));
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾部","雙翼" }) );
        set("verbs", ({ "bite", "claw" }) );
      set("str",120);
      set("int",50);
          set("addition_armor",100);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
    carry_object(__DIR__"eq/wo_waist")->wear();
    carry_object(__DIR__"eq/wo_cloak")->wear();
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
     message_vision("\n$N殺死霧獸，得到3點聲望! \n",ob);
             ob->add("popularity",3); //聲望
        ::die();
        return;
}

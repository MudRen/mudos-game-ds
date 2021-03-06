inherit NPC;
mapping *combat_action = ({
	([	"action":		"$N用念力攻擊$n的$l",
		"attact_type":  "sou",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"震傷",
	]),
	([	"action":		"$N將酸液噴向$n的$l",
		"attact_type":  "bio",
		"damage_type":	"潰傷",
	]),
	([	"action":		"$N施展木嵐攻向$n的$l",
		"attact_type":  "sou",
		"damage_type":	"刺傷",
	]),
	([	"action":		"$N用枯\枝揮往$n的$l",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
});

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("樹精", ({ "tree monster","monster" }) );
        set("race","monster");
        set("gender", "中性");
        set("level",23);
        set("age",999);
        set("evil",-15);
        set("long",@LONG
千年老樹的樹根深入地底，吸收了大地的靈氣而成為樹精，
經歷近千年的歲月磨練，使他們成為相當有智慧的生物。
LONG
);
        set_skill("unarmed",35);
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup(); 
        carry_object(__DIR__"../eq/tree_ring")->wear();
}


inherit NPC;
mapping *combat_action = ({
	([	"action":		"$N用念力攻擊$n的$l",
		"attact_type":  "sou",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"震傷",
	]),
	([	"action":		"$N颳起一陣寒風吹向$n的$l",
		"attact_type":  "wit",
		"damage_type":	"凍傷",
	]),
	([	"action":		"$N施展葉嵐攻向$n的$l",
		"attact_type":  "sou",
		"damage_type":	"割傷",
	]),
	([	"action":		"$N撞向$n的$l",
		"attact_type":  "bar",
		"damage_type":	"傷害",
	]),
	([	"action":		"$N招來一道閃電劈向$n的$l",
		"attact_type":  "sou",
		"damage_type":	"灼傷",
	]),
});

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("木靈", ({ "wood monster","monster" }) );
        set("race","monster");
        set("gender", "無性");
        set("level",33);
        set("age",350);
        set("evil",-15);
        set("long",@LONG
寄宿在木頭中的精靈，擁有使樹木生生不息的自然能力，最
擅長利用大自然的能源。
LONG
);
        set_skill("bow",50);
        set_skill("dodge", 10);
        set_skill("parry", 40);
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
                  (:command("shoot"):),
        }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup(); 
        carry_object(__DIR__"../wp/wood_bow")->wield();
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");
        carry_object(__DIR__"../obj/wood_arrow");       
}

inherit NPC;
void create()
{
    set_name("眼鏡蛇", ({ "cobra" }) );
    set("race", "野獸");
    set("age", 10);
    set("long", "一條眼鏡蛇，對著你立了起來。\n");
    set("attitude", "aggressive");
    set("limbs", ({ "頭部", "身體", "七寸", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("combat_exp", 4500);
    set_temp("apply/attack", 25);
    set_temp("apply/defense", 10);
    set_temp("apply/damage", 10);
    set_temp("apply/armor", 10);

	setup();
}

/*
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + 10);
        return 0;
}
*/
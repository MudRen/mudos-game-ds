inherit NPC;
void create()
{
    set_name("����D", ({ "cobra" }) );
    set("race", "���~");
    set("age", 10);
    set("long", "�@������D�A��ۧA�ߤF�_�ӡC\n");
    set("attitude", "aggressive");
    set("limbs", ({ "�Y��", "����", "�C�o", "����" }) );
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
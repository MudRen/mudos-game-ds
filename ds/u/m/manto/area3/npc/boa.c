
inherit NPC;
void create()
{
    set_name("����", ({ "boa constrictor", "boa", "constrictor" }) );
    set("race", "���~");
    set("age", 80);
    set("long", "�@����V�Ӫ������D�A�������K�K���C\n");
    set("attitude", "aggressive");

    set("limbs", ({ "�Y��", "����", "�C�o", "����" }) );
    set("verbs", ({ "bite" }) );

    set("combat_exp", 300000);
    set("no_get","������A�Ө��ӭ��աA�A�L�k����");
	  
	  set_skill("dodge", 200);
	  set_skill("parry", 200);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 50);
    set_temp("apply/damage", 50);
    set_temp("apply/armor", 100);
    set_temp("apply/dodge", 100);
	setup();
}

 
void die()
{
	object ob;
    	message_vision("$N�����ä�F�X�U�N���ʤF�C\n", this_object());
        ob = new(__DIR__"obj/boafur.c");
	ob->move(environment(this_object()));
	destruct(this_object());
}

/*
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + random(3));
        return 0;
}
*/

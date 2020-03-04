inherit NPC;
mapping *combat_action = ({
	([	"action":		"$N�Ω��O����$n��$l",
		"attact_type":  "sou",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"�_��",
	]),
	([	"action":		"$N�N�ĲG�Q�V$n��$l",
		"attact_type":  "bio",
		"damage_type":	"���",
	]),
	([	"action":		"$N�I�i��P��V$n��$l",
		"attact_type":  "sou",
		"damage_type":	"���",
	]),
	([	"action":		"$N�ά\\�K����$n��$l",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
});

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("���", ({ "tree monster","monster" }) );
        set("race","monster");
        set("gender", "����");
        set("level",23);
        set("age",999);
        set("evil",-15);
        set("long",@LONG
�d�~�Ѿ𪺾�ڲ`�J�a���A�l���F�j�a���F��Ӧ������A
�g����d�~������i�m�A�ϥL�̦����۷����z���ͪ��C
LONG
);
        set_skill("unarmed",35);
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup(); 
        carry_object(__DIR__"../eq/tree_ring")->wear();
}


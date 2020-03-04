inherit NPC;
mapping *combat_action = ({
	([	"action":		"$N�Ω��O����$n��$l",
		"attact_type":  "sou",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"�_��",
	]),
	([	"action":		"$N�h�_�@�}�H���j�V$n��$l",
		"attact_type":  "wit",
		"damage_type":	"���",
	]),
	([	"action":		"$N�I�i���P��V$n��$l",
		"attact_type":  "sou",
		"damage_type":	"�ζ�",
	]),
	([	"action":		"$N���V$n��$l",
		"attact_type":  "bar",
		"damage_type":	"�ˮ`",
	]),
	([	"action":		"$N�ۨӤ@�D�{�q�A�V$n��$l",
		"attact_type":  "sou",
		"damage_type":	"�`��",
	]),
});

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("���F", ({ "wood monster","monster" }) );
        set("race","monster");
        set("gender", "�L��");
        set("level",33);
        set("age",350);
        set("evil",-15);
        set("long",@LONG
�H�J�b���Y�������F�A�֦��Ͼ��ͥͤ������۵M��O�A��
�ժ��Q�Τj�۵M���෽�C
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

inherit NPC;

void create()
{
	set_name("�Ѫ�", ({ "tiger" }) );
	set("long", @LONG
�@���~�������\���ʪ�, ����θ����e�j, �ӥB�����󤧬����r, ���ɵo�X��q�C
LONG	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}", "����" })); //���𳡦�
	set("verbs", ({ "crash", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 5);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 3);
	set("level", 17);
	set("dex", 18);
	set("str", 21);
	set("attitude", "killer");
	setup();
}

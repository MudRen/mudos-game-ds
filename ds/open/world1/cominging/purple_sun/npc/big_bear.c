inherit NPC;

void create()
{
	set_name("�j��", ({"big bear", "bear" }) );
	set("long", @ABC
�@���e�j���ʪ�, �@���}�N�O�A�@�ӤH�@�몺�j, �ݰ_�ӥ֫p�O�j���ˤl�C
ABC	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}", "����"})); //���𳡦�
	set("verbs", ({ "crash","bite", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 20);
	set("level", 20);
	set("str", 24);
	set("con", 32);
	set("attitude", "aggressive" );
	setup();
}
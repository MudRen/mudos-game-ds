inherit NPC;

void create()
{
	set_name("�p��", ({ "small bear", "bear" }) );
	set("long", @LONG
�@���j������N, ���G�٨S���j���ˤl, ��l�����٦��\�h���դ�C
LONG	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "crash","bite", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 3);
	set("level", 13);
	set("str", 20);
	set("con", 18);
	setup();
}
inherit NPC;

void create()
{
	set_name("����", ({ "wild cat", "cat" }) );
	set("long", @LONG
�@�����ջ������p�ʪ�, �`�Q�H��ӭ��ΡC
LONG
	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "crash","bite", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 1);
	set("level", 8);
	set("dex", 11);
	setup();
}
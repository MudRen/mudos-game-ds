inherit NPC;

void create()
{
	set_name("�ѹ�", ({ "mouse" }) );
	set("long", @LONG
�@���p�ʪ�, ���η��p, �b�A�}�Ǳr��, �C�������C
LONG	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "crash","bite", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 4);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 1);
	set("level", 5);
	set("dex", 10);
	setup();
}
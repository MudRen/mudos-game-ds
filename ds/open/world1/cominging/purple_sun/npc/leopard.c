inherit NPC;

void create()
{
	set_name("���\\", ({ "wild leopard", "leopard" }) );
	set("long", @long
�@���ݰ_�Ӱʧ@���F�Ӫ��ʪ�, �ѥ�����ʤW, �ݪ��X�����O�j, �������t�C
long	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "crash","bite", "claw", "hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("chat_chance", 13);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));
	set("age", 6);
	set("level", 18);
	set("str", 27);
	set("dex", 25);
	setup();
}

inherit NPC;

void create()
{
	set_name("�A�l", ({"mosquito"}) );
	set("long", "�i�c���A�l, ��䪺�b�A���䭸�ӭ��h..\n");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "�ͻH", "��}","����"})); //���𳡦�
	set("verbs", ({ "bite","poke"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level", 1);
	set("con",1);
	set("str",1);
	set("dex",10);
	set("int",1);
	setup();

}


inherit NPC;

void create()
{
	set_name("�A�l", ({"mosquito"}) );
	set("long", "�i�c���A�l, ��䪺�b�A���䭸�ӭ��h..\n");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�ͻH", "��}","����"})); //���𳡦�
	set("verbs", ({ "bite","poke"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level", 1);
	set("max_hp",15);
	set("con",1);
	set("str",1);
	set("dex",5);
	set("int",1);
	set_temp("apply/damage",-1);
	set_temp("apply/hit",-15);	//�z�ƩR���v
	set("attitude", "killer");
	setup();

}

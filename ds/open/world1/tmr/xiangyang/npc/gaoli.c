// gaoli.c

inherit NPC;

void create()
{
	set_name("���R��", ({ "gaoli shang", "shang" }));
	set("title", "�sù�{����");
	set("shen_type", 1);

	set("gender", "�k��");
	set("age", 45);
	set("long", "�o�O�Ӱ��R�ӤH�A���o�M����H�Sԣ�ϧO�C�s�檺�F��]�t���h�C\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	
	setup();
}


inherit NPC;
void create()
{
	set_name("����", ({"roach"}) );
	set("long", "�@���¦⪺����, ���۪o�G���ͻH�M��򪺸}��, �åB���_���R�ʨe��ĲŽ�C\n");
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�ͻH", "��}","����"})); //���𳡦�
	set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",2);
	setup();

}

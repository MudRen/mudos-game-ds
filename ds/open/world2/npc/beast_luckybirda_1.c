inherit NPC;
void do_flee();
void create()
{
	set_name("[1;31m���a���B��[0m", ({"red lucky bird","bird"}) );
	set("long",@LONG
�ǻ��������a���B���A���⪺�Y�W��g�������F�@�ǯS�O���������
�A�Ϊ����a�A�o�س��Q���֨��A�ǻ��i�H�a���H���B�C
LONG);
	set("unit","��");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "����", "�ͻH" })); //���𳡦�
	set("verbs", ({ "bite","poke" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("int",50);
	set("str",5);
	set("con",5);
	set("max_hp",10);
	set("level",1);
	set("dex",50);
	set_temp("fly",1);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: do_flee :),
	}) );
	setup();
    	set("exp",200+random(4000));
	add_money("dollar",1000);
}
void do_flee()
{
	if(this_object()->query("hp")<1) return;
	message_vision("[1;31m$N[37m��M�@���ਭ�A���Ͱk���F�C[0m\n",this_object());
	environment(this_object())->bird_fly();
	destruct(this_object());
}


inherit NPC;

void create()
{
	set_name("���s��", ({"wild female pig","pig"}) );
	set("long", "�@�Y�Q�����j���s�ޡA�o�����j���s�ަ��G�ܰQ���~�H�I�J�e���a�L�C\n");
	set("unit","�Y");
	set("race", "beast");
	set("limbs", ({ "�Y��", "����", "�e��", "��L", "�{�l","����" })); //���𳡦�
	set("verbs", ({ "bite","crash","hoof" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 24);
	set("level",18);
	//set_temp("fly",1);
	set("attitude", "aggressive");
	set("chat_chance",1);
	set("chat_msg",({
//		(: this_object(), "random_move" :),
		"���s�ޫܥΤO�����ۧA�ݡC\n",
	}));

	setup();
}

void die()
{
	object pork;
	int i;
	for(i=0;i<9;i++)
	{
		pork=new_ob(__DIR__"../obj/pork");
		pork->move(this_object());
	}
	::die();
}
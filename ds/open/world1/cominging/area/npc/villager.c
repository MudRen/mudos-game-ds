inherit NPC;
void create()
{
	set_name("�ƨR������",({ "villager" }));
	set("long",
		"�o�O�ƨR�����`���������A�L�̪����W���y���F�H���������A�i���L\n"
		"�̪����ԩM�V�O�C\n"
	);
	set("age",random(10)+30);
	set("level",random(5)+5);
	set("combat_exp",200);
	set("chat_chance",4);
	set("chat_msg",({
  "�����V�O���N�_�Ф�������ް��C\n",
  "�������G�[�o���A�n���L���~�V�ѧr�C\n",
  (: random_move :),
}));
	setup();
	carry_object(__DIR__"eq/sandal.c")->wear();
}
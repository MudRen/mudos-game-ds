inherit NPC;
void create()
{
	set_name("���H",({ "traveller","���H" }));
	set("long","�@�ӥ��b���������H�A�L�]�������A�]���I�W���O��䪺�����C\n");
	set("level", 1);
	set("age",20);
	set("chat_chance", 8);
	set("chat_msg", ({
  "���H���G �����٦��n�X�Ѫ����{�n���C\n",
  (: random_move :),
}) );
	setup();
	add_money("coin",150);
	carry_object(__DIR__"wp/woodensword")->wield();
	carry_object(__DIR__"eq/swatheshoe")->wear();
}
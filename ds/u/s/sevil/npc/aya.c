// child.c

inherit NPC;

void create()
{
	set_name("����", ({ "aya" }) );

	set_skill("stealing", 40);
	set_skill("dodge", 25);
	set_skill("dagger", 20);
	set_skill("parry", 20);

	set("level",5);
	set("age", 15);
	set("gender", "�k��");
	set("long",
"�o�ӤQ�T�A�|�����p�h�Q�N�O�u�����v�F�M�ݦo���W���Mż�����a�A\n"
"�o�Q���O�Ӭ��H�F�l�M�@�����L�L���j�������L�L�a��ۡM�٤��ɨn��\n"
"�A�ݡM�ϧA���Tı�o���ǵo�~�C\n"
);
	set("chat_chance",5);
	set("chat_msg",({
		(:command("sing"):),
		"�������n�۹D�G�u�١��ӹL�ӡ�㲴�����n��f�U���v\n",	
	}) );
	setup();
	add_money("coin", 50);
	carry_object(__DIR__"eq/heart_cloth")->wear();
	carry_object(__DIR__"wp/dagger")->wield();
}


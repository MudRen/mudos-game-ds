inherit NPC;
void create()
{
	set_name("�p�̤l", ({ "second apprentice", "apprentice" }) );
	set("long", "�@�ӯe�����s���J���p���{�A�j���O��q�������a�ӨӡA\n"
		    "���W�ٱa���@�I�o�ר��C\n");

	create_family("�e����",4,"�̤l");
	set("class","fighter");
	set("attitude","friendly");

	set("level",10);
	set("age",  18);
	set("chat_chance",9);
	set("chat_msg",({
  "�p�̤l���۽m�ۼC�C\n",
  (: command,"sweat" :),
}));

	set_skill("sword",  20);
	set_skill("dodge",  20);
	set_skill("parry",  25);
	set_skill("sorgi_sword",15);
	map_skill("sword","sorgi_sword");
	set_skill("fogseven",20);
	map_skill("dodge","fogseven");

	setup();
	carry_object(__DIR__"wp/longsword")->wield();
	carry_object(__DIR__"eq/flyboots")->wear();
}
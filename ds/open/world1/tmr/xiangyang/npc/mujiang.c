// mujiang.c

inherit NPC;

void create()
{
	set_name("��K", ({ "mu jiang", "mu", "jiang" }) );
	set("gender", "�k��" );
	set("age", 32);
	set("long",
		"�o���K���b�I�Y�u�@�A�]���o�{�A�b�`���ۥL�A�N��_�Y�ӷL���F�@�U�C\n");
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


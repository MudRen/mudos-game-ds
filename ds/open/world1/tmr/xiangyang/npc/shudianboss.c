// shudianboss.c

inherit NPC;

void create()
{
	set_name("�ѩ�����", ({ "shudian laoban", "boss" }) );
	set("gender", "�k��" );
	set("age", 62);
	set("long", "�@�����Ĥl�̤@���Nı�o�i�˪��ѯΡC\n");
	set("combat_exp", 3000);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/book/parry_book",
	}) );
	setup();
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


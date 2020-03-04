inherit NPC;
inherit SELLMAN;
void create()
{
	set_name("�C���F",({ "chao lo-lin","lin","lo-lin","chao" }));
	set("long",@LONG
�L�O�o�a�b�B�F�������㩱���Ѫ��A�L���V���Ǧ��@
���M�������Ϊ��p��y�A�W��¸���\�h�}�G���ϮסC

[ ����: �A�i�H�� list �V�L�߰ݦ����򨾨�i��Υ� buy  �V�L�ʶR�˳� ]

LONG
	);
	set("level", 5);
	set("age",10);
	set("no_fight",1);
	set("sell_list",([
		__DIR__"eq/steelshield": 6,
		__DIR__"eq/steelhead": 5,
		__DIR__"eq/surcoat":5,
		__DIR__"eq/wrists":6,
		__DIR__"eq/cloudarmor":7,
		__DIR__"eq/gloves" : 4,
	]) );
	setup();
	add_money("silver",150);
	carry_object(__DIR__"eq/e_cloth.c")->wear();
	carry_object(__DIR__"wp/dagger.c")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy","buy");
	add_action("do_list","list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "�C���F���G�o��O�ݭn����˪��˳ƩO�H\n");
			break;
		case 1:
			say( "�C���F���G�w����{�C\n");
			break;
	}
}
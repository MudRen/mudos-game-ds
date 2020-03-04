// In room077.c �K�Q�ө�
inherit NPC;
inherit SELLMAN;

void make_mark();

void create()
{
	set_name("�W�Ӥk����",({"miss"}) );
	set("long","�@��~�����p�j���ˤ����V�z���n�۩I�C\n");		
	set("age",19);
	set("level",7);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-7);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �w����{!!"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);

	set("talk_reply","��A�A�n���n�h�R�I�F����C");

	set("sell_list",([
		__DIR__"eq/amulet9"	:10,
		__DIR__"eq/armor24"	:40,
		__DIR__"eq/boiler25"	:40,
		__DIR__"eq/belt16"	:25,
		__DIR__"eq/boots15"	:20,
		__DIR__"eq/cloth20"	:30,
		__DIR__"eq/gloves14"	:20,
		__DIR__"eq/hat12"	:20,
		__DIR__"eq/mask13"	:20,
		__DIR__"eq/pants18"	:30,
		__DIR__"eq/leggings19"	:30,
		__DIR__"eq/ring15"	:20,
		__DIR__"eq/towel14"	:20,
		__DIR__"eq/wrists20"	:35,
	]));

	setup();

	add_money("dollar",100);
}

void init() 
{
	::init();
	add_action("do_list","list");
	add_action("do_buy" ,"buy");
}

void make_mark()
{
	object *enemy, ob;
	command("say �z�I�ϩR���I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}

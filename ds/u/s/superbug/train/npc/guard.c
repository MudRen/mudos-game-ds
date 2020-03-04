
inherit NPC;
void make_mark();

void create()
{
	set_name("ĵ��",({"guard"}) );
    set("long","�@�Ӧ~����ĵ�áA���b���޵ۡC\n");       
	set("age",23);
	set("level",20);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
        (:command("say �o�̤��O�ȹC�ϡA�Ф��n�b�o�̳r�d��I"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
        (:command("say ���F���@�v�w�A�ڤ@�w�|�ⰵ�ê̴N�a���k�I�I"):),
		(: make_mark :),
	}) );
	set_skill("dodge",20);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("sword",20);

    set("talk_reply","��A�̪���񦳨Ǯd�p���A�A�n�h�[�d�N�C");
	setup();


}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 1 + random(3) )
	{
		command("say �A�o�ӧ@�ê̡A�~�M���D�@��A���ѳQ�ڹJ���A�˷��C");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}

void make_mark()
{
	object *enemy, ob;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	message_vision("$N�W�i�����_�L�u�q�ШD�䴩�C\n",this_object());
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}

inherit NPC;
void finish_eat(object ob);
void create()
{
	set_name("�p��", ({ "small white","white","dog" }) );
	set("race", "beast");
	set("age", 2);
	set("level",3);
        set("long", @LONG
�A�ݨ�@���͵����զ�g���A���b�V�A�n���ڡC
LONG);
	set("str",2);
	set("max_hp",30);
	set("dex",1);
	set("int",1);
	set("con",1);
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"�p�չ�ۧA�n�F�n���ڡC\n",
		"�p�աG�L��L�L��\n" 
		}) );
	setup();
}

int accept_object(object who, object ob)
{

	if( ob->id("bone") || ob->is_meat() ) {
//		set_leader(who);
			message_vision("$N���X�@"+ob->query("unit")+ob->name()+"��$n�C\n",who,this_object());
			if(!this_object()->is_busy()) this_object()->start_busy(1);
			//message("vision", name() + "�����a�L�L�s�F�_�ӡC\n", environment());
			call_out("finish_eat",1,ob);
		return 1;
	}
}

void finish_eat(object ob)
{
	if(!this_object() || !ob) return;
	message_vision("$N�ܧִN��$n�Y���F�C\n",this_object(),ob);
	destruct(ob);
	return;
}
inherit NPC;
void finish_eat(object ob);
void create()
{
	set_name("�¿�", ({ "black cat","cat" }) );
	set("race", "beast");
	set("age", 4);
	set("level",4);
        set("long", @LONG
�@�������¦⪺�ߡA�Pı���G���ӦN�Q�C
LONG);
	set("str",3);
	set("max_hp",40);
	set("dex",6);
	set("int",4);
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance",6);
	set("chat_msg",({
		(: this_object(), "random_move" :),
	}));
	setup();
}

int accept_object(object who, object ob)
{

	if( ob->query("gender")=="fish" || ob->is_meat() ) {
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
	message_vision("$N�p���l�l����$n�Y���C\n",this_object(),ob);
	destruct(ob);
	return;
}
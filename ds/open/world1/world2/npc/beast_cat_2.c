inherit NPC;
void finish_eat(object ob);
void create()
{
	set_name("�p���", ({ "color cat","cat" }) );
	set("race", "beast");
	set("age", 4);
	set("level",2);
        set("long", @LONG
�@���Ŧ�������p�ߡA���n�_���ݵۧA�C
LONG);
	set("str",1);
	set("max_hp",20);
	set("dex",3);
	set("int",2);
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
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
	message_vision("$N�C�C����$n�Y���F�C\n",this_object(),ob);
	destruct(ob);
	return;
}
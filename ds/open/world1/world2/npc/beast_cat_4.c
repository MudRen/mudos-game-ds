inherit NPC;
void finish_eat(object ob);
void create()
{
	set_name("黑貓", ({ "black cat","cat" }) );
	set("race", "beast");
	set("age", 4);
	set("level",4);
        set("long", @LONG
一隻全身黑色的貓，感覺似乎不太吉利。
LONG);
	set("str",3);
	set("max_hp",40);
	set("dex",6);
	set("int",4);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
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
message_vision("$N拿出一"+ob->query("unit")+ob->name()+"給$n。\n",who,this_object());
			if(!this_object()->is_busy()) this_object()->start_busy(1);
			//message("vision", name() + "高興地汪汪叫了起來。\n", environment());
			call_out("finish_eat",1,ob);
		return 1;
	}
}

void finish_eat(object ob)
{
	if(!this_object() || !ob) return;
	message_vision("$N小心翼翼的把$n吃掉。\n",this_object(),ob);
	destruct(ob);
	return;
}
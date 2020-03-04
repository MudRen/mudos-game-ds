inherit NPC;
void finish_eat(object ob);
void create()
{
	set_name("小白", ({ "small white","white","dog" }) );
	set("race", "beast");
	set("age", 2);
	set("level",3);
        set("long", @LONG
你看到一隻友善的白色土狗，正在向你搖尾巴。
LONG);
	set("str",2);
	set("max_hp",30);
	set("dex",1);
	set("int",1);
	set("con",1);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"小白對著你搖了搖尾巴。\n",
		"小白：汪∼汪汪∼\n" 
		}) );
	setup();
}

int accept_object(object who, object ob)
{

	if( ob->id("bone") || ob->is_meat() ) {
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
	message_vision("$N很快就把$n吃掉了。\n",this_object(),ob);
	destruct(ob);
	return;
}
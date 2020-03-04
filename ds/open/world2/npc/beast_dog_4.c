inherit NPC;
void finish_eat(object ob);
void create()
{
	set_name("小黑", ({ "small black","black","dog" }) );
	set("race", "beast");
	set("age", 2);
	set("level",4);
        set("long", @LONG
你看到一隻懶散的黑狗，正在打哈欠。
LONG);
	set("str",3);
	set("max_hp",40);
	set("dex",2);
	set("int",1);
	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
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
	message_vision("$N慢慢的把$n吃掉了。\n",this_object(),ob);
	destruct(ob);
	return;
}
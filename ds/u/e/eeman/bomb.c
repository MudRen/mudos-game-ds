inherit ITEM;

void bomp(object env);

void create()
{
	set_name("定時炸彈", ({ "timer bomb", "bomb" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "這是一個定時炸彈。(setup)\n");
		set("unit", "個");
		set("value", 500);
	}
}

void init()
{
	add_action("do_setup","setup");
}

int do_setup()
{
        object env,me;
        mapping exits;
	string *env1;

	me = this_player();
	env = environment(me);
	exits = env->query("exits");
	env1 = keys(exits);

	call_out("bomp",5, env);
	message_vision("$N把定時炸彈埋進土裡!!倒數5秒!!!!!!!!\n", me);

for(int i=0;i<sizeof(env1);i++)
{

        if( mapp(exits = env->query("exits")) && !undefinedp(exits[env1[i]]) ) 
	{
                if( objectp(env = find_object(exits[env1[i]])) )
                        call_out("bomp",5, env);
                else {
                        call_other(exits[env1[i]], "???");
                        call_out("bomp",5, find_object(exits[env1[i]]));
                     }
        }
}
                return 1;
}

void bomp(object env)
{
	object *ob;
	ob= all_inventory(env);
		for(int z=0; z<sizeof(ob); z++)
		{
			if( !living(ob[z]) ) continue;

			ob[z]->receive_damage("hp", 50, this_player());
			tell_object(ob[z], "炸彈爆炸, 你被炸的七暈八素﹗(50)\n");
		}
	return ;
}


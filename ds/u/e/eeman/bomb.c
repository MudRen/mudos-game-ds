inherit ITEM;

void bomp(object env);

void create()
{
	set_name("�w�ɬ��u", ({ "timer bomb", "bomb" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�o�O�@�өw�ɬ��u�C(setup)\n");
		set("unit", "��");
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
	message_vision("$N��w�ɬ��u�I�i�g��!!�˼�5��!!!!!!!!\n", me);

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
			tell_object(ob[z], "���u�z��, �A�Q�����C�w�K���T(50)\n");
		}
	return ;
}


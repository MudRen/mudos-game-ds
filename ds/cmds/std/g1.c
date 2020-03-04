// go.c
#include <ansi.h>

inherit F_CLEAN_UP;
inherit SSERVER;
mapping default_dirs = ([
	"north":		"�_",
	"south":		"�n",
	"east":			"�F",
	"west":			"��",
	"northup":		"�_��",
	"southup":		"�n��",
	"eastup":		"�F��",
	"westup":		"����",
	"northdown":		"�_��",
	"southdown":		"�n��",
	"eastdown":		"�F��",
	"westdown":		"����",
	"northeast":		"�F�_",
	"northwest":		"��_",
	"southeast":		"�F�n",
	"southwest":		"��n",
	"up":			"�W",
	"down":			"�U",
	"enter":		"��",
	"out":			"�~",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	mixed dest;
	string mout, min, dir,who,*busy_type;
	object env, obj,victim,ride,defender,protecter;
	mapping exit=([ ]),h_exit=([ ]),is_busy=([ ]);
	int wound=0,check=0,i=0;
	
	if( in_edit(me) || in_input(me) || me->query_temp("Fall_sleep")) return 0;
	if( !arg ) return notify_fail("�A�n�����Ӥ�V���S\n");

	if( me->over_encumbranced() )
		return notify_fail("�A���t���L���M�ʼu���o�C\n");

	if( me->is_busy() )
		return notify_fail("�A���ʧ@�٨S�������M���ಾ�ʡC\n");
	if(mapp(is_busy=me->query_temp("is_busy")))
	{
		busy_type=keys(is_busy);
		for(i=0;i<sizeof(is_busy);i++)
		{
			if(stringp(is_busy[busy_type[i]])) return notify_fail(is_busy[busy_type[i]]+"\n");
			if(!is_busy[busy_type[i]]) return notify_fail("�A�ȮɵL�k���ʡC\n");
		}
	}
	ride=me->query_temp("ride");
	if(wound = me->query("wound/foot") && !ride)
	{
		wound/=10;
		if(random(14-wound)==1) check = 1;
		if(wound>8 && check)
		{
			me->start_busy(1);
			return notify_fail(HIC"�A�����}�˶չL��, �ʼu���o�C\n"NOR);
		} else
		if(wound>5 && check)
		{
			me->start_busy(1);
			return notify_fail(HIC"�A�����}��M�@�}�k�h, �h���A�L�k���ʡC\n"NOR);
		}
	}
        env = environment(me);
        if(!env) return notify_fail("�A���̤]�h���F�C\n");
	exit = env->query("exits");
        h_exit = env->query("hide_exits");
        if( mapp(exit) && !undefinedp(exit[arg]) );
        else
        if( !mapp(h_exit) || undefinedp(h_exit[arg]) )
        {
        	if( query_verb()=="go")
	    		return notify_fail("�o�Ӥ�V�S���X���C\n");
                else
                        return 0;
        }
        if(!mapp(exit))
        {
        	dest = h_exit[arg];
        }
        else
        if( undefinedp(exit[arg]) )
        {
        	dest = h_exit[arg];
        }
        else
        {
        	dest = exit[arg];
        }

	if( stringp(dest) )
	{
	        if( !(obj = find_object(dest)) ) call_other(dest, "???");
	        if( !(obj = find_object(dest)) ) return notify_fail("�L�k���ʡC\n");
	        if( !env->valid_leave(me, arg) ) return 0;
	        if( !undefinedp(default_dirs[arg]) )
	                dir = default_dirs[arg];
	        else
	                dir = arg;
	        if(obj->is_house())
	        {
	        	obj->remeber_exit(env);
	        	env->set("exits/"+arg,obj);
	        }
	}
	else if( objectp(dest) )
	{
		obj=dest;
		if( !env->valid_leave(me, arg) ) return 0;
		if( obj->is_house() ) dir=obj->outside_vision(me);
		else dir=arg;
	}
	
	if( me->is_fighting() && victim = offensive_target(me))
	{
		if(
		   victim->visible(me)
		   && !userp(victim)
		   && random(2)
		   && random(victim->query_dex()) > random(me->query_dex()*2+10)
		   && !victim->is_busy()
		   && !victim->is_block()
		)
		{
			me->add_busy(1);
			return notify_fail(HIM"����A�Q���}���ɭԡA"+victim->name()+HIM"�{���צ�F�A���h��!!!\n"NOR);
		}
		mout = "��" + dir + "����Ӱk�F�C\n";
		if(me->query("race")=="human")
			min = "���Y�j��, �Q���W�i�a�]�F�L�ӡC\n";
		else min = "�ܯT�V���k�F�L�ӡC\n";
		if(victim) 
		{
			tell_object(me,"  �i���}�ɧA�`�N��"+COMBAT_D->status(victim)+"�j\n\n");
		}
	} else {
		mout = "��" + dir + "���}�C\n";
		if(me->query("race")=="human")
				min = "�Ө즹�a�C\n";
		else min = "�Ө즹�B�C\n";

	}
	if(me->query_temp("hide")) me->delete_temp("hide");
	if(me->query_temp("sneak")) me->delete_temp("sneak");
	if(defender=me->query_temp("defender"))
	{
		defender->delete_temp("protecter");
		me->delete_temp("defender");
	}
	if(protecter=me->query_temp("protecter"))
	{
		protecter->delete_temp("defender");
		me->delete_temp("protecter");
	}
	who=me->name();
	if(ride) who=who+"�M��"+ride->name();
	if(me->query_temp("invis") < 1 )
	{
	 	message( "vision", who + mout, environment(me), ({me}) );
	}
	if( me->move(obj) )
	{
		me->remove_all_enemy();
		if(check)
		{
		   min+=me->name()+"��۸}, �@�ƫܵh�W���ˤl�C\n";
		   write("\n�A���}���ˤf�����@�h�C\n");
		}
		if(me->query_temp("invis")<1)
			message( "vision", who + min, environment(me), ({me}) );
		me->delete_temp("visible_ob");
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	object env,target;
	mapping exits;
	string *directions;
	if(!me) return;
	if(!living(me) ) return;
	env = environment(me);
	if( !env || base_name(env) == VOID_OB ) return;
	exits = env->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, HIW"\n�A�}�l����|�k�]...\n"NOR);
	if(!userp(me) && random(2)) return;
	if(me->query("ride/riding"))
	{
		main(me, directions[random(sizeof(directions))]);
		return;
	}
	if(random(me->query("wound/foot"))>40)
	{
		tell_object(me, HIM"�A�Q���]�i�O�A�����}�o��ť�ϳ�..\n"NOR);
		return;
	}
	
	if(target = offensive_target(me))
	{
		if(random(10+me->query_dex()*2)<random(target->query_dex()) )
		{
			tell_object(me, HIM"�V�F!!�A�Q���]�i�O�o�Q��⵹�d��F!!!..�o�U�l�ɤF..\n"NOR);
			return;
		}
	}
//	main(me, directions[random(sizeof(directions))]);
        me->force_me("go "+directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
���O�榡 : go <��V>
 
���A�����w����V���ʡC
 
HELP
    );
    return 1;
}

// go.c
#include <ansi.h>
#define GO_CMD		"/cmds/std/go"
inherit F_CLEAN_UP;
inherit SSERVER;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string mout, min, dir,who,*busy_type;
	object env, obj,victim,ride,defender,protecter;
         mapping is_busy=([ ]);
          int i = 0;
	if( in_edit(me) || in_input(me) || me->query_temp("Fall_sleep")) return 0;
	if( !arg ) return GO_CMD->main(me,"enter");
	obj = present(arg, environment(me));
	if(!obj) return notify_fail("�A�n�i�J����?\n");
	
	if(!obj->is_house())
	{
		dir=obj->query("short");
		notify_fail("�A���|�Q�i�J"+dir+"���C\n");
		return 0;
	}

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
        env = environment(me);
        if(!env) return notify_fail("�A���̤]�h���F�C\n");
	dir=obj->query_short(0);
	if( !env->valid_leave(me, arg) ) return 0;
	if( !obj->valid_enter(me) ) return 0;
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
		mout = "�k�i" + dir + "�F�C\n";
		if(me->query("race")=="human")
			min = "���Y�j��, �Q���W�i�a�]�F�i�ӡC\n";
		else min = "�ܯT�V���k�F�i�ӡC\n";
		if(victim) 
		{
			tell_object(me,"  �i���}�ɧA�`�N��"+COMBAT_D->status(victim)+"�j\n\n");
		}
	} else {
		mout = "�i�J�F" + dir + "�C\n";
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
	ride=me->query_temp("ride");
	if(ride) who=who+"�M��"+ride->name();
	if(me->query_temp("invis") < 1 )
	{
	 	message( "vision", who + mout, environment(me), ({me}) );
	}
	if( me->move(obj) )
	{
		if(env->is_house()) obj->set("exits/exit",env);
		else if(env->is_room()) obj->set("exits/exit",base_name(env));
		me->remove_all_enemy();
		if(me->query_temp("invis")<1)
			message( "vision", who + min, environment(me), ({me}) );
		me->delete_temp("visible_ob");
		me->set_temp("pending", 0);
		return 1;
	}

	return 0;
}

int help(object me)
{
	write(@HELP
���O�榡 : enter < �ؿv�� || �B��u�� >
 
���A�i�J�Y�ɫؿv���άO�B��u��C
 
HELP
    );
    return 1;
}

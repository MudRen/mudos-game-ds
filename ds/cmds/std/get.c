// get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;

	if( !arg ) return notify_fail("�A�n�߰_����F��S\n");
	if( me->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������T\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("�A�䤣�� " + from + " �o�˪F��C\n");
		if(living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�A���Ův���ť������谪�M�~��j���C\n");
		if(env->is_box())
		{
			if(!env->can_access_box()) return notify_fail("�A���������}"+env->name()+"�~��q�̭����F��C\n");
		}
	} else env = environment(me);

	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("�o�̨S���o�˪F��C\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "����Q���}�����C\n");
		if( amount < 1 )
			return notify_fail("�F�誺�ӼƦܤ֬O�@�ӡC\n");
		if( amount > obj->query_amount() )
			return notify_fail("�o�̨S������h��" + obj->name() + "�C\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj);
		} else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(!obj2->can_move(me))
			{
				destruct(obj2);
				return notify_fail("�A���O�q����, ������"+obj->name()+"\n");
			}
			obj->set_amount( (int)obj->query_amount() - amount );
			// Counting precise amount costs more time.
			if(obj->query("wiz_only")) obj2->set("wiz_only",1);
			return do_get(me, obj2);
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all")
	{
		//if( me->is_fighting() )	return notify_fail("�A�٦b�԰����T�u��@�����@�ˡC\n");
		if( !env->query_max_encumbrance() )	return notify_fail("�����O�e���C\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("���̭��S������F��C\n");

		for(i=0; i<sizeof(inv); i++)
		{
			if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
			do_get(me, inv[i]);
		}
		write("Ok�C\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("�A����S���o�˪F��C\n");

          if( obj->query("no_get") && wiz_level(me) <4 ) // Fix By tmr
		return notify_fail("�o�ӪF�讳���_�ӡC\n");
	
	return do_get(me, obj);
}
	
int do_get(object me, object obj)
{
          object old_env;
	int equipped;

	if( !obj ) return 0;
	old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
		//	if( !userp(obj) && !obj->is_corpse() )
		//		return notify_fail("�A�u��I�t��L���a������C\n");
		// If we try to save someone from combat, take the risk :P
	} else {
          if( obj->query("no_get") && wiz_level(me) <4 ) return 0;// Fix By tmr
	}
	if(!obj->can_move(me) ) return 0;
	if( obj->query("equipped") ) equipped = 1;
	if( obj->query("wiz_only") )
	{
	 if(wizardp(me)) obj->detete("wiz_only");
	 else {
	 	message_vision("����$N�Q���_$n��, $n��M�Ƭ��@����u�F!!\n",me,obj);
	 	destruct(obj);
	 	return 1;
	      }
	}
	if( obj->move(me) )
	{
		if( me->is_fighting() ) me->start_busy(1);
		if( obj->is_character() )
			message_vision( "$N�N$n�ߤF�_�Ӵ��b�I�W�C\n", me, obj );
		else if(!old_env)
			message_vision( sprintf("$N�߰_�@%s$n�C\n", 
				stringp(obj->query("unit"))? obj->query("unit") : "��"), me, obj );
		
		else
		{
			message_vision( sprintf("$N%s�@%s$n�C\n", 
				old_env==environment(me)? "�߰_":
					(old_env->is_character() ?
						"�q" + old_env->name() + "���W" + (equipped? "���U" : "�j�X"):
						"�q" + old_env->name() + "�����X"),
				stringp(obj->query("unit"))? obj->query("unit") : "��"), me, obj );
		}
		if( me->is_fighting() ) me->add_block(1);
                if(old_env && old_env->query("access_log"))
                {
                        log_file("access_log",sprintf("[%s] %s get %s from %s\n",ctime(time()),me->name_id(1),obj->name(),old_env->short()));
			old_env->log_get(me, obj);
                }
		return 1;
	}
	else return notify_fail("�A���O�q����, ������"+obj->name()+"\n");
}

int help(object me)
{
	write(@HELP
���O�榡 : get <���~�W��> [from <�e���W>]
 
�o�ӫ��O�i�H���A�߰_�a�W�ήe�������Y�˪��~.
 
HELP
    );
    return 1;
}
 

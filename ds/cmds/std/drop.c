// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(!arg) return notify_fail("�A�n��󤰻�F��S\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("�A���W�S���o�˪F��C\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( obj->query("secured") )
			return notify_fail("�Х���[secure ���~�W off]�Ѱ��������O�s���A\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "����Q���}���C\n");
		if( amount < 1 )
			return notify_fail("�F�誺�ƶq�ܤ֬O�@�ӡC\n");
		if( amount > obj->query_amount() )
			return notify_fail("�A�S������h��" + obj->name() + "�C\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("money_id") ) continue;
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("�A���W�S���o�˪F��C\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;
	string temp;
	if( obj->query("secured") )
			return notify_fail("�Х���[secure ���~�W off]�Ѱ��������O�s���A\n");
	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "�o�˪F�褣���H�N���C\n");
        if(obj->query("equipped")) return notify_fail("�Х��Ѱ��˳�.\n");
	if(obj->query_temp("riden")) return notify_fail("�Х� ride <�y�Mid> off.\n");
	if(environment(me)->query("no_drop")) return notify_fail("�o�̨S���Ŷ����A��F��C\n");
	if (obj->move(environment(me)))
	{
		if(wizardp(me) && userp(me) && sscanf(base_name(environment(me)),"/open/%s",temp)>=1 )
		{
			temp+="("+environment(me)->query("short")+")";
			log_file( "static/drop", "[" + geteuid(me) + "] drop a" + obj->short() + "("+base_name(obj)+")"+" at "+temp+" on " + ctime(time()) + "\n" );
			obj->set("wiz_only",1);
		}
		if( obj->is_character() )
			message_vision("$N�N$n�q�I�W��F�U�ӡC\n", me, obj);
		else {
			message_vision( sprintf("$N��U�@%s$n�C\n",	obj->query("unit")),
				me, obj );
			if( !obj->query("value") && !obj->value() ) {
				write("�]���o�˪F��ä��ȿ��M�ҥH�H�̨ä��|�`�N�쥦���s�b�C\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
���O�榡 : drop <���~�W��>
 
�o�ӫ��O�i�H���A��U�A����a�����~.
 
HELP
    );
    return 1;
}
 

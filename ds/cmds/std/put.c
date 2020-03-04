// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string target, item; // str;

	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("�A�n�N����F���i���̡S\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("�A�n�񤰻�F��S\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) ) return notify_fail("�o�̨S���o�˪F��C\n");
	if( dest->is_box() )
	{
		if(!dest->can_access_box()) return notify_fail("�A���������}"+dest->name()+"�~���F��i�h�C\n");

	}
	
	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("�A���W�S���o�˪F��C\n");
		if( obj==dest ) return notify_fail("�ӷ��M�ت�����O�ۦP���F��!\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "����Q���}�C\n");
		if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"�ä��O�@�Ӯe���C\n");
		if( obj->query_max_encumbrance() && !obj->query("no_get"))
			return notify_fail( "�e��������e���̡C\n");
		if( obj->query("no_drop") )
			return notify_fail( obj->name() + "����Q���C\n");
    if( obj->query("no_put") )
	{
        // if( stringp(str) ) return notify_fail( str );
		return notify_fail( obj->name() + "������e�����C\n");
	}
		if( amount < 1 )
			return notify_fail("�F�誺�ƶq�ܤ֬O�@�ӡC\n");
		if( amount > obj->query_amount() )
			return notify_fail("�A�S������h��" + obj->name() + "�C\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(!obj2->can_move(dest))
			{
				destruct(obj2);
				return notify_fail("�A�S����k��"+obj->query("name")+"��i"+dest->query("name")+"�̡C\n");
			}
			obj->set_amount( (int)obj->query_amount() - amount );
			return do_put(me, obj2, dest);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("�A���W�S���o�˪F��C\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	mixed no_put;
	string date;
	if( obj==dest ) return notify_fail("�ӷ��M�ت�����O�ۦP���F��!\n");
    if( obj->query("no_put") )
        {
        // if( stringp(str) ) return notify_fail( str );
                return notify_fail( obj->name() + "������e�����C\n");
        }

	if( obj->query("equipped") ) return notify_fail( obj->name() + "���Q�A�˳Ƶ�, ������e���̡C\n");
	if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"�ä��O�@�Ӯe���C\n");
	if( obj->query_max_encumbrance()  && !obj->query("no_get"))
			return notify_fail( "�e��������e���̡C\n");
	if( obj->query("no_drop") )
			return notify_fail( obj->name() + "����Q���C\n");
	if( no_put = obj->query("no_drop"))
	{
		if(stringp(no_put)) return notify_fail( no_put+"\n");
		return notify_fail( "�A�L�k��"+obj->name()+"��i���̡C\n");
	}
	if( obj->query_temp("riden") ) return notify_fail("�A���b�M�ۭC!\n");
	if(!obj->can_move(dest)) return notify_fail("�A�S����k��"+obj->query("name")+"��i"+dest->query("name")+"�̡C\n");
	if( obj->query("secured") ) return notify_fail( obj->name() + "�Q�A�]�w���O�s���A, ������e�����C\n");
	if( obj->move(dest) )
	{
		message_vision( sprintf("$N�N�@%s%s��i%s�C\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
//                if( wizardp(me) && NATURE_D->which_world(dest) )
		if( wizardp(me) && sscanf(base_name(environment(me)),"/open/%*s") == 1 ) // change by alick.
                {
                        date=ctime(time());
                        date=sprintf("%s",date[0..15]);
                        log_file("static/put",sprintf("[%s] %s(%s) put %s[%s] at %s\n",
                        date,
                        me->name(1),
                        getuid(me),
                        obj->name(1),
                        base_name(obj),
                        "short:"+dest->query("short")+"name:"+dest->name(1),
                        base_name(dest), ) );
                }
                if(dest->query("access_log"))
                {
                        log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                        dest->log_put(me, obj);
                }
		return 1;
	}
	else return 0;
}

int help(object me)
{
write(@HELP
���O�榡 : put <���~�W��> in <�Y�e��>
 
�o�ӫ��O�i�H���A�N�Y�˪��~��i�@�Ӯe���M��M�M�����A�n�֦��o�˪��~�C
 
HELP
    );
    return 1;
}

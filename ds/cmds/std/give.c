// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("�A�n���֤���F��S\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("�A�n���֤���F��S\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("�o�̨S���o�ӤH�C\n");
	if(who == me) return notify_fail("�ۤv���ۤv?? �O�x�F�C\n");
	if( who->is_inactive() ) 
		return notify_fail("��西�b�e���m�f���A�S�Ŧ��A���F��C\n");
	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("�A���W�S���o�˪F��C\n");
		if( obj->query("no_drop") && !obj->query("can_give"))
			return notify_fail("�o�˪F�褣���H�K���H�C\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "����Q���}���H�C\n");
		if( amount < 1 )
			return notify_fail("�F�誺�ƶq�ܤ֬O�@�ӡC\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("�A�S������h��" + obj->name() + "�C\n");
                if( who->is_inactive() )
                        return notify_fail("�A�L�k���F�赹���b���m���A�����a�C\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(!obj2->can_move(who) )
			{
				
				return notify_fail( who->name() + "������"+obj2->name()+"�C\n");
				
			}
			obj->set_amount( (int)obj->query_amount() - amount );
			return do_give(me, obj2, who);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("�A���W�S���o�˪F��C\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	string name,date;
	if( (obj->query("no_drop") ||  obj->query("no_give")) && !obj->query("can_give") && wiz_level(me) < 5)
		return notify_fail("�o�˪F�褣���H�K���H�C\n");
	if( obj->query_temp("riden") )
		return notify_fail("�ФU��(ride xx off)���H�M�a�C\n");
        if(obj->query("equipped")) return notify_fail("�Х��Ѱ��˳�.\n");
	if(!obj->can_move(who))
		return notify_fail("�����G�����ʡC\n");
	if( !interactive(who) )
	{
		if(who->accept_object(me, obj))
		{
			if(obj) obj->move(who);
			return 1;
		} else return 0;
	}
	if( obj->query("secured") )
			return notify_fail("�Х���[secure ���~�W off]�Ѱ��������O�s���A\n");
	if( obj->value() )
	{
		//destruct(obj);
		name=obj->short();
		if(obj->move(who))
		{
			message_vision("$N���X" + name + "��$n�C\n", me, who);
			if( me->is_fighting() ) me->add_block(1);
			return 1;
		}
		else
		{
			tell_object(who,me->name()+"�Q���A���i�O�A�����ʡC\n");
			return notify_fail(who->name()+"�����ʳo��h���C\n");
		}
	} else
	{
		name=obj->name();
		if( obj->move(who) )
		{
                write(sprintf("�A��%s�@%s%s�C\n", who->name(), obj->query("unit"),name));
			message("vision", sprintf("%s���A�@%s%s�C\n", me->name(),
				stringp(obj->query("unit"))? obj->query("unit") : "��", name), who );
			message("vision", sprintf("%s��%s�@%s%s�C\n", me->name(), who->name(),
				stringp(obj->query("unit"))? obj->query("unit") : "��", name), environment(me), ({me, who}) );
			if( wizardp(me) && !wizardp(who) && userp(who))
			{
				date=ctime(time());
				date=sprintf("%s",date[0..15]);
                                log_file( "static/give",sprintf("[%s] %s(%s) give %s(%s) %s[%s]\n",date,me->name(1),getuid(me),who->name(1),getuid(who),obj->name(1),base_name(obj)));
			}
			if( me->is_fighting() ) me->add_block(1);
			return 1;
		}
		else
		{

			tell_object(who,me->name()+"�Q���A"+name+"�i�O�A�����ʡC\n");
			return notify_fail(who->name()+"������"+name+"�C\n");
		}
	}
}
int help(object me)
{
write(@HELP
���O�榡 : give <���~�W��> to <�Y�H>
      �� : give <�Y�H> <���~�W��>
 
�o�ӫ��O�i�H���A�N�Y�˪��~���O�H, ��M, �����A�n�֦��o�˪��~.
 
HELP
    );
    return 1;
}

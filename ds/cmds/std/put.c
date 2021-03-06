// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string target, item; // str;

	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要將什麼東西放進哪裡﹖\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要放什麼東西﹖\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) ) return notify_fail("這裡沒有這樣東西。\n");
	if( dest->is_box() )
	{
		if(!dest->can_access_box()) return notify_fail("你必須先打開"+dest->name()+"才能放東西進去。\n");

	}
	
	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上沒有這樣東西。\n");
		if( obj==dest ) return notify_fail("來源和目的不能是相同的東西!\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分開。\n");
		if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"並不是一個容器。\n");
		if( obj->query_max_encumbrance() && !obj->query("no_get"))
			return notify_fail( "容器不能放到容器裡。\n");
		if( obj->query("no_drop") )
			return notify_fail( obj->name() + "不能被丟棄。\n");
    if( obj->query("no_put") )
	{
        // if( stringp(str) ) return notify_fail( str );
		return notify_fail( obj->name() + "不能放到容器中。\n");
	}
		if( amount < 1 )
			return notify_fail("東西的數量至少是一個。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(!obj2->can_move(dest))
			{
				destruct(obj2);
				return notify_fail("你沒有辦法把"+obj->query("name")+"放進"+dest->query("name")+"裡。\n");
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
		return notify_fail("你身上沒有這樣東西。\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	mixed no_put;
	string date;
	if( obj==dest ) return notify_fail("來源和目的不能是相同的東西!\n");
    if( obj->query("no_put") )
        {
        // if( stringp(str) ) return notify_fail( str );
                return notify_fail( obj->name() + "不能放到容器中。\n");
        }

	if( obj->query("equipped") ) return notify_fail( obj->name() + "正被你裝備著, 不能放到容器裡。\n");
	if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"並不是一個容器。\n");
	if( obj->query_max_encumbrance()  && !obj->query("no_get"))
			return notify_fail( "容器不能放到容器裡。\n");
	if( obj->query("no_drop") )
			return notify_fail( obj->name() + "不能被丟棄。\n");
	if( no_put = obj->query("no_drop"))
	{
		if(stringp(no_put)) return notify_fail( no_put+"\n");
		return notify_fail( "你無法把"+obj->name()+"放進那裡。\n");
	}
	if( obj->query_temp("riden") ) return notify_fail("你正在騎著耶!\n");
	if(!obj->can_move(dest)) return notify_fail("你沒有辦法把"+obj->query("name")+"放進"+dest->query("name")+"裡。\n");
	if( obj->query("secured") ) return notify_fail( obj->name() + "被你設定為保存狀態, 不能放到容器中。\n");
	if( obj->move(dest) )
	{
		message_vision( sprintf("$N將一%s%s放進%s。\n",
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
指令格式 : put <物品名稱> in <某容器>
 
這個指令可以讓你將某樣物品放進一個容器﹐當然﹐首先你要擁有這樣物品。
 
HELP
    );
    return 1;
}

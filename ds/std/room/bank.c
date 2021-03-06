// bank.c

inherit ROOM;

void init()
{
//	add_action("do_convert", "convert");
//	add_action("do_deposit", "deposit");
	this_object()->set("room_type","bank");
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;

	if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
		return notify_fail("指令格式﹕convert <數量> <貨幣種類> to <貨幣種類>\n");

	from_ob = present(from + "_money", this_player());
	to_ob = present(to + "_money", this_player());
	if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
		return notify_fail("你想兌換哪一種錢﹖\n");

	if( !from_ob )		return notify_fail("你身上沒有這種貨幣。\n");
	if( amount < 1 )	return notify_fail("兌換貨幣一次至少要兌換一個。\n");
		
	if( (int)from_ob->query_amount() < amount )
		return notify_fail("你身上沒有那麼多" + from_ob->query("name") + "。\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("這種東西不值錢。\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

	if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
	if( amount==0 )	return notify_fail("這些" + from_ob->query("name") + "的價值太低了﹐換不起。\n");

	if( !to_ob ) {
		to_ob = new("/obj/money/" + to);
		to_ob->move(this_player());
		to_ob->set_amount(amount * bv1 / bv2);
	} else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision( sprintf("$N從身上取出%s%s%s﹐換成%s%s%s。\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
		this_player() );

	from_ob->add_amount(-amount);

	return 1;
}


int do_deposit(string arg)
{
}

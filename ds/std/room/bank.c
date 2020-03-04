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
		return notify_fail("���O�榡�Rconvert <�ƶq> <�f������> to <�f������>\n");

	from_ob = present(from + "_money", this_player());
	to_ob = present(to + "_money", this_player());
	if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
		return notify_fail("�A�Q�I�����@�ؿ��S\n");

	if( !from_ob )		return notify_fail("�A���W�S���o�سf���C\n");
	if( amount < 1 )	return notify_fail("�I���f���@���ܤ֭n�I���@�ӡC\n");
		
	if( (int)from_ob->query_amount() < amount )
		return notify_fail("�A���W�S������h" + from_ob->query("name") + "�C\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("�o�تF�褣�ȿ��C\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

	if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
	if( amount==0 )	return notify_fail("�o��" + from_ob->query("name") + "�����ȤӧC�F�M�����_�C\n");

	if( !to_ob ) {
		to_ob = new("/obj/money/" + to);
		to_ob->move(this_player());
		to_ob->set_amount(amount * bv1 / bv2);
	} else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision( sprintf("$N�q���W���X%s%s%s�M����%s%s%s�C\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
		this_player() );

	from_ob->add_amount(-amount);

	return 1;
}


int do_deposit(string arg)
{
}

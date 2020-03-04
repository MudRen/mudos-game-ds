// finance.c
// can_afford() checks if this_object() can afford a price, it returns:
//
//	0:	cannot afford.
//	1:	can afford with proper money(coins).
//	�]���[�W�۰ʴ������\��....�ҥH�쥻�L�k�I�����Ǧ^�Ȥw�g�Τ���F......
//
// int pay_money(amount) 
//  �Хγo�ӨӰ��I�����ʧ@�� amount �����I����
//
//
// int receive_money(amount)
// �Хγo�ӨӰ��o�����ʧ@�� amount ���ұo�쪺��
//
//
//
//

int can_afford(int amount)
{
	int total;
	object gold, silver, coin;
        string env_dir, buffer1, buffer2;

        env_dir = base_name(environment());
        if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)!=2)
        {
        	return 0;
        }
        
	if(buffer1 == "world1")
	{
		gold = present("gold_money");
		silver = present("silver_money");
		coin = present("coin_money");
	}
	else if(buffer1 == "world2")
	{
		gold = present("t_dollar");
		silver = present("h_dollar");
		coin = present("dollar");
	}
	else if(buffer1 == "world3")
	{
		coin = present("money_card");
	}

	total = 0;

	if(buffer1 == "world3")
	{
		return 0;
	}
	else
	{
		if( gold )	total += gold->value();
		if( silver )	total += silver->value();
		if( coin )	total += coin->value();
	}
	
	if( total >= amount )
	{
		return 1;	//�Ǧ^ 1 ��ܦ������������ӥI��
	}
	else
	{
		return 0;	//�Ǧ^ 0 ��ܿ�������
	}
}

int pay_money(int amount)
{
	int total;
	object gold, silver, coin;
        string env_dir, buffer1, buffer2;

        env_dir = base_name(environment());
        if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)!=2)
        {
        	return 0;
        }

	if(buffer1 == "world1")
	{
		gold = present("gold_money");
		silver = present("silver_money");
		coin = present("coin_money");
	}
	else if(buffer1 == "world2")
	{
		gold = present("t_dollar");
		silver = present("h_dollar");
		coin = present("dollar");
	}
	else if(buffer1 == "world3")
	{
		coin = present("money_card");
	}

	total = 0;

	if(buffer1 == "world3")
	{
		return 0;
	}
	else
	{
		if( gold )	total += gold->value();
		if( silver )	total += silver->value();
		if( coin )	total += coin->value();
	}

	if( total < amount ) return 0;
	
	total -= amount;

	if(buffer1 == "world3")
	{
//		coin->set("card_value",total);	
		return 0;
	}
	if(gold)	destruct(gold);
	if(silver)	destruct(silver);
	if(coin)	destruct(coin);

	if(total >= 10000)
	{
		if(buffer1 == "world1")
		{
			gold = new("/obj/money/gold.c");
			gold -> move(this_player());
		}
		else if(buffer1 == "world2")
		{
			gold = new("/obj/money/t_dollar.c");
			gold -> move(this_player());
		}
		gold->set_amount( (int)(total/10000) );
		total %= 10000;
	}
	
	if(total >= 100 )
	{
		if(buffer1 == "world1")
		{
			silver = new("/obj/money/silver.c");
			silver -> move(this_player());
		}
		else if(buffer1 == "world2")
		{
			silver = new("/obj/money/h_dollar.c");
			silver -> move(this_player());
		}
		silver->set_amount( (int)(total/100) );
		total %= 100;
	}
	if( total )
	{
		if(buffer1 == "world1")
		{
			coin = new("/obj/money/coin.c");
			coin -> move(this_player());
		}
		else if(buffer1 == "world2")
		{
			coin = new("/obj/money/dollar.c");
			coin -> move(this_player());
		}
		coin->set_amount( total );
		return 0;
	}
}

int receive_money(int amount)
{
	int total;
	object gold, silver, coin;
        string env_dir, buffer1, buffer2;

        env_dir = base_name(environment());
        if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)!=2)
        {
        	return 0;
        }

	if(buffer1 == "world1")
	{
		gold = present("gold_money");
		silver = present("silver_money");
		coin = present("coin_money");
	}
	else if(buffer1 == "world2")
	{
		gold = present("t_dollar");
		silver = present("h_dollar");
		coin = present("dollar");
	}
	else if(buffer1 == "world3")
	{
		coin = present("money_card");
	}

	total = 0;

	if(buffer1 == "world3")
	{
		return 0;
	}
	else
	{
		if( gold )	total += gold->value();
		if( silver )	total += silver->value();
		if( coin )	total += coin->value();
	}

	if( total < amount ) return 0;
	
	total += amount;

	if(buffer1 == "world3")
	{
//		coin->set("card_value",total);	
		return 0;
	}
	if(gold)	destruct(gold);
	if(silver)	destruct(silver);
	if(coin)	destruct(coin);

	if(total >= 10000)
	{
		if(buffer1 == "world1")
		{
			gold = new("/obj/money/gold.c");
			gold -> move(this_player());
		}
		else if(buffer1 == "world2")
		{
			gold = new("/obj/money/t_dollar.c");
			gold -> move(this_player());
		}
		gold->set_amount( (int)(total/10000) );
		total %= 10000;
	}
	
	if(total >= 100 )
	{
		if(buffer1 == "world1")
		{
			silver = new("/obj/money/silver.c");
			silver -> move(this_player());
		}
		else if(buffer1 == "world2")
		{
			silver = new("/obj/money/h_dollar.c");
			silver -> move(this_player());
		}
		silver->set_amount( (int)(total/100) );
		total %= 100;
	}
	if( total )
	{
		if(buffer1 == "world1")
		{
			coin = new("/obj/money/coin.c");
			coin -> move(this_player());
		}
		else if(buffer1 == "world2")
		{
			coin = new("/obj/money/dollar.c");
			coin -> move(this_player());
		}
		coin->set_amount( total );
		return 0;
	}
}



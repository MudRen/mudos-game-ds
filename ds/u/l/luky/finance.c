// finance.c
// can_afford() checks if this_object() can afford a price, it returns:
//
//	0:	cannot afford.
//	1:	can afford with proper money(coins).
//	因為加上自動換幣的功能....所以原本無法兌換的傳回值已經用不到了......
//
//
//
// int receive_money(amount)
// 請用這個來做得錢(付錢)的動作∼ amount 為所得到的錢 (當 amount > 0 )
// 若 amount 為負值則為 付錢
//
//
//
int money_type()
{
	string env_dir, buffer1, buffer2;
        
        env_dir = base_name(environment());
        if(sscanf(env_dir,"/open/%s/%s",buffer1,buffer2)!=2)
        {
        	return 0;
        }
        
	if(buffer1 == "world1")
	{
		return 1;
	}
	else if(buffer1 == "world2")
	{
		return 2;
	}
	else if(buffer1 == "world3")
	{
		return 3;
	}

	return 0;

}

int money_count(int flag)
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
	if(flag)
	{
	 if(gold)	destruct(gold);
	 if(silver)	destruct(silver);
	 if(coin)	destruct(coin);
	}
	return total;
}

int can_afford(int amount)
{
	int total;

	total = money_count(0);
	if( total >= amount )
	{
		return 1;	//傳回 1 表示有足夠的錢幣來付款
	}
	else
	{
		return 0;	//傳回 0 表示錢幣不足
	}
}


int receive_money(int amount)
{
	int total,type;
	object gold, silver, coin;
        
	total = money_count(0);
	total += amount;
	if( total < 0 ) return 0;
	money_count(1);	//加上flag = 1 表示清除金錢
	type = money_type();
	if(type == 3)
	{
//		coin->set("card_value",total);	
		return 0;
	}

	if(total >= 10000)
	{
		if(type == 1)
		{
			gold = new("/obj/money/gold.c");
		}
		else if(type == 2)
		{
			gold = new("/obj/money/t_dollar.c");
		}
		else 
		  {
		  	gold = new("/obj/money/gold.c");
		  }
		gold->set_amount( (int)(total/10000) );
		gold -> move(this_player());
		total %= 10000;
	}
	
	if(total >= 100 )
	{
		if(type == 1)
		{
			silver = new("/obj/money/silver.c");
		}
		else if(type == 2)
		{
			silver = new("/obj/money/h_dollar.c");
		}
		else 
		 {
		 	silver = new("/obj/money/silver.c");
		 }
		 
		silver->set_amount( (int)(total/100) );
		silver -> move(this_player());
		total %= 100;
	}
	if( total )
	{
		if(type == 1)
		{
			coin = new("/obj/money/coin.c");

		}
		else if(type == 2)
		{
			coin = new("/obj/money/dollar.c");
		}
		else //一般巫師路徑
		  {
		   	coin = new("/obj/money/coin.c");
		  }
		  
		coin->set_amount( total );
		coin -> move(this_player());
	}
	return amount;
}



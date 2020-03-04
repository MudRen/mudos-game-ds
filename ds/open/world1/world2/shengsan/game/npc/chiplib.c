// chiplib.c			Shengsan@DS	1999.4.4
// 遊樂場內籌碼的應用函式

/*
 *  計算籌碼數
 */
int Game_chip_count(int flag, object me)
{
	int total;
	object gamechip;


	gamechip = present("game_money",me);
	if(!gamechip) return 0;	// 如果沒有籌碼就傳回 0

	total = 0;
	total += gamechip->value();


	if(flag && gamechip)	// 如果有 flag 就消除籌碼
		destruct(gamechip);

	return total;
}

/*
 *  判斷是否有足夠的籌碼來付
 */
int Game_can_afford(int amount, object me)
{
	int total;

	total = Game_chip_count(0,me);
	if( total >= amount )
	{
		return 1;	//傳回 1 表示有足夠的籌碼來付
	}
	else
	{
		return 0;	//傳回 0 表示籌碼不足, 或沒有籌碼
	}
}

/*
 *  對籌碼作加減的動作
 */
int Game_receive_chip(int amount, object me)
{
	int total;
	object chip;
        
	total = Game_chip_count(0,me);
	total += amount;
	if( total < 0 ) return 0;
	Game_chip_count(1,me);	//加上flag = 1 表示清除籌碼

	chip = new("/obj/money/gamechip.c");
	chip -> set_amount( total );
	chip -> move(me);
	return 1;
	
}
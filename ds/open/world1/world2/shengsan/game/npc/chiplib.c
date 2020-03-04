// chiplib.c			Shengsan@DS	1999.4.4
// �C�ֳ����w�X�����Ψ禡

/*
 *  �p���w�X��
 */
int Game_chip_count(int flag, object me)
{
	int total;
	object gamechip;


	gamechip = present("game_money",me);
	if(!gamechip) return 0;	// �p�G�S���w�X�N�Ǧ^ 0

	total = 0;
	total += gamechip->value();


	if(flag && gamechip)	// �p�G�� flag �N�����w�X
		destruct(gamechip);

	return total;
}

/*
 *  �P�_�O�_���������w�X�ӥI
 */
int Game_can_afford(int amount, object me)
{
	int total;

	total = Game_chip_count(0,me);
	if( total >= amount )
	{
		return 1;	//�Ǧ^ 1 ���ܦ��������w�X�ӥI
	}
	else
	{
		return 0;	//�Ǧ^ 0 �����w�X����, �ΨS���w�X
	}
}

/*
 *  ���w�X�@�[��ʧ@
 */
int Game_receive_chip(int amount, object me)
{
	int total;
	object chip;
        
	total = Game_chip_count(0,me);
	total += amount;
	if( total < 0 ) return 0;
	Game_chip_count(1,me);	//�[�Wflag = 1 ���ܲM���w�X

	chip = new("/obj/money/gamechip.c");
	chip -> set_amount( total );
	chip -> move(me);
	return 1;
	
}
// coin.c

inherit MONEY;

void create()
{
	set_name("��", ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "�o�O�y�q�����̤p���f���M���n�@�ʤ���~�ȱo�@��Ȥl�C\n");
		set("unit", "��");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
	}
	set_amount(1);
}


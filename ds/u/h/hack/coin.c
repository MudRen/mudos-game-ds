// coin.c

inherit MONEY;

void create()
{
	set_name("�j��", ({"coin", "coins", "past_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "�o�O�j�N�y�q�����f��, �O�H�»ɥ��y�Ӧ����C\n");
		set("unit", "��");
		set("material", "copper"); //�ɻs�~
		set("base_value", 1);
		set("base_unit", "�T");
		set("base_weight", 1);
		set("base_volume", 0.0002);
	}
	set_amount(100000);
}



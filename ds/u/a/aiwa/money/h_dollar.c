// coin.c

inherit MONEY;

void create()
{
	set_name("�{��", ({"h_dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "h_dollar");
		set("long", "�o�O�{�N�y�q�����ʤ��f���C\n");
		set("unit", "��");
		set("base_value", 100);
		set("base_unit", "�i�ʤ�");
		set("base_weight", 1);
	}
	set_amount(1);
}


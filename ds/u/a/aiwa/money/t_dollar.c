// coin.c

inherit MONEY;

void create()
{
	set_name("�{��",({"t_dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "t_dollar");
		set("long", "�o�O�{�N�y�q�����U���f���C\n");
		set("unit", "��");
		set("base_value", 10000);
		set("base_unit", "�i�U��");
		set("base_weight", 1);
	}
	set_amount(1);
}


// coin.c

inherit MONEY;

void create()
{
	set_name("����",({"golden dollar","dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "dollar");
		set("long", "�ѯª����y�Ӧ�������, �O�{�N�y�q�����f���C\n");
		set("unit", "��");
		set("base_value", 1);
		set("base_unit", "�T");
		set("base_weight", 1);
		set("base_volume", 0.0002);
	}
	set_amount(1);
}



// coin.c

inherit MONEY;

void create()
{
	set_name("�{��",({"dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "dollar");
		set("long", "�o�O�{�N�y�q�����̤p���f���C\n");
		set("unit", "��");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
	}
	set_amount(1);
}


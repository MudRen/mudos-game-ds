// coin.c

inherit MONEY;

void create()
{
	set_name("現金",({"dollar"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "dollar");
		set("long", "這是現代流通中單位最小的貨幣。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "元");
		set("base_weight", 1);
	}
	set_amount(1);
}


// gold.c

inherit MONEY;

void create()
{
	set_name("金元寶", ({"gold ingot", "gold" , "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
		set("long", "黃澄澄的金子﹐人見人愛的金子﹐市面上的價值相當於100兩銀子﹗\n");
		set("unit", "些");
		set("base_value", 10000);
		set("base_unit", "錠");
		set("base_weight", 250);
	}
	set_amount(1);
}




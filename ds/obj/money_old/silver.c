// silver.c

inherit MONEY;

void create()
{
	set_name("�Ȥl", ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "�ժ�᪺�Ȥl�M�H���H�R���Ȥl�C\n");
		set("unit", "��");
		set("base_value", 100);
		set("base_unit", "��");
		set("base_weight", 37);
	}
	set_amount(1);
}


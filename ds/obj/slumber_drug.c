// slumber_drug.c

inherit POWDER;

void create()
{
	set_name("�X����", ({ "slumber drug", "drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"�o�O�M�`����L�s��Ψӧ@�ת��X���ġM�A�i�H�⥦��(pour)�b\n"
			"�s�������ϥΡC\n" );
		set("unit", "�]");
		set("base_value", 20);
		set("base_unit", "��");
		set("base_weight", 30);
	}
	set_amount(1);
}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") + 100 );
	return 0;
}



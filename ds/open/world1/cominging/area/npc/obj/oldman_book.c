inherit ITEM;

void create()
{
	set_name("�p�U�l", ({ "book", "wu_lin_me_gei" }));
	set("long", "�o�O�@���p�U�l, �W���O���۳\\�h�Z�\\. \n");
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 1);
		set("no_sell", 1);
		set("no_sac", 1);
	}
	setup();
}
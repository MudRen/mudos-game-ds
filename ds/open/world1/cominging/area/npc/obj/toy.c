inherit ITEM;
void create()
{
	set_name("����",({ "toy" }));
	set_weight(1000);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�Ӥp�Ĥl��������C\n");
		set("unit","��");
		set("value",50);
	}
	setup();
}
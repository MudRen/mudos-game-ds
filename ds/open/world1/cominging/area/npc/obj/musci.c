inherit ITEM;
void create()
{
	set_name("���a",({ "musci" }));
	set_weight(200);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�رq���t�B�Ҩ�U���F��C\n");
		set("unit","��");
		set("value",10);
	}
	setup();
}
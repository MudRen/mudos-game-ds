inherit ITEM;

void create()
{
	set_name("����",({"woo-ton tree","tree"}));
	set("long","����b�˪L������O�ܴ��M�����C\n");
	set_weight(9999);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("no_get",1);
	}
	setup();
}
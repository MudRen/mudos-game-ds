inherit ITEM;

void create()
{
	set_name("�J��",({"ash"}) );
	set_weight(10);
	set("long","�@��J�ǡA�w�ݤ��M��Ӫ��ˤl�C\n");
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	set("unit","��");
	set("value",0);
	set("no_sac",1);
	}
	setup();
}
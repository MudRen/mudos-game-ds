inherit ITEM;

void create()
{
	set_name("�Ѯv�D��", ({ "taoist charm", "charm" }));
	set("long", "�D�h�b�I�k�ɩҥΪ��D�šC\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "�i");
		set("value", 100);
	}
	setup();
}
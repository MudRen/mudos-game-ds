inherit ITEM;

void create()
{
	set_name("�j����", ({ "rockslide", "stone", "stack-road" }));
	set("long", "�@�ӫܤj������, �O�q�s�W�Ƹ��U�Ӫ�. \n");
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 0);
		set("no_sac", 1);
		set("no_get", 1);
		set("no_sell",1);
	}
	setup();
}
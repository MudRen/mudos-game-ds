inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����",({"chisel meat","meat"}) );
	set("long","�@���q���稭�W���U�Ӫ��סA�¥ե���A�����ण��Y�C");
	set_weight(200);	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",500);
          set("food_remaining",5);
          set("heal_ap",30);
	}
	setup();

}

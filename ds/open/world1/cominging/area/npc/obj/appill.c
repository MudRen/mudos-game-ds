inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("�^����", ({ "recover pill","pill" }));
    set("long","�^�����O�M���ղz���O�M�u���Ĥ��A�ܦn�ΡC\n");
	set("weight", 300);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",200);
        set("heal_ap",40);
        set("food_remaining", 1);
	}
	setup();
}

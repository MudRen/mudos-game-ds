inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
    set_name("�Ŧ�N��", ({ "blue-gimi wine","blue","gimi","wine" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
�o�M�հs�ΤF�j�q���Ų��ĻP�ܩi�s�A�ҥH�e�{�X�`�Ŧ�C
LONG);
		set("unit", "�M");
	}
	set("value", 200);    
	set("heal_mp",50);
	set("heal_ap",50);
	set("water_remaining", 1);
	setup();
	f = (: call_other, __FILE__, "do_drunk" :);
	set("water/function",f);
}

int do_drunk()
{
	this_player()->apply_condition("drunk", this_player()->query_condition("drunk")+8);
	return 1;
}

inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("��s", ({ "beer" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
�@�ؤj���C�����s���C
LONG);
		set("unit", "�~");
	}
	set("value", 80);    
	set("heal_ap",10);
	set("water_remaining", 1);
	setup();
	f = (: call_other, __FILE__, "do_drunk" :);
	set("water/function",f);
}

int do_drunk()
{
	this_player()->apply_condition("drunk", this_player()->query_condition("drunk")+4);
	return 1;
}
inherit ITEM;
inherit F_WATER;
void create()
{
	set_name("��s", ({ "beer" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@�ؤj���C�����s���C\n");
		set("unit", "�~");
		set("value", 180);    
		set("heal_mp",20);
		set("water_remaining", 3);
	}
	setup();
}

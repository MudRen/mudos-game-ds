inherit ITEM;
void create()
{
	set_name("�����",({ "green crystal","crystal" }) );
	set_weight(1700);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�@���Ѻ�⪺�����H���C

LONG);
		set("unit", "��");
		set("material","glass");
	}
	setup();
	set("value",1000);
	set("volume",1);
}

int is_crystal() { return 1; }
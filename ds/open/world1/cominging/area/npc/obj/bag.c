inherit ITEM;

void create()
{
	set_name("�p���U", ({ "small bag","bag" }) );
	set_weight(500);
	set_max_capacity(8);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�f");
		set("long", "�o�O�@�f�M�`�����U�M�i�H�ΨӸˤ@�������C\n");
		set("volume",3);
    set("value",20);
	}
	setup();
}

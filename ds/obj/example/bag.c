// bag.c

inherit ITEM;

void create()
{
	set_name("���U", ({ "bag" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�f");
		set("long", "�o�O�@�f�M�`�����U�M�i�H�ΨӸˤ@�������C\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

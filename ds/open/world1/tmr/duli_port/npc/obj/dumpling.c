// manto.c

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
	set_name("��]�l", ({ "dumpling" }));
	if( !clonep() ) {
		set("unit", "��");
		set("base_unit", "��");
		set("base_value", 10);
		set("base_weight", 100);
		set("food_stuff", 100);
		set("long", "�@�ӭ��Q�Q����]�l�A�����@�Ӯ��Y�j�A�Y�_�ӫܦ������P�C\n");
	}
	setup();
}


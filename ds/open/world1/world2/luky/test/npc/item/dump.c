// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�j�N�]", ({ "dump" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@�ӭ��Q�Q�B�����˪��j�N�]�C\n");
		set("unit", "��");
		set("value", 15);	//�Ѧһ��欰�^�_�I���`�M���H5
		set("heal_hp",20);	//�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
		set("food_remaining", 3);
	}
	setup();
}

// hamburg.c

inherit shop;
inherit F_FOOD;

void create()
{
    set_name("�j�~��", ({ "hamburg" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@�ӭ��Q�Q�B�����˪��j�N�]�C\n");
		set("unit", "��");
		set("value", 40);	//�Ѧһ��欰�^�_�I���`�M���H5
		set("heal_hp",10);	//�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
		set("heal_mp",10);
		set("food_remaining", 3);
	}
	setup();
}

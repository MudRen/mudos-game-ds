// dumpling.c

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("��s", ({ "beer" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@�~�ܴ��q����s�C\n");
		set("unit", "�~");
		set("value", 16);	//�Ѧһ��欰�^�_�I���`�M���H5
		set("heal_mp",20);	//�i�H�O"heal_hp"�άO"heal_mp",�]�i�H����.
		set("water_remaining", 3);
	}
	setup();
}

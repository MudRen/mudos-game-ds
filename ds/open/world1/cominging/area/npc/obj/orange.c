inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�h��", ({ "orange" }));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@�ӱq���`�Ф��ҺK�U�����G�A�i�H���ΡA�Y�F�i�H�ɥR��O�C\n");
		set("unit","��");
	}
	set("value", 160);
	set("heal_ap", 20);
	set("water_remaining",2);
	setup();
}
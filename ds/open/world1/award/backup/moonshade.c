#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"����Z"NOR, ({ "moonglow armor","armor" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���_�ҥ~�h���z�ե�, ���p���뤧��, �b�դѴN�w�g\n"
                           "�{�{�o��, �]�ߧ�O�G�o�p�P�@������, ��O�@��۷����o\n"
			   "���_��.\n");
		set("unit", "��");
		set("material","steel");
	set("value",1);
		set("needaward",35);
	}
        set("armor_prop/con",3);
	set("armor_prop/int",3);
	set("armor_prop/dodge",5);
	set("armor_prop/shield",20);
	set("armor_prop/armor",40);
	setup();
}

int query_autoload() { return 1; }

void init()
{
 if( environment(this_object()) == this_player() )
  this_player()->set_temp("has_light",1);
}

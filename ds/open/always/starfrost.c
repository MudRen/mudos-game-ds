#include <armor.h>
#include <ansi2.h>

inherit PANTS;

void create()
{
     set_name(HIY"�[��"HIC"�P��"NOR, ({ "Lazurite star frost", "frost" }) );
	set_weight(10000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("long", @long
�o��˳ƶǻ��O�q�ӥj�ɥN�y�Ǧܤ����A�ڻ��@���Q�G��W�K�@
�P���y�Ӧ����C���D�n�����ƬO�[���A�٦��ǳ\���B�A�B�����A
���ݰ_�Ӫ���z���A�o�S���o�ۤ��Z�����~�A���P���B�S���B
���A�G�j�H�R��y�[���P���z�C

Mid-Autumn Festival Gifts By -Alickyuen@The.Dream.Of.Seven
long);
		set("unit", "��");
                set("value", 1);
                set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sac", 1);
		set("material", "diamond");
	}
	set("armor_prop/wit", 1);
	set("armor_prop/shield",15);
	set("armor_prop/armor",25);
	setup();
}

int query_autoload() { return 1; }

void init()
{
	object me= this_player();

	if( !me ) return;
	if( environment(this_object()) == me )
	{
		if( !this_object()->query_light() ) this_object()->start_light(1);
  	}
}

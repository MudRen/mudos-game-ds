#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("�Q�F�U" ,({ "Ossifer's hat","hat" }) );
	set_weight(1000);
	set("long","�o�O�@�����ѷݥ��ɩҬ�����A�o���U�l�N��ۡu�v�Q�v�C\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material","cloth");
		set("unit", "��" );
		set("value",500);
	}
	set("armor_prop/armor", 3);
	set("armor_prop/int",1);
	setup();
} 

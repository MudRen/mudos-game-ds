#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
        set_name("�g�q��M", ({ "toast gloves", "gloves" }) );
        set_weight(500);
		set("long", "�۷�u������M�A�O�g�H�ڸs���q������������A�i�H�[�j�{����O�C");
		set_weight(700);
		if( clonep() )
			set_default_object(__FILE__);
		else 
		{
			set("unit", "��");
			set("volume",2);
			set("value",5000);
			set("material","fur");
		}
 		set("armor_prop/armor", 5);
 		set("armor_prop/dex", 1);
 		set("armor_prop/dodge", 5);
        setup();
}


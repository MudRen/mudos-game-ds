#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name("�¥ɤ��N" ,({ "black jade bangle","bangle" }) );
	set_weight(800);
	set("long","�o�Ӷ¥ɤ��N��u��ӡA�ר�O�Ѷ¥ɩҳy�A�ꬰ�@�����_�C\n");
	if ( clonep() )
	      set_default_object(__FILE__);
	else {
         set("material","jade");
		set("unit", "��" );
          set("value",400);
	}
	set("armor_prop/armor", 1);
	set("armor_prop/shield", 1);
	set("armor_prop/hit",3);
	setup();
} 

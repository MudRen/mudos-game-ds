#include <armor.h>
inherit SURCOAT;
void create()
{
	set_name("¸���ܭ�",({"surcoat"}));
	set_weight(980);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ܥ��`���ܭ��C\n");
                set("value", 200);                                             
		set("armor_prop/armor", 2);  
	}
	setup();
}    

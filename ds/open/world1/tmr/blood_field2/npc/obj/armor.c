#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("�����", ({  "field armor", "armor" }) );
		set("long", "�o�O�@��Ѧ�{����o�����ҡA�`�Q�y���b���䪺���]����ۡC\n");
        set_weight(3000);

		if ( clonep() )
  			 set_default_object(__FILE__);
		else {
                set("unit", "��");
                set("value", 500);   
                set("material", "iron");
        }
		set("armor_prop/armor",10);
        setup();
}



#include <armor.h>
inherit HEAD;

void create()
{
	set_name("�B���U",({"sun cap","cap"}) );
	set("long","�@���U�u��j���B���U�A�b�������U�A���W�o���U�l�A�ˤ]�D�n���֡C\n");
    set_weight(200);
	if (clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","��");
      set("value",30);           
      set("armor_prop/armor",1);
	}
	setup();
}


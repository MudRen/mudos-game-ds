#include <weapon.h>
inherit BLADE;

void create() {
        set_name("�ٰ��j�M" ,({"cutbone blade","blade"}));
        set("long",@LONG
�@��q�������j�M�A�N�s��w�����Y�A�]�i�H�����a�ٸH�C
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	        set("unit", "��");        
	        set("value",1000);
	        set("volume",4);        
	        set("material","bone");       
		}
        set("weapon_prop/str",1);
        set("weapon_prop/con",1);
        init_blade(40);
        setup();
}    

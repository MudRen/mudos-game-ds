#include <weapon.h>
inherit AXE;

void create() 
{
        set_name("����",({"huge axe","axe"}));
        set("long",@LONG
�o�O�@��Q�����j���۩�A���F�G�Q�禳�l�A�u�O���t���H�ڥ��N�����ʡC
LONG
);
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");        
                set("value",200);
                set("volume",5);        
                set("material","stone");      
        }        
        init_axe(30);
        set("weapon_prop/str",1);
        set("weapon_prop/dex",-1);
        setup();
}    



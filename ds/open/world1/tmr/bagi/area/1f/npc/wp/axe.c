#include <weapon.h>

inherit AXE;

void create()
{
        set_name("�u��",({"short axe","axe"}) );
        set("long","�@�⤣�j���u��A�j�b���O�Q���Ӷ}�s�P�L�Ϊ��C\n");
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
              set("volume",2);
              set("value",1000);
        }
        init_axe(10);
        setup();        
}


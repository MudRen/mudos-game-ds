#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("����",({"cloth"}) );
        set("long","�`��������A���U�ؼ˦��A������N�O����C\n");
        set_weight(300);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",100);
                set("volume",1);
                set("armor_prop/armor",1);
        }
        setup();
}



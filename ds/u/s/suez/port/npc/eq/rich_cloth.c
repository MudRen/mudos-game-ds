#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�تA",({"cloth"}) );
        set("long","�Q�����R����A�A�ΰ��Ū����ƻs���C\n");
        set_weight(300);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",1500);
                set("volume",1);
                set("armor_prop/armor",1);
        }
        setup();
}




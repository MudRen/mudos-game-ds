#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�k�ʮM��",({"dress"}) );
        set("long","�������M�ˡA�i�HŨ���X�ת������q�H�Υj�媺���C\n");
        set_weight(300);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",150);
                set("volume",1);
                set("armor_prop/armor",1);
        }
        setup();
}




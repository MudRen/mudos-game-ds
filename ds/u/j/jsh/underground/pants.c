#include <armor.h>

inherit PANTS;

void create()
{
        set_name("�}�}��",({"holes pants","pants"}) );
        set("long","�@��Ѱ��ť���´���A�ݨӺ��@�諸�C\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",3);
                set("unit","��");
                set("value",1000);
          set("armor_prop/armor",10);
        }
        setup();
}


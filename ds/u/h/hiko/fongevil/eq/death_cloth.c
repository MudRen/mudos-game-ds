#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("����",({"death cloth","cloth"}) );
        set("long",@long
  �N�O���H�U���ɬ諸��A�A�ݨӤQ���޲��C
long
);
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",3);
                set("unit", "��");
                set("value",3500);
                set("limit_lv",8);
                set("armor_prop/str",2);
                set("armor_prop/armor",10);
        }
        setup();
}



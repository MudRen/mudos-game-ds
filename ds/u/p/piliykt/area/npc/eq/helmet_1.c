#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(MAG "�R�ѫa" NOR,({ "chung-sky-guan","guan"}) );
        set("long","�ѩ]���B�A���y�Ӧ�,�b�R�ѫa������,�٦��@�Ӥp�]�l\n");
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "jade");
                set("unit","��");
        }
        set("value",3500);
        set("limit_lv",25);
        set("armor_prop/armor",12);
        set("armor_prop/str",1);
        set("armor_prop/con",1);
        set("armor_prop/int",1); 
        setup();
        set("volume",3);
}


#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(HIY "��"NOR+YEL"�s"HIM"�u"NOR+MAG"��" NOR,({ "dragon helmet","helmet"}) );
        set("long","������ɬy�J���g�A�K�Q�߷R��v�������հ��R���C\n");
        set_weight(2800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit","��");
        }
        set("value",4000);
        set("limit_lv",30);
        set("armor_prop/armor",16);
        set("armor_prop/str",1);
                setup();
        set("volume",2);
}



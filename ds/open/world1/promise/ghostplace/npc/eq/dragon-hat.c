#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(HIY "亢"NOR+YEL"龍"HIM"守"NOR+MAG"盔" NOR,({ "dragon helmet","helmet"}) );
        set("long","不知何時流入中土，便被喜愛西洋物的火幽鬼買取。\n");
        set_weight(2800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit","頂");
        }
        set("value",4000);
        set("limit_lv",30);
        set("armor_prop/armor",16);
        set("armor_prop/str",1);
                setup();
        set("volume",2);
}



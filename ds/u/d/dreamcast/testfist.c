#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HIY"�����ĳ���"NOR,({"sun-snow-fist","fist"}) );
        set("long",
"�@��ݨӪ��~�|�g���Q���A�N�b��̻ᬰ���S�C\n"
);
        set_weight(2000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","��");
          set("value",3000);
        set("material","gold");
                set("volume",2);


        }
        init_fist(70);
setup();
}


#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(HIY "���C" NOR,({ "gold zar","zar" }) );
        set("long","���C�ѯ¶������y�Ӧ����Y���A�ݨӻ��ȫD�Z�C\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit","��");
        }
        set("value",1000);
        
        set("armor_prop/armor",4);
        set("armor_prop/int",1);
           setup();
        set("volume",3);
}


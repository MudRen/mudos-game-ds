#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(HIY "�����в�" NOR,({ "gold helmet","helmet"}) );
        set("long","�����в��ѯ¶������y�Ӧ����Y���A�ݨӻ��Ȥ���C\n");
        set_weight(2400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        	set("material", "gold");
        	set("unit","��");
        }
        set("value",3300);
        set("limit_lv",20);
        set("armor_prop/armor",15);
        set("armor_prop/str",1);
        set("armor_prop/dex",-1);
        setup();
        set("volume",3);
}

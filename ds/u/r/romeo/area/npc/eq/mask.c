#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name("����",({ "ghost-mask","mask" }) );
        set("long",
"�@�㮣�ƪ�����A����W�誺���y�Q�����ơA�J�Ӥ@�ݡC�A�n
��ı�o����W����䲴�������ۧA�ݡI�C\n"
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",3);
        set("armor_prop/con", -1);
        }
        setup();
}


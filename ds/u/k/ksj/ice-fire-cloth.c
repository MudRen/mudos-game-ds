#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"�[�t"HIR"�����T"HIR"(S)"NOR ,({ "ice-fire cloth","cloth" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
�H�B�����Τ�������´�Ӧ�����A�A��A�W¸���U�a���s�������A��
�Ȩ��@�O�W�s�A����A��O���o�@�������N�~�C
LONG
     );
        set("unit", "��");
        set("value",20000);
        set("material", "fur");
        set("armor_prop/armor", 26);
        }
        setup();
}

int query_autoload() { return 1; }

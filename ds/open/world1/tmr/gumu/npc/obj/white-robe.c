#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW "�ճT" NOR, ({"white robe", "robe"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"�o�O��λ���´�����զ���T�A���M�o����T�S������¸�ˡA\n"
"���O�Ů�o�y�A��b���W��R���i�{�����j�誺�Pı�C\n"
                                );
                set("material", "silk");
                set("limit_lv",15);
                set("armor_prop/armor", 8);
                set("armor_prop/shield", 5);
                set("armor_prop/int", -1);
                set("armor_prop/dex", 1);
                set("value", 1500);
        }
        setup();
}


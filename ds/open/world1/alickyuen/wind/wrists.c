#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
        set_name(HIW"�U�F�@��"NOR, ({ "wan ling wrists", "wrists" }));
        set("long", "�o�O�e�����j�̤l�U�A�F�M�Ϊ��@�áAť���O�Ѱa�կP�e���o���C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(500);
                set("material", "linen");
                set("unit", "��");
                set("value", 5000);
        }
        set("armor_prop/armor", 10);
        set("armor_prop/tec", 1);
        set("armor_prop/bar", -1); // 2003.5.2  by ksj
        setup();
}

#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("��L�۾c", ({ "none boots","boots" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���ѪŮ���l�Ʀ����媬���i�ĩʾc�l�C\n");
                set("unit", "�i");
                set("material", "sheet");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1000);          
                set("wear_msg", "$N���}�W��¶�۴X�\\�z���H���u��V�y�ʡC\n");
                set("unequip_msg", "$N�}�|�P���Ů𰱤�y�ʤF�C\n");
           }
        set("armor_prop/dodge",7);
        set("armor_prop/armor",-4);
        setup();
}


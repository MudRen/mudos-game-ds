#include <armor.h>
inherit NECK;
void create()
{
        set_name("�W��O��", ({ "magic power necklace","necklace" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@��ѤT�d�֯S���q�O�涰�Ӧ����z���_�ҡC\n");
                set("unit", "��");
                set("material", "gold");
                set("no_sell",1);
                set("no_sac",1);
                set("value",700);          
                set("wear_msg", "$N���������O���E���l�W, �n���Φ��F�@������\n");
                set("unequip_msg", "$N���믫�@�ӫ鱫, $n��M�����F�C\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",5);
        setup();
}



#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("�q�ϥ���", ({ "power armor","armor" }) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@��ѤT�d�֯S���q�O�涰�Ӧ����z���_�ҡC\n");
                set("unit", "��");
                set("material", "gem");
                //set("no_sell",1);
                set("no_sac",1);
                set("value",1700);          
                set("wear_msg", "$N�����W��M�ĥX�X�D�q���]���$N�C\n");
                set("unequip_msg", "$N���F�@�Ӷ}��, �q���b���@�b�����������L�v�L�ܡC\n");
           }
        set("armor_prop/shield",15);
        set("armor_prop/dodge",5);
        set("armor_prop/armor",20);
        setup();
}



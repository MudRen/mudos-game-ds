#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(CYN "�C���~��" NOR,({ "copper armor","armor" }) );
        set("long",@LONG
�o�O�@�ƨϥΫC�ɤ��~�ְ������~�ҡA���U�F���m�ΫO�x���@�ΡA�̾A�X
�`�~�b�Գ��W���H�ϥΡC
LONG
);
        set_weight(22500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "silver");
        set("unit", "��" );
        }
        set("limit_con",30);
        set("limit_lv",25);
        set("value", 5000);
        set("armor_prop/armor", 30);
        set("armor_prop/dex", -2);
        set("armor_prop/con",  1);
        setup();
}



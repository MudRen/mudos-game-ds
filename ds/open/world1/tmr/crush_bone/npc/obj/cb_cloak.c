#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIW "�H���ӳT" NOR, ({ "crush bone armor", "armor" }) );
        set_weight(1000);

        if( !clonep() ) {
                set("unit", "�M");
                set("value", 18000);
                set("long",@long
    �o�O�@��Q�����Ū��ӳT�A���H����ӫҪ��@���v�O���x�C�W��
�^�������u�p�������W���ݤ��A��W�K�F�X�\�®e���Pı�C
long
                );
                set("armor_prop/armor", 10);
                set("armor_prop/con", 2);
                set("armor_prop/str", 2);
        } else 
                     set_default_object(__FILE__);

        setup();
}


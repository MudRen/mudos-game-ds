#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name( "�s��q�Ѳ���" ,({ "dragon-tiger armor","armor" }) );
        set("long",@LONG
�s��O�ۦW�����u���~�A��ӷ��󯳺~�|�F�����s��R���C
�D�ѱ`�⥦�̴y�z������Ϊ��}�O�C�ӳo�O�@�ƨϥ��s���~�֩�
���������ҡC
LONG
);
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("volume",6);
                set("unit", "��" );
                set("limit_con", 30);
                set("limit_level", 20);
                set("value", 5000);
                set("armor_prop/armor", 40);
                set("armor_prop/int",1);
        }
        set("beast_armor_prop/armor",40);
        set("beast_armor_type","armor");
        setup();
}


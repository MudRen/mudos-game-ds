#include <weapon.h>
#include <ansi.h>

inherit AXE;
inherit F_UNIQUE; // only one

void create()
{
        set_name( HIW "�H��" NOR, ({ "crush bone axe","axe" }) );
        set_weight(12000);
        init_axe(77);

        if( !clonep() ) {
                set("unit", "��");
                  set("value" ,10000);
                set("long",@long
�H���O�@��Q�����j�����Y�A�۶Ǧb�Ʀʦ~�e�A�ѤѪŸ��U���D�`�_
�S���q�ۡA��a��w�ӹL�o�@�ɤW�s�b�������q���A�ӥB�D�`�a���C�̫�
�O�ѸH���뤤�Ʀʭӱj�����b�~�H�̡A���g�Ʀ~���ɶ��~�N���q�ۥ��y��
�@�⥨��A�̫�]�N�ܦ��H���뤤�y�ǼƥN���_���C
long
        );
        set("replica_ob",__DIR__"huge-axe");
        set("material","iron");
        set("weapon_prop/str", 6);
        set("weapon_prop/damage", 10);
        set("limit_str", 40);
        set("limit_level",40);

        } else 
                     set_default_object(__FILE__);

        setup();
}


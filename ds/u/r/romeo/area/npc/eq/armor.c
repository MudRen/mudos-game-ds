#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIB "�U���N�x�Z" NOR,({ "general-armor","armor" }) );
        set("long",
"�ҿפ@�N�\���U���\�I�o��}�ª��Z�ҥ�O�p���A������
�h�ֱN���L�L�b�Գ����ġA�������h�֤H�R�b�L���e�@�@�f���C
�b���A�d�s�A�ͤ��������Գ��W����Ʀʦ~���Z�ҡA��N�����H
�̫᪺�N�@�E���_�ӡC�h�W�A����A���h���H�H�L�̪��N�ӱN�o��
�Z����y���@��㦳�F�ʪ��Z�ҡI���F�ͦs�Ӧs�b���Z�ҡI�C\n"
);
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/dex", -2);
        }
        setup();
}


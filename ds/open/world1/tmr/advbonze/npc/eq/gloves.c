#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIW "�N������" NOR ,({ "lucky gloves","gloves" }) );
        set("long",@LONG
�N�����جO�@���H����Ϯ׬��D���@��A�u��¸�u��ӡA�N����X�J�d
�Ӥ��g�V�b�I���Ъ��믫�A��{�o�D�`�ͰʡC�o���@�⥿�ϭ���¸���F�U��
�U�˪�����A�p�ν��B���g�B���������U�ت��C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",3500);
        }
  set("limit_lv",35);

        set("armor_prop/armor",5);
        set("armor_prop/shield",10);
        set("armor_prop/int",3);
        setup();
}


#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW "�p�Ӧ���٧Q" NOR ,({ "rulaifo finger","finger" }) );
        set("long",@LONG
�o�O�@��u�p�Ӧ򯪡v��d�b�H�����@�����٧Q�A��A�⤤���۳o
��٧Q�ɡA�A���ߤ��ϩ��w�g�����Х@�������ۡA���H�ͦ��G����`�@
�h���{���C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",4000);
        }
        set("wear_msg",HIY"$N�����٧Q�����b����W�A�n�ɥ����o�X�@�}�O��������C"NOR);

        switch(random(3))
        {
        case 0:        
                set("armor_prop/int",1);
                set("armor_prop/str",1);
                set("armor_prop/hit",20);
        break;
        case 1:
                set("armor_prop/dex",1);
                set("armor_prop/con",1);
                set("armor_prop/hit",20);
        break;
        case 2:
                set("armor_prop/int",1);
                set("armor_prop/str",1);
                set("armor_prop/dex",1);
                set("armor_prop/con",1);
        break;
        }
          set("armor_prop/armor",10);

        setup();
}

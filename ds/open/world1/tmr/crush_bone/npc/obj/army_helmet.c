#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "�x���Y��" ,({ "army helmet", "helmet" }));
        set_weight(3500);
        if( !clonep() ) {
                set("volume",3);
                set("material","iron");
                set("unit", "��");
                set("value", 2000);
                set("long",@long
�o�O�@���Ѳʻɥ��y�Ӧ����Y���A�W�Y���G��W�|���T���A�Y��
�e��観�����W����r��Ÿ��A�ݰ_�Ӧ��G���@�����v���Ȧb�C
long
                );
                set("armor_prop/armor", 8);
                set("armor_prop/con", 2);
                set("armor_prop/dex", -1);
        } else
                set_default_object(__FILE__);

        setup();
}



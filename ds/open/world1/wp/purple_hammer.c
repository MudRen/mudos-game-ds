#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create() {
        set_name(HIM"������"NOR,({"purple flame hammer","hammer"}));
        set("long",@LONG
�@��ݰ_�Ӳ@���_�����j��l�A�S�­��S���j�A���⪺�񨭶ǨӰ}�}
����A�\�O�t���H�̮ڥ��L�k��ܳo���ת��Iŧ�C
LONG
);
        set_weight(16000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",30);
        set("unit", "��");        
        set("value",1130);
        set("volume",6);        
        set("material","steel");       
              }        
        set("weapon_prop/str",2);
        set("weapon_prop/dex",-2);
        init_hammer(57);
        setup();
}    

#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("��֤j��" ,({ "tiger cloth" , "cloth" }) );
        set("long","�o���A���H�Pı�۷�����, �Q��Q��, ���L�q�`\n"
                   "�u�������s��D���H�h�~�|��o�تF��C\n");
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value" ,1500);
                set("material","fur");
        }
        set("armor_prop/armor", 6);
        set("armor_prop/shield", 4); 
        setup();
}

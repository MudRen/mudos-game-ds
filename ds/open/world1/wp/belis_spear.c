#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create() {
        set_name("��������",({"belis spear","spear"}));
        set("long",@LONG
�Ѧh�ؤ��P�q�۲V�Xű�������١A�۷�H���A�]���O�q�������H�O�L
�k�B�Φۦp���A�٦y�ä��Q���W�Q�A�º�O�a�ۥ������q�ӥ����ĤH
���C
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");        
        set("value",600);
        set("volume",3);        
        set("material","mixsteel");       
              }        
        set("weapon_prop/con",1);
        init_fork(35);
        setup();
}    



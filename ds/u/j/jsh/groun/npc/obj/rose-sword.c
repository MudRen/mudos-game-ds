#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("�����M�h�C", ({ "rose sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��"); 
                set("limit_str",35);
                set("long", 
 "�o��C���C��P�C�`���O�������F�@������K��A�Y�O�S���W�@
  ��֩w�|�����x�}�֡A�C�y�B�h���O��ä�몺�Ϊ��A����ϥ�
  �W�W�[�F���֪��O�q�C\n");
                set("value", 4000);
        }
        init_sword(56);
        setup();
}


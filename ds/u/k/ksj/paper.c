#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("�p�ȱ�", ({"small paper","paper"}));
        set("long",@LONG
�ȱ��W�g�ۡG

  �K�������(blood-scale surcoat) ��+17  �]��+2
  ���]��(dark gloves)             ��+9
  ��������(crystal mask)          ��+3   �]��+5
  �Ϥ��@��(magnetic wrists)       ��+8
  �j���P�ҧ�(refractile ring)     ��+5
  �H�K�V��(ice-iron neck)         ��+5
  �E�_���a(nine-gem crown)        ��+10  �]��+6
  �[�t�����T(ice-fire cloth)      ��+26
  �K���X����(eight-metal shield)  ��+28
  �P�e���Z(galaxy armor)          ��+42
  ��q�y�a(lion waist)            ��+8
  �񵾻ȹu(phoenix boots)         ��+15
  �B�����s��(ice-dragon pants)    ��+10
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "��");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

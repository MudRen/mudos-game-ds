#include <path.h>
inherit ITEM;

void create()
{
  set_name("�����˦a��", ({"forest map","map"}) );
  set("long",@long
�yø�۰����˦a�Ϊ��@�i�a�ϡC

            �U��
            ��      ��
          ���U    ���U��
        �ˡдˡЩ��Щ��Щ�
        �U  �U  �U  �U  �U
        �ˡдˡдˡдˡд�
        �U  �U  �U  �U  �U
        �ˡдˡдˡдˡд�
            �U  �U  �U
            �ˡдˡд�
                �U
                ���и�
                    �U
                    ��  

long);      
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}

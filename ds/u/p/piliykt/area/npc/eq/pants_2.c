#include <armor.h>
inherit PANTS;
void create()
{
  set_name("��������" ,({ "skin pants","pants" }) );
  set("long","�o�������ǭ��Y���,���O�Φʤ����ʯµ��һs,�ҥH�o�Ǥl��_�ӤQ���ΪA.");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silk");
    set("volume",3);
    set("unit", "��");
    set("value",2200);
    set("limit_lv",10);

  }
  set("armor_prop/armor",8);
  set("armor_prop/con",1);
  
setup();
}


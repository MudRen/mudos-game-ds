#include <weapon.h>
inherit SWORD;
void create()
{
 set_name("�g�A�C",({"mini sword","sword"}) );
 set_weight(3000);//damage*50�N�O�ӪZ�������q
 if( clonep() )
    set_default_object(__FILE__);
 else
 {
  set("unit", "��");
  set("long",
      "�C�b�u���@�ت����p�C�C\n");
  set("value",10);
  set("material", "iron");
  set("wield_msg","$N�N$n"+"�Ѹy����X\n");
  set("unequip_msg","$N�N$n"+"�C�C��^�y���C\n");
  init_sword(5);
 }
 setup();
}


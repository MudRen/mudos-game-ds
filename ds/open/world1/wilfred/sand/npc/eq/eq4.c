#include <armor.h>
inherit SURCOAT;
void create()
{
  set_name("�ȯT��" ,({ "silver-wolf skin","skin" }) );
  set("long","�o�O�q�ȯT���W��U�Ӫ��֡A�g�L�[�u�v�s����A�i�@���ܪӨϥΡA�軴�X�n�A�O���W�~�C");
  set_weight(1500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",8);
  set("armor_prop/dex",1);
  set("beast_armor_prop/armor",8);
  set("beast_armor_prop/dex",1);
  setup();
}

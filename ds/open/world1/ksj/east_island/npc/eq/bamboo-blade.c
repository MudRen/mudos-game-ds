#include <weapon.h>
inherit BLADE;

void create()
{
  set_name("�U�ˤM", ({ "bamboo blade","blade" }) );
  set("long",@long
�ξ�K�ˤl�a�V�A���Ʊ��A�A�˶i�Ӫ����ֳU���A�p���b�m�߮ɴN
���|�ˤH�F�C
long);      
  set_weight(880);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "wood");
    set("value",100);
    set("volume",2);
  }
  init_blade(3);
  setup();
}

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name("���ӤM", ({ "ya katana","katana" }) );
  set_weight(4550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long",@long
���ӤM�O�@�ضW�����M�A�����y�p���H�Ʀܷ|�⤣�X�ӡA�ѩ�Ӫ���
�A�X�b������a�A�j�����O�׽m�Z�D�̩ή��H�ϥΡC
long);      
    set("material", "steel");
    set("value",4500);
    set("volume",5);
    set("limit_skill",40);
  }
  init_blade(40);
  setup();
}

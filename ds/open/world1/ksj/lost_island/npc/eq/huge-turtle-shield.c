#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(YEL"���R�Ҭ�"NOR,({"huge-turtle shield","shield"}));
  set("long", @LONG
���R���ߥһs�����޵P�A�D�`�����j�I���A�X�G�i�H�צ�@�ӤH������C
LONG
);
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",5);
    set("value",8000);
    set("material","fur");
  }
// 2003.3.30 �s�W lv���� by ksj
  set("limit_lv",30);
  set("armor_prop/armor",29);
  set("armor_prop/dodge",-10);
  set("armor_prop/str",-1);
  set("armor_prop/dex",-3);
  setup();
}

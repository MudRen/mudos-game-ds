#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
  set_name(HIW"����ù����"NOR, ({ "horn bugle", "bugle" }));
  set("long", "�@�����j�������A���ӥi�H�j�X��ʤѦa���n��(bugle)�C\n");
  set_weight(5500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",2000);
    set("volume",5);
    set("wear_msg",
        "$N���Q�Ѷ}�N�@��$n�M�b�Y���A�ˤl�ᬰ�i���C\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("limit_con",30);
  set("armor_prop/dex", -2);
  setup();
}

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIR"�t��"HIW"���u"NOR, ({ "christmas boots","boots" }) );
  set("long",@long
�o�O�@�������������u�A�u�Y�W�٪g���X�������٨S���ĤơA�A���b
��W�⪱�����A�V�ݶV�O�߷R�A�V�ݶV�O�Q�n��W���C
long);      
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","fur");
    set("value",1);
  }
  set("armor_prop/armor", 1);
  setup();
}


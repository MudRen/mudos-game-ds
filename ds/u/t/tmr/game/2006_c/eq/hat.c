#include <armor.h>
#include <ansi.h>
inherit HEAD;


void create()
{
  set_name(HIR"�t��"HIW"�U"NOR,({ "inverse-horn hat","hat" }) );
  set("long",@LONG
�o�O�@���j�����y�U�l�A�W�Y�٪g���@�ǳ����A��o�D�`�߮�v�v�A
�A�V�ݶV�O���w�o���t�ϴU�A�W�Q���W���C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(100);
    set("unit", "��");
    set("value",1);
    set("volume",1);
  }
  set("armor_prop/armor", 1);
   setup();
}


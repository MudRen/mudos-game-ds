#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name(HIC"�Z�H�B��"NOR, ({"warrior ice statue","statue"}) );
  set("long",@LONG
�@�y���j���B���A�B�����O�@�짧�Ӫ����~�Z�̡A�q�L�y�������M��
���X�T�ݨӡA���O�P���Ψ����U�D��B�ʡA�B���~�򥿦b�C�C�ĤơA
���L�ӳo�سt�׬ݨӨS���Q�X�G�Q�~�O�ĤƤ������C
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "�y");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

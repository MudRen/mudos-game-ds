#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("����]", ({"bogle bead","bead"}) );
  set("long",@LONG
ĭ�t���Ǫk�O���]�l�A���ɦb���Ǧ��`��|�X�{�C
LONG
);
  set_weight(30);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("eat_msg","$N�Y�U�@�����x������p�]�l�C");
    set("eff_msg",HIG "�Aı�o���ѧN�y�b�����g�߬y«�A�ϧA�����κZ�C" NOR );
    set("unit", "��");
    set("volume",1);
    set("value",500);
  }
  set("heal",([
      "ap": 150,
      "mp": 150,
     ]));
  setup(); 
}

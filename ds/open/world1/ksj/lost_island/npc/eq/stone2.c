#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("�H�ۤ�", ({"broken stone","stone"}));
  set("long",@LONG
�@���}�H���۪O�A�۪O�W�e�F�@�ǹϮסA�ϤW�e�ۤ@���T�����ݰ_��
���j���r���s�A�s�l�v�����@�s�H�A�U�ӹϮ׬O�s�P�H���I�J�@�Ӥj
�d�h���A�ݨӬO���j�@����߰ʾz���ԨơC
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "��");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

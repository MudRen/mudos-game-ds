#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("�H�ۤ�", ({"broken stone","stone"}));
  set("long",@LONG
�@���}�H���۪O�A�۪O�W�e�F�@�ǹϮסA�ݰ_�ӹ��O�@�s�H�l�ۤ@��
���ۨⰦ���������j�Ѫ�A���ᥨ�긨�J�B�e�����B�A�M��O�\�h�H
�y�����ϮסC
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


#include <ansi.h>
inherit ITEM;
void create()
{
  set_name( "�ժ�" ,({"platinum"}));
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�N�O�զ⪺�����A�w�׸��������A�����H�`���D�A�O�ة��Q�����ݡC");
    set("value",10000);
  }
  setup();
}


#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

int hit;
int again, index;

void create()
{
  set_name(HIC"�s�����q"NOR,({"final book","book"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�W���g�F����A�A�����ݤ����������D�n��HŲ�w�@�f�H");
    set("unit","��");
    set("value",10);
  }
  setup();
}


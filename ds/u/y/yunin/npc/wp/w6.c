

#include <ansi.h>

#include <weapon.h>

inherit DAGGER;

void create()

{

  set_name(HIG"�ϯŤѨ�"NOR,({ "level A dagger","dagger" }) );

  set_weight(3000);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "��");

    set("long", "�o�O���ƤH�̩ҫ����Ѩ�C\n");

    set("material", "iron");

    set("value",4000);

    set("volume",1);

  }

  init_dagger(22);

  setup();

}

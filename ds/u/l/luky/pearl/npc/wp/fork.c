#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
set_name("�e�l",({"fork"}));
set_weight(12200);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
�o�O�@��ܱ`�������ÿ��e�l�C\n");
set("unit", "��");
set("spear",35); //skill 70
set("value",1100);
       }
      setup();
}

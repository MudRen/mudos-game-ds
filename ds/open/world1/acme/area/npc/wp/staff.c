#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
  set_name("�I��",({"monk's staff","staff"}));
  set("long","�o���I���O�o�D�����ҨϥΪ��k���C\n");
  set_weight(9000);
  if( clonep() )
      set_default_object(__FILE__);
  else {
      set("unit", "��");
     set("value",2500);
set("volume",4);
      set("limit_str",10);
  }
  init_staff(40);
  setup();
} 

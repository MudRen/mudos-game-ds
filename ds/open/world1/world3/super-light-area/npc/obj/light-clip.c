#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name("���l��",({"light-clip","clip"}) );
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","���l�j�M�Ϊ��u��");
        }
      set("value", 800);
   set_weight(1000);
set("amount",25);
  set("bullet/damage",50);        //�Z���¤O
set("bullet/unit","��");
 set("bullet/name","����");
set("type","light_clip");
setup();
}

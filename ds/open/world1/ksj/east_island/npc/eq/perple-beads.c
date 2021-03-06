#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(MAG"霞紫念珠"NOR,({"perple beads","beads"}) );
  set("long",@LONG
三十六顆紫玉珠串成的念珠，每顆珠子都呈現完美的紫色，不帶一點
暇庛。
LONG);
  set_weight(300); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_int",45);
    set("unit", "串");
    set("light",1);       
    set("value",9000);          
    set("volume", 2);                       
    set("material", "stone");
  }
  set("armor_prop/armor",3);       
  set("armor_prop/bio",1);
  set("armor_prop/bar",-1);
  setup();
  call_out("receive_by_beads", 30);
}

void receive_by_beads()
{
        object me = environment(this_object());
        int p_ap, i;

        if( !this_object() || !me ) return;
        if( me->query_temp("armor/neck")==this_object() )
        {
                p_ap = me->query("max_ap");
                if( me->query("ap") < p_ap )
                {
                        me->receive_heal("ap", p_ap*1/70);
                         message_vision(HIM"霞紫念珠發出紫光，$n感覺力氣回復了一些。\n"NOR, this_object(), me);
                }
        }
        call_out("receive_by_beads", 35);
}

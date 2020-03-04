#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(MAG"�������]"NOR,({"perple beads","beads"}) );
  set("long",@LONG
�T�Q�������ɯ]�ꦨ�����]�A�C���]�l���e�{����������A���a�@�I
�vθ�C
LONG);
  set_weight(300); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_int",45);
    set("unit", "��");
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
                         message_vision(HIM"�������]�o�X�����A$n�Pı�O��^�_�F�@�ǡC\n"NOR, this_object(), me);
                }
        }
        call_out("receive_by_beads", 35);
}

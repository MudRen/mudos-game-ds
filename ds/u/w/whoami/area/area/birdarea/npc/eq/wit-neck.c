#include <ansi.h>
#include <armor.h>
inherit NECK; 
string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});
void create()
{
set_name(HIY"���k��"NOR,({"sun-moon necklace","necklace"}));
set("long", @LONG
�@�����t���O�q������A���צ�B�`�O�o�X���~�A���b�⤤��
���۷ŷx���Pı�A�Aı�o�o������u�O�����Z�E
LONG);
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",0); 
    set("no_put",1);
    set("material","gold");
  }
  set("wear_msg", "$N��W�@"+this_object()->query("unit")+"$n�A$N�Pı���p����¶�b���ǡE\n");
  set("limit_lv",37);
  set("armor_prop/armor",13);
  set("armor_prop/shield",10); 
  set("armor_prop/dex",-2);
  set("armor_prop/con",2+random(2)); 
  set("armor_prop/str",-2); 
  set("armor_prop/wit",1); 
  set("armor_prop/tec",-1); 
  setup();
  call_out("receive_by_necklace", 70);
}

void receive_by_necklace()
{
        object me = environment(this_object());
        int p_mp, i;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/neck") == this_object())
        {
                p_mp = me->query("max_mp");
                if( me->query("mp") < p_mp/2 )
                {
                me->receive_heal("mp", p_mp*1/15);
                for(i=0;i<sizeof(wounds);i++)
                me->receive_curing(wounds[i], 1);
tell_object(me,HIY"\n���k��ǥX�@�ѷŷx���𮧡A�A���F�P��R�ꤣ�֡E�E\n"NOR);
                }
                else
                {
                tell_object(me,HIY"\n���k��ǥX�@�ѷŷx���𮧡A���O�S������Ƶo�͡I\n"NOR);
                }
        }
        call_out("receive_by_necklace", 90);
} 
void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}


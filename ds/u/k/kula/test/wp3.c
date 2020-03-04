#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
  set_name( "����C" , ({ "two-hand sword","sword" }) );
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O���K�s��������C�A�ݰ_�Ӥ���­��C\n");
    set("material", "iron");
    set("value",1500);
    set("volume",1);
  }
    set("limit_str",15);
  init_sword(30,TWO_HANDED);

  set("wield_msg","$N�q�I���X�@������C�A$Nı�o����m�ˡI\n");
  setup();
}

int wield()
{
  object me;
  me = this_player();
  if(me->query("combat_exp") < 150 )
  { return notify_fail("�A�g�礣���A�L�k�ϥ�����C�C"); }
  else { return ::wield(); }
}

void attack(object me,object victim)
{
        int freeztime,def;

        ::attack();
        if(!me) return;
        if(!victim) return;
    if(me->query_skill("sword") > 50 && me->query_str() > 20 && random(25)<3 )
    {
        message_vision( 
                HIC "\n�u��$N"+HIC "���_�⤤������C�A��$n���Y�W�{�U�h�I�I\n" NOR
    ,me,victim);

        freeztime = random(me->query_str()/4)+4;
        def = victim->query_con()/2;
        if(me->query("ap") < 10)
        {
        message_vision("$N"+HIG+"��O�����A�n�w�w�����夣�_�ӡC\n"NOR,me);
        return;
        }
        if(freeztime-def>4)
        {
        me ->start_busy(2);
        victim->start_busy(freeztime);
        message_vision(HIW+victim->query("name")+HIW"�Q$N�H����C�{���A�w�t�F�@�U�C\n\n"NOR,me);
        me->add("ap",-8);
        }
        else
        {
        message_vision(NOR"$N������@���A�{�L�F$n����աC\n"NOR,victim,me);
        }
    }
    return;
}

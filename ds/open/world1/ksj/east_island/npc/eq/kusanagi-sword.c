#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIW"���O"HIC"���C"NOR, ({ "kusanagi sword","sword" }) );
  set("long",@long
�ѤK�[�j�D�����ڤ����o�A�]�K�[�j�D�X�S�ɤW�ű`���Q���\��ӱo
�W�A�S�W���K���C�A�O�ѤU�L�������C�C
long);      
  set_weight(1450);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",4);
    set("rigidity",1200);
    set("limit_skill",60);
    set("limit_lv",45);
    set("replica_ob",__DIR__"viper-killed-katana");
  }
  set("weapon_prop/con",3);
  init_sword(70);
  set("wield_msg",HIC"$N�ޥX$n"HIC"�A�����ѪŤ@�}�������A�H��S�^�k���`�C\n"NOR);
  set("unwield_msg","$N�H�h������$n���C�b��A�p�ߦa���_�C\n");
  setup();
}

void attack(object me,object victim)
{
  int hitchance;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if( me->query("ap") < 250 ) return;
  if( me->query("level") < 35 ) return;
  
  hitchance = me->query("level")/10 + me->query_dex()/10;
  if(!random(21-hitchance))
  {
    me->start_busy(2);
    message_vision(HIC"\n���O���C���C�b�y���ť��A$N���P�򺥺����E�H�H������A��M�C���p�ձޯ�Ӯg�|�P�I�I\n"NOR,me);
    call_out("do_super",2,me);
    return;
  }
  return;
}

void do_super(object me)
{
  object *inv;
  int i, damage,def;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIW"\n���~�E�����j�L�񪺼C�b�A$N�p���H��B�b�b�Ũ��t�a�N�C�b���|�P��׼A�C�I�I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(inv[i]->query("no_fight")) continue;
    if(inv[i]->query("no_kill")) continue;
    if( inv[i]->query_temp("invis")>2 ) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if(inv[i]->is_fighting(me))
      {
        def=inv[i]->query_skill("parry")+inv[i]->query_skill("dodge")+inv[i]->query_skill("block");
        damage = 200+random(100)+me->query_skill("sword")+me->query_str()-def;
        if(damage < 1)
        {
          message_vision(HIG"$N�s�{�a�סA���W�a���L��աI\n"NOR,inv[i]);
        }
        message_vision(HIR"$N�Q�C�������٤��A�����Y�����жˡI"HIR"("+damage+")\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
        COMBAT_D->report_status(inv[i]);
      }
      else
      {
        def=inv[i]->query_skill("parry")+inv[i]->query_skill("dodge")+inv[i]->query_skill("block");
        damage = 200+random(50)+me->query_skill("sword")+me->query_str()-def;
        damage=damage/5;
        if(damage < 1)
        {
          message_vision(HIG"$N�W���{���A�I�ǾD��C���i�ΡI\n"NOR,inv[i]);
        }
        message_vision(HIR"$N�L�d�a�Q�C�������A���컴�L���ζˡI"HIR"("+damage+")\n"NOR,inv[i]);
        inv[i]->receive_damage("hp", damage, me);
      }
    }
  }
  me->start_busy(1);
  me->receive_damage("ap",100);
  return;
}

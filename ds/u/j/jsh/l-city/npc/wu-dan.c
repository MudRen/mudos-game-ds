#include <path.h>
#include <ansi.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIW"�臘�T�@"NOR,({"wu-dan","dan"}) );
  set("long", HIW"
  �}ù�ꪺ��g���A�λ�ۥ��j���}ù�����A\n"
 "  �⤤���L�O�A�i�P�F�j���������Ѱ�B���C\n"NOR    
  );
  set("race", "human");
  set("unit","��"); 
  set("title",HIG"�}ù���"NOR);
  set("age",60);
  set("level",65);
  set("attitude", "friendly");
  set("max_hp",30000);
  set("Merits/bar",5);
  set("Merits/bio",5);
  set("Merits/wit",5);
  add("addition_armor",123);
  add("addition_damage",123);
        set("chat_chance",7);
        set("chat_msg",({
  (: heal :),  
}));

  setup();
  carry_object(__DIR__"obj/blade")->wield();
}

void heal()
{ 
  if(query("hp") > query("max_hp")) return;  
  add("hp",500); 
  return;
}   
int special_attack(object me, object target, int hitchance)
{ 
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  { 
    me->start_busy(2);
    target->add_busy(1);
    message_vision(HIW"\n$N���M���z�ե��I�@�����j"+HIW""+BLK"��D"+HIW"�q$N���F�ĥX�I\n\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}

void do_super(object me)
{ 
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIW"\n���j��D�i�}�j�f�I�@��"+BLK"�¦��q"+HIW"�C�C���E�I�Q�X�I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      damage = random(400)+250;
      message_vision(HIW"$N�Q"+BLK"�y�}ù�E��D�i�z"+HIW"���L .... �������X"+HIR"�@�@����.."HIM"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N�����l�@�˪��A�������}�A���ƵM��Ů𤧤� .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}

void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIG"\n�i"+HIB"�}ù����"+HIG"�j"+HIY""+ob->name(1)+"��j�ǰ��A�^�������A���U�F"+HIB"�}ù�����C\n\n"+NOR     
       ,users());
        ob->add("popularity",7+random(3)); 
        ::die();
        return;
}



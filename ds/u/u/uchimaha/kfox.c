#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"�E��"NOR,({ "killer fox", "fox" }) );
        set("level",60);
        set("race", "���~");
        set("age", 1000);
        set("title",HIR"���H��"NOR);
        set("long", "�e�O�o�̪��Y�Y�A�ڻ��e�w�g���F�W�d�~�F�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_skill("dodge",100);
        set("Merits/bar",10);
        set_skill("combat",100);
        set_skill("parry",90);
        add("addition_armor",90);
        add("addition_damage",80);
        set("evil",200);
        set("attitude", "aggressive");
        set("guild_gifts",({6,6,-2,10}));
        setup();
}
int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;

  if(!random(5))
  {
    message_vision("\n$N"HIW"������}�l�l������P��Ҧ������...\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}
void do_super(object me)
{
  // �o�̪� me �O�� this_object()
  object *inv;
  object ob;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      damage = random(150)+200;
      message_vision(HIW"$n�����Q"HIR"$N"HIW"���l���F... "MAG"("+damage+")\n"NOR,inv[i],me);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
      add("hp", damage);
    }
    else
    {
      message_vision(HIR"\n$N�����Q�l���@�㰮��... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  return;
}
int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();

  // ����
  if(!random(10))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIW"\n�i"HIR"�E���������I"HIW"�j\n"NOR,ob);
    if(me->query("level") > 40)
    {
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    else
      if(me->query("level") > 30) 
      {        COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+2);
         if(query("hp") < query("max_hp")) add("hp",15+random(15));
      }
      else
        if(me->query("level") > 24)
        {
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+2));
        }
        else
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+1));
  }

  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIC"\n  [�p�D����]:"HIR"\n\n\t�ǻD�������H��  �E���p�����G���b"+ob->name(1)+"����U!\n\n"+NOR,users());
        ob->add("popularity",10);
        tell_object(ob,HIW"(�]���A�����F�E���A�ҥH�o��F 10 �I�n��C)"NOR);
        message_vision( "$N"+HIR "�{���e�A�]������κɡA���W��ֲ渨�U��...." NOR ,this_object() );
        ob->move(environment(this_object() ) );
        ob=new(__DIR__"obj/pe");
        ob->move(environment(this_object() ) );
        ::die();
        return;
}

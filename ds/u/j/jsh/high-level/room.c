#include <ansi.h>
inherit NPC; 
//void super_attack();
void create()
{
        set_name(HIC"�ɪ��]�N�v"NOR, ({ "mage" }) );
        set("race", "�H��");
        set("age", 40);
        set("level",60+random(10));
        set("long", HIW"�g�˪��H�C\n"NOR);      
        set("max_hp",30000);
        set("chat_chance", 33);
        set("chat_msg", ({
                (: random_move() :),
                "�]�N�v���X�F�@����l�A�}�l��z�Y�v�C\n" }) );  
        set("chat_chance_combat", 300);
        set("chat_msg_combat", ({  
        (: random_move() :), 
/*
        (: super_attack() :), 
        (: super_attack() :), 
        (: random_move() :),
        (: super_attack() :),
        (: super_attack() :),
        (: super_attack() :), 
        (: random_move() :),
        (: super_attack() :),
        (: super_attack() :), 
        (: random_move() :),
        (: super_attack() :),
        (: super_attack() :),
        (: random_move() :),
        (: super_attack() :), 
        (: random_move() :),  
*/
}));        setup();  
        carry_object(__DIR__"mage-hat")->wear();  
        carry_object(__DIR__"mage-gloves")->wear(); 
}  

/*
void super_attack(object me,object target,int hitchance)
{
    int tdex,tcon;  
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*20) > tdex+tcon)
    {
      message_vision(HIW"$N�j�ۤ@�n�G�ɪŬ��u�I�I��V$n�I\n" 
                     HIW"$n�Q�����A��O�O...\n"NOR,me,target);
    target->receive_damage("hp",500+random(199), this_object());
    } 
    return;
}  
*/
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*200) > tdex+tcon)
    {
      message_vision(HIW"\n$N���n�D�G��...�o���N��A�o�I�ݧڪ�t�a\n\n"
                     HIW"\n$N�Τ����$n�C\n\n" ,me,target);
      target->receive_damage("hp",100+random(200), this_object());  
      target->add_temp("yyy",1);
      call_out("do_super2",2,me);      return 1; 
    }
    else
    {
      message_vision(HIW"$N���n�D�G���A���|�|�ɪŪ����O�a�I\n\n"NOR,me,target);
      call_out("do_super",2,me);
      return 1;
    }
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIC"�L��j�j�����O�A�q�|���K��ӨӡI\n"NOR,me);
  message_vision("\n�A�L�B�i�k�A�u��Ө��o�j�j�����O�I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(350)+300;
      message_vision(HIW"�y�ذաz���G�O���Y�H�����n���I "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      if( inv[i]->query_con() > 90 )
        inv[i]->add_busy(1);
      else if( inv[i]->query_con() > 75 )
        inv[i]->add_busy(2);
      else
        inv[i]->add_busy(3);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N�Q�j�j�����O�Ҥ��ѡI \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(2);
  return;
}
void do_super2()
{
      object me=this_player();  
      if(!me) return;
      if(me->query_temp("yyy") != 1 ) return;
      else{      message_vision(HIW"�u��"+this_player()->name(1)+"�Q�@�ӧᦱ���Ŷ����Y�F�i�h�I\n\n",me);
      this_player()->move(__DIR__"room");
      }
      return;
}int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
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
    HIR"\n�i��    ���j"+HIW "�ɪ��]�N�v���Ѧb"+ob->name(1)+"����W�I\n\n"+NOR     
       ,users()); 
        ob->add("popularity",10);  
        ::die(); 
        return;
} 
void start_busy() { return; }
void add_busy() { return; }






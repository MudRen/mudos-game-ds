#include <ansi.h>
inherit NPC; 
void super_attack(); 
void heal_hp();
void create()
{
        set_name(HIC"�ɪ��]�N�v"NOR, ({ "mage" }) );
        set("race", "�H��");
        set("age", 40);
        set("level",60+random(10));
        set("long", HIW"�g�˪��H�C\n"NOR);      
        set("max_hp",30000);
        set("addition_damage",400); 
        set("addition_shield",200);
        set("addition_armor",200);
        set("dex",300); 
        set("chat_chance", 33);  
        set("chat_msg", ({
                (: random_move() :), 
                (: heal_hp():), 
                "�]�N�v���X�F�@����l�A�}�l��z�Y�v�C\n" }) );  
        set("chat_chance_combat", 300);
        set("chat_msg_combat", ({  
        (: random_move() :), 
        (: heal_hp():),
        (: super_attack() :), 
}));        

        setup();  
        carry_object(__DIR__"mage-hat")->wear();  
        carry_object(__DIR__"mage-gloves")->wear(); 
}  

void heal_hp()
{
     object me=this_object();
     me->receive_heal("hp",2000,me);
     return;
}
void super_attack()
{ 
    object me=this_player(),target=me->select_opponent();
    int tdex,tcon;  
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(100)+100 > tdex+tcon)
    {
      message_vision(HIW"$N�j�ۤ@�n�G�ɪŬ��u�I�I�r�M�a��V$n�I\n" 
                     HIW"$n�Q�����A��O�O...\n"NOR,me,target);
    target->receive_damage("hp",700+random(199), me);
    }  
     else {       message_vision(HIW"$N�j�ۤ@�n�G�ɪŬ��u�I�I�r�M�a��V$n�I\n" 
                     HIW"$n�Q�����A��O�O...\n"NOR,me,target);
    target->receive_damage("hp",700+random(199), me);
          }
    return;
}  
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision(HIW"\n$N���n�D�G��...�o���N��A�o�I�ݧڪ�t�a\n\n"
                     HIW"\n$N�H�K���F�@�ӤH�C\n\n" ,me,target);  
      message_vision(HIW"$N���n�D�G���K���A���|�|�ɪŪ����O�a�I\n\n"NOR,me,target);
      message_vision(HIW"�u��"+target->name(1)+"�Q�@�ӧᦱ���Ŷ����Y�F�i�h�I\n\n",me);
      target->receive_damage("hp",100+random(200), this_object());    
      target->add_temp("be_point",1); 
      target->move("/open/world1/jangshow/room.c"); 
      tell_object(target,"�A���ݤf���G�Q�ؤU�F����F��..\n");
      call_out("do_super",2,me);
      return 1;    
    }   else {return 1;}
     /*
    }
    else if(random(hitchance*5) < tdex+tcon)    {
      message_vision(HIW"$N���n�D�G���A���|�|�ɪŪ����O�a�I\n\n"NOR,me,target);
      call_out("do_super",2,me);
      return 1;
    } 
      else { return 1; }  
     */ 
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
      damage = random(1000)+500;
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
  if(inv[i]->query_temp("be_point")!=0) {  
               switch(random(10)){
               case 0..1:               
               message_vision(HIW""+me->name(1)+"��M�Ⲵ�����e��...�f�R�A��Ӥ`�I\n"NOR,inv[i]);
               inv[i]->die(); 
               break;
               case 2..5:
               message_vision(HIW""+me->name(1)+"�����F�ɪŪ����O�A�R�F�@�f�A��I\n"NOR,inv[i]);
               inv[i]->receive_damage("hp",600,inv[i]);
               break;
               case 6..10:
               message_vision(HIW""+me->name(1)+"�����F�ɪŪ����O�A�R�F�@�f�A��I\n"NOR,inv[i]);  
               inv[i]->receive_damage("hp",600,inv[i]);
               break;
                } 
                                  }  return;
} 
/*
void do_super2()
{
      object me=this_player();  
      if(!me) return;
      message_vision(HIW"�u��"+this_player()->name(1)+"�Q�@�ӧᦱ���Ŷ����Y�F�i�h�I\n\n",me);
      this_player()->move(__DIR__"room");
      return;
} 
*/
int receive_damage(string type,int cost)
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
    HIR"\t\n�i��    ���j"+HIW "�ɪ��]�N�v���Ѧb"+ob->name(1)+"����W�I\n\n"+NOR     
       ,users()); 
        ob->add("popularity",10);    
        switch(random(99))
        {
        case 0..3:
        ::die(); 
        break;
                  case 4..33:
                  message_vision(HIW"�ɪ��]�N�v���G�K�K�K....�C�H�Y�K���i�F�ɪŵ��_..\n"NOR,ob); 
                  destruct(this_object());
                  break; 
                  case 34..66:
                  message_vision(HIW"�ɪ��]�N�v���G�K�K�K....�C�H�Y�K���i�F�ɪŵ��_..\n"NOR,ob); 
                  destruct(this_object());
                  break;
                  case 67..80:
                  message_vision(HIW"�ɪ��]�N�v���G�K�K�K....�C�H�Y�K���i�F�ɪŵ��_..\n"NOR,ob); 
                  destruct(this_object());
                  break;  
                  case 81..99:
                  message_vision(HIW"�ɪ��]�N�v���G�K�K�K....�C�H�Y�K���i�F�ɪŵ��_..\n"NOR,ob); 
                  destruct(this_object());
                  break; 
        }
        return;
} 
void start_busy() { return; }
void add_busy() { return; }


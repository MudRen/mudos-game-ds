#include <ansi2.h>
inherit NPC; 
void summon_fox();
void create()
{
        set_name(HIW"�E"HIY"��"NOR,({ "killer fox", "fox" }) );
        set("level",60+random(20));
        set("race", "���~");
        set("age", 1000+random(500));
        set("title",HIR"���H��"NOR);
        set("long", 
        "�ȥզ⪺�֤�M�A���������A�Q���N�O�ǻ������E�����C\n"
        "�s�n������ڭ��A�H�Y�����۴b�A���K�D�̹B�C���L�H�Y\n"
        "�Y�F�����סA�]�ण���������𪺫I�`�C�E�����i�ۤƬ�\n"
        "���k���k�A�A�˲��͡C�ڻ��g�o�Ӭ���������}���H�v�A\n"
        "�N�O�E�����ҤۤơC\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("fox",1);
        set("max_hp",9000+random(5000));
        set("Merits/bar",8+random(5)); 
        set("Merits/wit",8+random(5));
        set("Merits/tec",1+random(10));
        set_skill("combat",100);
        set_skill("parry",90); 
        set_skill("dodge",100); 
        set_skill("unarmed",100);
        add("addition/armor",400);
        add("addition/shield",250);
        add("addition/damage",400); 
        add("addition/dodge",100);
        add("addition/hit",100);
        set("evil",2000);
        set("attitude", "aggressive");  
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
        (: summon_fox() :),
         }) );
        setup(); 
        carry_object(__DIR__"eq/fist2")->wield();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(!random(3))
  {
    message_vision("\n$N"HIW"����X�j�q"NOR+MAG"����"HIW"��A$N"HIW"��"NOR+MAG"����"HIW"�}�l���ͤF�ܤơE�E�E\n"NOR,me);
    call_out("do_super", 2, me);
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
      if( inv[i]->query("fox") ) continue; 
      if( inv[i]->query_temp("invis")>2) continue;
      switch(random(100)){
      case 0..50:
       damage = me->query("mp");
       if( damage < 0 ) damage=0;
message_vision(HIW"\n�@�ѧ���«�J$N"HIW"�餺�A$N"HIW"�����Q$n"HIW"���l���F�I�I"HIY"("+damage+")\n"NOR,inv[i],me);
       inv[i]->receive_damage("hp", damage, me); 
       inv[i]->start_busy(random(2));
       COMBAT_D->report_status(inv[i]);
       me->add("hp", damage);
       me->receive_damage("mp",random(30));
       break;
      case 51..75:
       damage = (me->query("ap"))/10;
       if( damage < 0 ) damage=0;
message_vision(HIW"\n�@�ѧ���«�J$N"HIW"�餺�A$N"HIW"���]�O�Q$n"HIW"���l���F�I�I"HIY"("+damage+")\n"NOR,inv[i],me);
       inv[i]->receive_damage("mp", damage, me);
       COMBAT_D->report_status(inv[i]);
       inv[i]->start_busy(random(2));
       me->add("mp", damage);
       me->receive_damage("mp",random(30));
       break;
      default:
       damage = (me->query("hp"))/100; 
       if( damage < 0 ) damage=0;
message_vision(HIW"\n�@�ѧ���«�J$N"HIW"�餺�A$N"HIW"�����l�Q$n"HIW"���l���F�I�I"HIY"("+damage+")\n"NOR,inv[i],me);
       inv[i]->receive_damage("ap", damage, me);
       COMBAT_D->report_status(inv[i]); 
       inv[i]->start_busy(random(2));
       me->add("ap", damage);
       me->receive_damage("mp",random(30));
      break;
      }
    }
    else
    {
      message_vision(HIR"\n$N�Q"HIW"�E"HIY"��"NOR"������U�N�p�ɤF.. \n\n"NOR,inv[i]);
      me->add("hp", 500);
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
  if(!random(4))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIW"\n�i"HIR"�E���������I"HIW"�j\n"NOR,ob);
   
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(ob->query("hp") < ob->query("max_hp")) 
      ob->receive_heal("hp",200+random(100));
  }

  ::receive_damage(type,cost,me);
  return 0;
}  

void summon_fox()
{
  int hp,max_hp;
  object b,ob1,me;
  me=this_object();
  hp=this_object()->query("hp");
  max_hp=this_object()->query("max_hp");

  if( hp < (max_hp - 5000) )
  {
    b=new(__DIR__"s_fox" );
    b->move(environment(this_object()));
    message_vision(HIG"\n$N�����𺥺����E���ΡA�]�X�F�@��$n�E�E\n",this_object(),b);
    b->kill_ob(this_object());
    this_object()->kill_ob(b);
    return;
  }
}

void die()
{
object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", 
        
        HIW"\n\t�i"HIB"���@�@��"NOR+HIW"�j
        "HIW"\n\t���H�L�ƪ�"HIR"���H�� �E��"NOR+HIW"�ש�Q"NOR+ob->name(1)+HIW"�ʦL�F�E\n\n"+NOR,users());
        ob->add("popularity",10);
        tell_object(ob,HIG"\t�A�o��F�����I�n��I\n"NOR);
        message_vision( "\n\t$N"+HIR "�{���e�A�]������κɡA���W��ֲ渨�U��....\n" NOR ,this_object() );
        newob=new(__DIR__"obj/pe"); 
        ob->set_temp("ko_fox_nine",1);
"/open/world1/whoami/birdarea/fox18"->set("exits");
"/open/world1/whoami/birdarea/fox19"->delete("exits","out"); 
"/open/world1/whoami/birdarea/fox19"->add("exits",
(["back" : "/open/world1/whoami/birdarea/village1.c"]));
        newob->move(environment(this_object() ) );
        ::die();
        return;
} 


#include <ansi.h>
#include <combat.h>     
inherit NPC;
object z;
int i;

void create()
{
  set_name("�s���", ({"apeman king","king"}) );
  set("long",@LONG
��Υ��j���s��A���߮ɦ��T���ذ��A�������y���S�X�b�L�ڥ~�A��
���٦ץY�X�A�����ݴNı�o�ܮ��ơA�e�������G���j�j�p�p���ˬ͡C
LONG);
  set("race", "�H��");
  set("unit","��");
  set("age",50);
  set("evil",30);
  set("gender", "�k��" );
  set("level",45);
  set("int",30);
  set("str",115);
  set("con",140);
  set("dex",70);
  set_skill("unarmed",70);
  set_skill("dodge",20);
  set_skill("parry",40);
  add("addition_damage",50);
  add("addition_armor",100);
  setup();
  carry_object(__DIR__"eq/bone-armor")->wear();
  carry_object(__DIR__"eq/wrists-design-page");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( objectp(z=present("shi-ganrin sword",this_player())) )
  {  
    message_vision("$N�ݨ�$n���W�����l�[�L�C�A���Ĩĥ�ť�O(hest)�C\n",this_object(),this_player() );
    i=this_player()->query_temp("hest_king_times");
    this_player()->set_temp("hest_king_times",i+1);
    this_object()->set("creater",this_player());         
    this_object()->set_leader(this_player());
    this_object()->set_temp("last_opponent",0);
    this_object()->remove_all_killer();
    if( this_player()->query_temp("hest_king_times") > 7 )
    {
      call_out("crazy",0,this_player());
      return;
    }
    call_out("crazy",30,this_player());
    return;
  }
  if( userp(this_player()) && this_object()->query("creater")!=this_player() )
     this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(4))
  {
    message_vision( "$N�����q���A�o�X�@�}��q�C\n", this_object() );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void crazy(object ob)
{
  object env;
  env = environment(this_object());
  if( env != environment(ob) ) return;
  if( userp(ob) && objectp(z=present("shi-ganrin sword",ob)) )
  {
    message_vision(HIR"�s�����ı����l�A�ܥh$N���W�����l�[�L�C�����a�����C\n"NOR,ob );
    this_object()->kill_ob(ob);
    destruct(z);
    this_object()->delete("creater");
    this_object()->set_leader(0);
    this_player()->delete_temp("hest_king_times");
    return;
  }
  return;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",2);      
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);
  ::die();
  return;
}

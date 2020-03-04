#include <ansi.h>
#include <combat.h>     
inherit NPC;
object z;

void create()
{
  int i;
  set_name("�s��", ({"ferity apeman","apeman"}) );
  set("long",@LONG
������θ�@��H�t���h�A�������e�{�t����A���O�C�ӤO��j�A��
�w�s��ŧ���H���A�ݭ��ͦסA�q�`�n��T�Ӥj�~�~���A�@���s��C
LONG
);
  set("race", "�H��");
  set("unit","��");
  set("age",30+random(20));
  set("gender", "�k��" );
  set("apeman",1);
  set("level",30+random(6));
  set("str",60+random(10));
  set("con",80+random(10));
  set("dex",70+random(10));
  set_skill("unarmed",40+random(30));
  set_skill("dodge",30);
  set_skill("parry",30);
  add("addition_damage",30+random(10));
  add("addition_armor",30+random(10));
  set("chat_chance",9);
  set("chat_msg",({
     (: command,"go east" :),
     (: command,"go west" :),
     }));
  setup();
  switch( random(10) )
  {
    case  0..2: carry_object(__DIR__"eq/climb-claw")->wield(); break;
    case 3..5: carry_object(__DIR__"eq/hand-dagger")->wield(); break;
    case 6..9: carry_object(__DIR__"eq/wood-stick")->wield(); break;
  }
  i = random(4)+2;
  while( i-- )
  {
    switch( random(10) )
    {
      case  0: carry_object(__DIR__"eq/wild-fruit1"); break;
      case  1: carry_object(__DIR__"eq/wild-fruit2"); break;
      case  2: carry_object(__DIR__"eq/wild-fruit3"); break;
      case  3: carry_object(__DIR__"eq/wild-fruit4"); break;
      case  4: carry_object(__DIR__"eq/water-pill"); break;
      case  5: carry_object(__DIR__"eq/food-pill"); break;
    }
  }
  switch( random(10) )
  {
    case  0..3: carry_object(__DIR__"eq/stone-corslet")->wear(); break;
  }
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( objectp(z=present("protect amulet",this_player())) ) return;
  if( this_player()->query("apeman-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(20))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
varargs int receive_damage(string type, int damage, object who);
void normal_ai();
void combat_ai();

mapping *combat_action = ({
        ([  "action":       "$N���|���l�[�L�C�A�۹D�G�ޮ�s�C�N�I\n"
                            "���l�[�L�C�~�M�����߱C�C�⤤��ŭ��_�A�������V$n��$l�I",
                "attact_type":  "bio",
                "damage_type":  "���",
        ]),
        ([  "action":       "$N����D�_�A�⨬���b���l�[�L�C���C�b�W�A�۹D�G���Y�ٸ��C�I\n"
                            "���l�[�L�C���a�U�����խ����٦V$n��$l�I",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([  "action":       "$N�N���l�[�L�C�ߦV�b�šA���L�۹D�G�H�߻�p�C�I\n"
                            "�Ť��@�D�{�q������l�[�L�C���ɤޡA���V$n�ү�����m�C",
                "attact_type":  "wit",
                "damage_type":  "�q����",
        ]),
        ([  "action":       "$N�w�w�H�C�b��ŵe��A�f������G�A\n"
                            "$n�~�M����L�Ƭr�D�q�C�餤«�X�A�¦ۤv�g���ӨӡI",
                "attact_type":  "sou",
                "damage_type":  "�r��",
        ]),
        ([  "action":       "$N�ߥX���l�[�L�C�A���⵲�L���V$n�A\n"
                            "���l�[�L�C���Y�p�ۭ���e�t�b$n�����W���ΡC",
                "attact_type":  "tec",
                "damage_type":  "�h�B�ζ�",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name("�߱C�C", ({"cat oldwoman","oldwoman","_CAT_OLDWOMAN_"}));
  set("long",@long
���ۨ��l�A�ֽ��S���S�K�A�����ۤ���Ͱʭ��e�j�示���G��A�o��
�y���صۤ@��ݰ_�ӫܵ��R�����C�A�L�ڤ��ɳ�䪺�����D��ۤ���
�C
long);      
  set("gender", "�k��" );
  set("age",193);
  set("evil",50);
  set("level",50);
  set("attitude", "aggressive");
    set("race","celestial");
    set("race","celestial");
  set("con",109);
  set("int",100);
  set("dex",80);
  set_skill("sword", 90);
  set_skill("parry", 70);
  set_skill("dodge", 70);
  set_skill("unarmed", 70);
  set_temp("apply/hit",40);
  set_temp("apply/dodge",30);
  add("addition_armor",130+random(5));
  set("talk_reply","�����a�ڪ��n�ơA�䦺�I�I\n");
  set("chat_chance", 80);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  set("chat_chance_combat",200);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  set("can_defend", 1);
  setup();
  set_living_name("_NPC_CAT_OLDWOMAN_");
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/cat-tail-waist")->wear();
  add_money("coin",2000);
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("apeman-enemy") ) this_object()->kill_ob(this_player());
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

void normal_ai()
{
  object me,target;
  me = this_object();
  target = this_player();

  if(me->is_busy()) return;
  if( me->query("hp") + 200 < me->query("max_hp") )
  {
    message_vision(HIG"\n$N����X�x���L�A�P�ɩ��������A$N���W���ˤf�~�M����¡�X�I\n\n"NOR,me);
    me->receive_heal("hp",300);
    me->start_busy(3);
    return;
  }

  if( me->query("mp") + 200 < me->query("max_mp") )
  {
    message_vision(HIG"\n$N�q�j�礤�c�F�@�I�G�鶼�U�A�믫�ݨӦn�F�\\�h�C\n\n"NOR,me);
    me->receive_heal("mp",300);
    me->start_busy(3);
    return;
  }

  switch( random(25) )
  {
     case  0: message_vision("�߱C�C����D�G�o���Ļs�n��A�N�����s��̹�����o�ʧ����F�A�K�K�K�D�D�D\n",me);
           break;
     case  1: message_vision("�߱C�C����D�G�X���s�M�I�����A�٬O�J�V�A�i�h���w���C\n",me);
           break;
     case  2: message_vision("�߱C�C�@���Ͱ���l�A�n���Q�o�X�������A�S���`�N��A���s�b�C\n",me);
           break;
     case  3: message_vision("�߱C�C����D�G�ٮt�ӪF���J(putting)�N�৹���o���ĤF�A\n"
                             "��D�D�s�s����h�줣���D�ण�৹���D�D�D\n",me);
           break;
  }
  return;
}

void combat_ai()
{
  int hp,mp,ap,max_hp,max_mp,max_ap;
  object b,ob1,ob2,ob3,ob4,me,target;
  me=this_object();
  target = offensive_target(me);
  ob1=find_living("_NPC_STONE_PUPPET_");
  ob2=find_living("_NPC_MUD_PUPPET_");
  ob3=find_living("_NPC_AXEMAN_");
  ob4=find_living("_NPC_PROTECT_GHOST_");
  hp=this_object()->query("hp");
  mp=this_object()->query("mp");
  ap=this_object()->query("ap");
  max_hp=this_object()->query("max_hp");
  max_mp=this_object()->query("max_mp");
  max_ap=this_object()->query("max_ap");

  if(me->is_busy()) return;
  if( objectp(ob1) )
  {
    if(!environment(ob1) )
    {
      destruct(ob1);
    }
  }
  else if( mp > 50 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIW "\n$N�N�@�i�G�ŶK�b�a���W�A�P�򪺨F�۳��H�G�Ŭ����߳v���E���H�ΡI\n" NOR,me);
    b=new(__DIR__"stone-puppet" );
    b->move(environment(me));
    me->receive_damage("mp",50,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",10);
    return;
  }

  if( objectp(ob2) )
  {
    if(!environment(ob2) )
    {
      destruct(ob2);
    }
  }
  else if( mp > 50 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIW "\n$N�N�@�i�G�ŶK�b�a���W�A�d�g���t�l���b�G�ŤW�v���E���H�ΡI\n" NOR,me);
    b=new(__DIR__"mud-puppet" );
    b->move(environment(me));
    me->receive_damage("mp",50,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",10);
    return;
  }

  if( objectp(ob3) )
  {
    if(!environment(ob3) )
    {
      destruct(ob3);
    }
  }
  else if( mp > 150 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIR"\n$N�r�}�ަy�N�A��Q�b�G�ŤW�A�����|�P���𾮻E�A�Φ��@�W�Z�̡I\n" NOR,me);
    b=new(__DIR__"axeman" );
    b->move(environment(me));
    me->receive_damage("mp",150,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }

  if( objectp(ob4) )
  {
    if(!environment(ob4) )
    {
      destruct(ob4);
    }
  }
  else if( mp > 150 )
  {
    if(query_temp("wait_to_summon")) return;
    message_vision(HIR"\n$N�r�}�ަy�N�A��Q�b�G�ŤW�A��M�@�D���v�q�a���B�{�I\n" NOR,me);
    b=new(__DIR__"protect-ghost" );
    b->move(environment(me));
    me->receive_damage("mp",150,me);
    me->start_busy(2);
    set_temp("wait_to_summon",1);
    call_out("delay",20);
    return;
  }

  if(!random(15))
  {
    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
    COMBAT_D->report_statue(target);
    return;
  }
  return;
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
  if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
  if( type!="hp" && type!="mp" && type!="ap" )
      error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
  if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
  if(random(100)<30)
  {
    damage/=3;
    message_vision(HIM "\n$N�ήɨϥX�����N�A���v��M�ܦ��@�I���Y�A�{�}�F�����������C\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void delay()
{
  delete_temp("wait_to_summon");
}

void die()
{
  object ob,ob1,ob2,ob3,ob4;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
  GRN"\n\t�i�����ˡj�G"+HIM" �ʦ~�ߧ� "HIW" �Q�L�q�߸z��"HIY+ob->name(1)+HIW"�����F�A�����L���w�Y���R�C\n\n"+NOR
    ,users());
  ob->add("popularity",5);      
  tell_object(ob,HIG"�A�o�� 5 �I�n��C"NOR);
  ob->set_temp("kill_cat",1);
  ob1=find_living("_NPC_STONE_PUPPET_");
  ob2=find_living("_NPC_MUD_PUPPET_");
  ob3=find_living("_NPC_AXEMAN_");
  ob4=find_living("_NPC_PROTECT_GHOST_");
  if( objectp(ob1) && environment(ob1) )  destruct(ob1);
  if( objectp(ob2) && environment(ob2) )  destruct(ob2);
  if( objectp(ob3) && environment(ob3) )  destruct(ob3);
  if( objectp(ob4) && environment(ob4) )  destruct(ob4);
  
  if( random(5000) )
     new(__DIR__"eq/shi-ganrin-sword")->move(this_object());
  else
     new(__DIR__"eq/devil-cat-mask")->move(this_object());
  ::die();
  return;
}

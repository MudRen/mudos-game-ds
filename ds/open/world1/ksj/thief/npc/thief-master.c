
inherit NPC;
#include <ansi.h>
#include <guild_mark.h>
inherit SSERVER;
void combat_ai();

void create()
{
  set_name("����", ({ "lee mou", "mou", }) );
  set("title", "����");
  set("gender", "�k��");
  set("age", 38);
  set("long",@LONG
�A�ݨ�@�ӸG�p�����~�H���b�Y�L��ƪ��j�ۤf��A�i�O�A�o��
�@�طPı�A�ϩ��A���@�|�@�ʥL�����A�p���x�C�`�E��������ܥL��
���g�L���֤j���j���C�L�N�O�H�١u����v���j�s�A���ߡC

[ �Y�Q�[�J�p�����|, �п�J join thief ]
[ �d�\�p�����|�ޯ�, �п�J list       ]
[ �p�G�A���u�|�H����, �п�J apply  ]

LONG
);
  set("attitude", "peaceful");
  set("level",40);
  set("evil",50);
  set_skill("unarmed", 95);
  set_skill("parry", 90);
  set_skill("dodge", 100);
  set_skill("dagger",92);
  set_skill("combat_backstab",61);
  set_temp("apply/armor",38);
  //���|�]�w
  set("class","thief");
  set("adv_class",1);
  set("class1","thief");
  set("class2","thief");
  set("no_check_class",1);
    set("guild_gifts",({3,7,0,10}));

  set("guild_skills",([
      "dagger":   ({100,4,95}),
      "bow":      ({130,3,80}),
      "blade":    ({120,3,70}),
      "sword":    ({130,3,60}),
      "dodge":    ({90,4,95}),
      "parry":    ({130,3,70}),
      "sneak":    ({100,4,95}),
      "hide":     ({100,4,90}),
      "backstab":     ({110,3,90}),
      "peep":     ({110,4,90}),
      "stealing":     ({120,3,90}),
      "perception":   ({130,4,90}),
      "organization": ({120,4,90}),
      "free_action":  ({180,2,40}),
     ])  );
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
     (: combat_ai() :),
     }) );
  setup();
  carry_object(__DIR__"eq/flash-boots")->wear();
  carry_object(__DIR__"eq/eagle-cloth")->wear();
   carry_object(__DIR__"eq/blood-sting")->wield();
}

void init()
{
  ::init();
  add_action("do_skill_list","list");
  add_action("do_skill_train","train");
  add_action("do_advance","advance");
  add_action("do_join","join");
  add_action("do_check_mark","apply");
}

void combat_ai()
{
  object me,target,z;
  me=this_object();
  z=present("needle",me);
  target = offensive_target(me);
  if(!me) return;
  if(me->is_busy()) return;

  if( !me->query_temp("weapon") && objectp(z) )
    command("wield needle");
  if( !random(3) )
    command("exert combat_backstab");
  return;
}

int do_check_mark(string arg)
{
  object me,ob,mark;
  me=this_player();
  if(mark=present("mulit-function dagger",me)) return notify_fail("�A�w�g���U��P���F�C\n");
  if(me->query("class1")!="thief") return notify_fail("�A�èS���ѥ[�p�����|�������C\n");

  ob=new(THIEF_MARK);
  if(!ob->can_move(me))
  {
    destruct(ob);
    return notify_fail("�A�����ᱼ�@�ǪF��~�����ʥ����|�H���C\n");
  }
  ob->move(me);
  message_vision("$N���F�@"+ob->query("unit")+ob->name()+"��$n�C\n",this_object(),me);
  me->save();
  return 1;
}

int do_skill_list(string arg)
{
  return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);     
}

int do_skill_train(string arg)
{
  return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}

int do_join(string arg)
{
  int i;
  string guild_rank, title;
  object ob, me, mark;

  ob = this_object();
  me = this_player();
  mark=new(THIEF_MARK);
  if(me->query("evil")<50) return notify_fail("�A�ӵ��}�F���A�X�[�J�����|�C\n");
  if(me->query_max_encumbrance()<mark->query_weight()+me->query_encumbrance())
  {
    return notify_fail("�A�����ᱼ�@�ǪF��~�����ʥ����|�H���C\n");
  }
  i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

  switch(i)
  {
    case 0:  return notify_fail("�H���]�w���~�A�гq���Ův�����ѨM�C\n");
    case -1: return notify_fail("�A�w�g�[�J��L���|�F�C\n");
    case -2: return notify_fail("�A�w�g�[�J��L���|�F�C\n");
    case -3: return notify_fail("�A���A�X�[�J�����|�C\n");
    case -4: return notify_fail("�A�ثe�����Ť��A�X�[�J�����|�C\n");
    case -5:
    case -6:
    case -7: return notify_fail("�A�����󤣾A�X�[�J�����|�C\n");
    case -8: return notify_fail("�S���o��¾�~�C\n");
  }
  if( !guild_rank = this_object()->guild_rank(me) || guild_rank=="")
    guild_rank = "�٫ܵ檺�s��p��";
  me->set("guild_rank",guild_rank);
  if( !(title=me->query("title")) || title == "�ɪź}�y��" )
    me->set("title", "�ǻ������ĤT����"); // ps�o�O�h�[��, luky �O�o�n�令�A�n����I�I

  mark->move(me);
  message_vision("$N�[�J�F�p�����|�C\n",me);
  tell_object(me,ob->name()+"�q�f�U�����X�F�@��"+mark->name()+"���A�C\n");
  return 1;
}

int do_advance(string arg)
{
  object ob, me;
  string title;
  ob = this_object();
  me = this_player();
  if(me->query("class1")!="thief" )
    return notify_fail("�A���O�p�����|���|���C\n");
  if( me->query("level") > 25)
    return notify_fail("�A�L�k�b�����@�A�����šC\n");
  return GUILDMASTER->do_advance(ob,me,arg);
}

string guild_rank(object me)
{
  string rank;
  if( me->query("gender") == "�k��" )
  {
    switch( me->query("level")/5 )
    {
      case 0: rank = "�¤�¸}���p�k��"; break;
      case 1: rank = "�|�B�y«���p�k��"; break;
      case 2: rank = "�޳N�¼����k����"; break;
      case 3: rank = "���H���N���k�s��"; break;
      case 4: rank = "����Q�D���k�j�s"; break;
      case 5: rank = "���X���S���k����"; break;
      default: rank = "���X���S���k����";
    }
  }
  else
  {
    switch( me->query("level")/5 )
    {
      case 0: rank = "�¤�¸}���¤p��"; break;
      case 1: rank = "�ʧ@�F�����p�s��"; break;
      case 2: rank = "�ޥ����m���p����"; break;
      case 3: rank = "�e��ֲ֪��ѺD��"; break;
      case 4: rank = "����Q�D����j��"; break;
      case 5: rank = "���X���S��������"; break;
      default: rank = "���X���S��������";
    }
  }
  return rank;
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
  message("world:world1:vision",
  HIC"\n  [�����Y��]:"HIW"\n\n\t"+ob->name(1)+"�A�����`���١u����v���¹D���l���ߡA�ް_�Ū������`�C\n\n"+NOR
        ,users());
  ob->add("popularity",1); //�n��
  ::die();
//  tell_object(ob,"  �A�o��@���n��C\n");
  //destruct(this_object());
  return;
}


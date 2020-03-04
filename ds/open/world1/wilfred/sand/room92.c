// �}�� & �Ԫ������� room , �����ɥ�q�۰}�|�_�X�\�h���q��  wilfred@DS

#include <ansi.h>

int is_war();
void start_war();
void end_war(int j);
void armageddon(int index_t);
string get_item();

inherit ROOM;
void create()
{
  set ("short", "���Y�s��");
  set ("long", @LONG
�o�̬O�������ǪK�A�b��ɤ]�N�O�ҿת������A�o�̦�����O��
����F���^�ت��A�W�Y���F�\�h��O���A�g�ۤ@�ǩ��g������r�A��
��������|�j�����A�ݨӦ��G�O���F�Ϥ��o�Ǥ�O�������e�C
LONG
);
  set("exits", ([
  "east" : __DIR__"room90",
]));
  set("item_desc", ([
  "��O��" : (: get_item :),
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

int is_war()
{
  return query("is_war");
}

void start_war()
{
  set("is_war",1);
  call_out("clone_mob",5);
  return;
}

void clone_mob()
{
  /*
     ���w�q�b�j��̪���
     �������s   x 5
     �����K�s   x 4
     �������s   x 3
     �������s   x 2
     �l�u�s     x 1
     �d�~�s     x 1
     �p���s     x 1

     ����m�@�w����
     �u�������s x 1 �����p�Y��
     �C�����s   x 1 �����Ѥj
     -------------------------
                 19 ��
  */

  string *npc = ({
"37","37","37","37","37",
"38","38","38","38",
"39","39","39",
"40","40",
"41","42","43"
});

  int i, index;

  message("world:world1:vision",
  HIC"\n\t�e�j���ʦL�S�A�׳Q����F......�@�D�C�լ۶����s��q�Y�s�s�q�z�_�}�ӡI�I\n"+
  HIR"\n\t\t�Y�s�s�s�s�ɥX�A����_�ѡI�I\n\n"NOR,users() );

  for(i=0;i<sizeof(npc);i++)
  {
    index = (random(11)+78);
    if(index == 83 || index == 87) index++;
    new(__DIR__"npc/npc"+npc[i])->move(__DIR__"room"+(string)index);
    tell_room(__DIR__"room"+(string)index,"�@�ζ¼v��M�X�{�b�A���e�C\n");
  }
  new(__DIR__"npc/npc44")->move(__DIR__"room89");
  new(__DIR__"npc/npc45")->move(__DIR__"room90");


  call_out("end_war",2000+random(600));
  return;
}

void end_war(int j)
{
  object mob, room, *env;
  int i, index;

  if(!j)
  {
    if( objectp(mob = find_living("dragon_war")) )
    {
      tell_room(environment(mob), HIW"\n�ѤW���M���U�@�D�j���]��F"+mob->name(1)+" .....\n\n"NOR);
      destruct(mob);
      call_out("end_war",3);
    }
    else
    {
      delete("is_war");
      room = load_object(__DIR__"room49");
      room->reset();
      room = load_object(__DIR__"room88");
      room->reset();

      for(index=78;index<93;index++)
      {
        room = find_object(__DIR__"room"+(string)index);
        if(!room) continue;
        env = all_inventory(room);
        if(!env) continue;
        for(i=0;i<sizeof(env);i++)
          if(userp(env[i]) || env[i]->query("id") == "tent")
          {
            tell_object(env[i],HIW"\n�A���M�Q�@�}�j���]�� ..... �A�uı�o�@�}�w�t ..\n\n"NOR);
            env[i]->move(__DIR__"room49");
          }
          else destruct(env[i]);
      }
      message("world:world1:vision",
      HIW"\n\t������h�A�s�s�^�k�A�Y�s�s�^�k���R�C\n\n"NOR,users() );
    }
    return;
  }
  else
  {
    call_out("armageddon",5,200);
    call_out("gold_mine",1);
  }
  return;
}

void armageddon(int index_t)
{
  object room;
  int index;

  if(index_t < 3)
  {
    remove_call_out("armageddon");
    call_out("go_die",1);
    return;
  }

  if(index_t < 17)
  {
    index_t -= 3;
    for(index=46;index<93;index++)
    {
      room = load_object(__DIR__"room"+(string)index);
      if(!room) continue;
      tell_room(room,"�٦� "+index_t+" ���ӽY�s�s�N�n�����F�A�кɳt���}�C\n");
    }
    call_out("armageddon",3,index_t);
  }
  else
  {
    index_t -= 15;
    for(index=46;index<93;index++)
    {
      room = load_object(__DIR__"room"+(string)index);
      if(!room) continue;
      tell_room(room,"�٦� "+index_t+" ���ӽY�s�s�N�n�����F�A�кɳt���}�C\n");
    }
    call_out("armageddon",15,index_t);
  }
  return;
}

void gold_mine()
{
  object room;
  int index;

  index = random(24) + 50;
  room = load_object(__DIR__"room"+(string)index);
  if( room )  {
          tell_room(room, HIY"\n���I�I�@�����q�q�����_�F�X�ӡI\n"NOR);
        new(__DIR__"npc/obj/obj30")->move(room);
  }
  call_out("gold_mine", 6+random(4) );
}

void go_die()
{
  object room, *env;
  int index, i;
  string msg = "";

  room = load_object(__DIR__"room46");
  room->armageddon();
  room = load_object(__DIR__"room49");
  room->reset();
  room = load_object(__DIR__"room88");
  room->reset();

  remove_call_out("gold_mine");
  for(index=46;index<93;index++)
  {
    room = load_object(__DIR__"room"+(string)index);
    if(!room) continue;
    env = all_inventory(room);
    if(!env) continue;
    for(i=0;i<sizeof(env);i++)
      if(userp(env[i]))
      {
        tell_object(env[i],HIW"\n�A�����G�D�ե��]���A�A���e�ү�ݨ쪺�A�u�ѷ���....\n\t���e���¤��O�¡A���e���լO�����...\n\n"NOR);
        msg +=  env[i]->name(1);
        env[i]->set_temp("last_damage_from", new(__DIR__"npc/hill.c") );
        env[i]->die();

      }
      else destruct(env[i]);
  }
  message("world:world1:vision",
  HIW"\n\t�Y�s�s�Q�ѤW���U�������զ���������A�@�}�ѷn�a�ʡA�Y�s�s�y�ɦǭ��Ϸ� ..... \n\n"  NOR,users() );
  if(msg != "")
          message("world:world1:vision",
                  HIG"  " + msg + " ���H���������b�Y�s�s���A�O�ѤU�H�{���C\n"NOR, users() );
  delete("is_war");
  delete("get_item");
  return;
}

string get_item()
{
  if(query("get_item")) return "�@�Ǥ�O���A�W���g�F�@�Ǥ�r�C\n";
  message_vision("\n$N�b��O���̵o�{�F�@���F��I�I\n\n",this_player());
  new(__DIR__"npc/obj/obj21")->move(environment(this_player()));
  set("get_item",1);
  return "";
}

void reset()
{
  if(is_war()) return;
    else ::reset();
}


#include <ansi.h>
inherit ROOM;

int flee(object obj);
int get_money();

string *temp_msg = ({
"\n�����L�F�h�[�Aé�ﶡ�uť�o���H�b���� ....\n\n",
WHT"�k�H���D�G ���A���F�S�H\n"NOR,
HIW"�~���H���D�G �S��F�A���ӬO���F�a�C\n"NOR,
WHT"�k�H���D�G �n�A��b�o�̴N�n�F�A���a�C\n"NOR,
HIW"�~���H���D�G �O�C\n"NOR,
HIW""BLK"\n�A���e�@�¡A�S���F�L�h ....\n"NOR,
HIG"\n�S�����L�F�h�[.... �A�ש��_�F����...\n\n"NOR,
});

void create()
{
  set ("short", YEL"�s��"NOR);
  set ("long", @LONG
�u���b�e�褣���@�B�������q���F�a�W�A�f�F�@��]��A���f�B
���۴X�쨭������~�֦�A�Y������ִU���u�áA�b���]�椺�ɰ_
�F���F�����X���Сж¶��������Y�A���a�u�ô��Y�A�ݨӨëD�[�d��
�a�C
LONG
);

/*
  set("exits", ([
  "south" : __DIR__"room36",
]));
  set("objects",([
  __DIR__"npc/obj/obj20" : 1,
]));
*/
  set("outdoors", "land");
  setup();
}

void init()
{
  object me;
  ::init();
  if( interactive(me = this_player()) )
  {
    remove_call_out("action1");
    call_out("action1",1,me);
    me->start_busy(2);
  }
}

int action1(object me)
{
  if(!me) return 1;
  if(random(3))
  {
    message_vision(WHT"���G�S�H�o�{$N��F�i�ӡC\n"NOR,me);
    return 1;
  }
  message_vision(HIW"\n$N���p�߽��_�}�U����K�I�I�o�X�@���n�T�I\n\n"NOR,me);
  message_vision(HIC"�V�F�I$N�Q�o�{�աI�I\n"NOR,me);
  message_vision(HIR"$N��M�Q�H�q�I�ᬽ���V�F�@�O�e�ҡI�I\n"NOR,me);
  message_vision(HIR"$N��F�@�n�H�Y�n�˦b�a�A���۳Q�G�ӳC�Τj�~��i�s��F�C\n\n"NOR,me);
  me->set_temp("block_msg/all",1);
//  me->move(__DIR__"room3");
//  tell_room(__DIR__"room3",HIW"�A�ݨ����Ӵ����O�媺�H�Q��b�o�̡A���p�~�G�A�v��Y�C���F�C\n"NOR);
  me->set("hp",random(30)+1);
  me->start_busy(20);
  call_out("action2",7,0,me);
  return 1;
}

int action2(int index, object me)
{
  string msg = temp_msg[index];
  if(!me) return 1;
  me->delete_temp("block_msg/all");
  write(msg);
  me->set_temp("block_msg/all",1);
  if(++index < sizeof(temp_msg)) call_out("action2",4,index,me);
    else me->delete_temp("block_msg/all");
  return 1;
}

int flee(object obj)
{
  object npc, ob = this_object();

  if(!obj)
  {
    while(objectp(npc = find_living("desert_robber")))
    {
      tell_room(environment(npc),"���F��W���k�h�F�C\n");
      destruct(npc);
      ob->delete_temp("start_robber");
    }
  }
  else
  {
    destruct(obj);
    if(objectp(npc = find_living("desert_robber")))
      return 1;
    else
    {
      message("world:world1:vision",HIC"\n���F��Q���o����Ӱk�F�C\n\n",users());
      ob->delete("start_robber");
    }
  }
  return 1;
}

int start_robber()
{
  object ob = this_object();
  int i;
  if(ob->query("start_robber")) return 1;

  message("world:world1:vision",
HIR"\n\t�i���ֳ��j"YEL"�����F�o�Ͳ��ܡI�U�O���x�n�u���f�A���o���~�I�I\n\n"NOR,users());

  for(i=0;i<5;i++)
    new(__DIR__"npc/npc48")->move(__DIR__"room1");
  for(i=0;i<3;i++)
  {
    new(__DIR__"npc/npc21")->move(ob);
    new(__DIR__"npc/npc22")->move(ob);
  }
  new(__DIR__"npc/npc23")->move(ob);

  ob->set_temp("start_robber",1);
  call_out("flee",100);
  return 1;
}

int get_money()
{
  object *all_ppl, maxppl;
  int i, money, lose, maxlose = 0;

  all_ppl = children("/obj/user");
  all_ppl = sort_array(all_ppl, "sort_user", this_object());

  for(i=0;i<sizeof(all_ppl);i++)
  {
    money = all_ppl[i]->query("bank/past");
    lose = money / 100 * (random(5)+1);
    if(lose > maxlose)
    {
      maxlose = lose;
      maxppl = all_ppl[i];
    }
    all_ppl[i]->add("bank/past",-lose);
  }
  message("system","�i�����p���j�@��" +chinese_number(sizeof(all_ppl))+ "��Z�L�H�h���s�ھD�T�C\n",users());
  message("system","�j�]�D"+maxppl->query("name")+"�l���̬��G���A�s�ھD�T"+chinese_number(maxlose)+"�T�j���C\n",users());
  return 1;
}


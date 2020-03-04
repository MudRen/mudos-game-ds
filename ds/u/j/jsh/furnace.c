#include <path.h>
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("�Z���l",({"weapon furnace","furnace"}));
  set_weight(99999999);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG
�K�K�M�Ϊ����l�A�D�n�O�Φb�Z�����ĦX�A���D����k�ӷһs
���H�O�֤��S�֡C

  �ϥΤ�k�G 
  1�G����J��تZ��
  2�G���l��(fireup)

LONG
);

  }
  set("no_sac", 1);
  set("no_get", 1);
  set("no_clean_up",1);
  set_max_encumbrance(999999);
  setup();
}

void init()
{
  add_action("do_fireup","fireup");
}

int do_fireup()
{
  object ob = this_object(), *obs, *only_check;
  int i, index = 0;

  obs = all_inventory(ob);
  if(sizeof(obs) < 1) return notify_fail("�A�n��J�F��~��ĦX�C\n");
  if(sizeof(obs) > 2) return notify_fail("�A��J���F��Ӧh�F�I�I\n"[30m);[0m
  message_vision("\n$N�ɰ_�F�l���A�}�l�Z�����ĦX ...... \n\n",this_player());


  if(sizeof(obs) > 2)
  {
    message_vision("\n���G����Ƴ��S�o��.... \n\n",this_player());
    return 1;
  }
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "white crystal") index += 10;
    if(obs[i]->query("skill_type") == "sword") index += 100; 
  }

  only_check = filter_array( children(WD_PAST+"sand/npc/wp/wp12"), (: clonep :) );

  if(index != 110 || sizeof(only_check) > 0 )
  {
    message_vision("\n���G����Ƴ��S�o��.... \n\n",this_player());
    return 1;
  }

  for(i=0;i<sizeof(obs);i++)
    destruct(obs[i]);

  tell_room(environment(ob),HIW"���l���z�g�X�@�}�j�� ...... �A�ݨ줦�l�̦��G�M�ҥX�s�����ơH\n"NOR);
  new(WD_PAST+"sand/npc/wp/wp12")->move(ob);
  return 1;
}


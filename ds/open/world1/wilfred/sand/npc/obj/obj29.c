// �ثe�u���}�� "�զ������C" ���ĦX, ��l���H��A�g   wilfred@DS

#include <path.h>
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("�C�s�����l",({"Dragon furnace","furnace"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG
�@�ӫC�ɻs�����l�A�W����۳\\�h�s�Ϊ᯾�A���񩳳�
���䤤�@��᯾�誺���G�O�~�r�A�W�Y�g�ۡG

                 �M �� �� �k

        ��J����M�Ҥ����A�ά��@�A�ά��h�]

  ���l��(combine)�A�ݤ����ɡA�i�o���]�A��L�i�w���]

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
  add_action("do_combine","combine");
}

int do_combine()
{
  object ob = this_object(), *obs, *only_check;
  int i, index = 0;

  obs = all_inventory(ob);
  if(sizeof(obs) < 1) return notify_fail("���ݥ���J�A�Q�n�M�Ҫ��F��C\n");
//  if(sizeof(obs) > 8) return notify_fail("�A��J���F��Ӧh�F�I�I\n");
  message_vision("\n$N�ɰ_�F�l���A�}�l�M�� ...... \n\n",this_player());

  // ������.... �Q�}�Y�]�S�����X�@�ӿĦX���n�W�h (�ڥd�b�o�̬��Ƥp�� -.-+�o�G)
  // �Ȯɭ���u����Ӧn�F�ӥB�P�w�γ̲ª���k, ����@�w�n��g
  // �x�Ωʯu���t��     wilfred@DS

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

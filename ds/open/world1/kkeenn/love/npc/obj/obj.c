/*���ɮ��F�P���� Wilfred ��sand obj*/
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIM"���K�l"NOR,({"love fire furnace","furnace"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG  
    �����������Ы����v�i�����P�L�j�үd�����A�O��~�o��
�H�a���۫n�����H�B���ؤɰ_���P�K�A��ūױN�����@�d
�װ��šA��ū׭쥻�ӱN��ӱ������ĤơA�i�O�g�ѧ��k�P�L
���D�ƪv�Ҥ���A�K�i�H�P�K���a���@�ѴH��A�w�����ūפ�
���šA�{�Uť���i�Ѥs���j�N��~������Q�j�W���ݨ��㪺�m
�P���H�B�n�g�Ѧ��l�ҤƦ��K�������A�i�����l���Q�`�C
( �ϥΤ�k: combine )
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


void dest_all(object *obs){
        int i;
        for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);
}

int do_combine()
{
  object ob = this_object(), *obs, *only_check;
        object armor;
  int i,x,index = 0;
        int t;

  obs = all_inventory(ob);
        if( !sizeof(obs) ) return notify_fail("�S���F��b���A���combine???\n");

  message_vision("\n$N�ɰ_�F�l���A�}�l�M�� ...... \n",this_player());
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "jan ball") index += 1;
    if(obs[i]->query("id") == "lin ball") index += 10;
    if(obs[i]->query("id") == "she ball") index += 100;
    if(obs[i]->query("id") == "jin ball") index += 1000;
    if(obs[i]->query("id") == "jun ball") index += 10000;
    if(obs[i]->query("id") == "run ball") index += 100000;
    if(obs[i]->query("id") == "ju ball")  index += 1000000;
    if(obs[i]->query("id") == "win ball") index += 10000000; 
  }

  if(index != 11111111 || sizeof(obs) > 8) {
        message_vision("���G����Ƴ��S�o��.... \n\n",this_player());
        new(__DIR__"ash")->move(ob);
        dest_all(obs);
        return 1;
  }

        armor=new(__DIR__"armor");
        if( armor->violate_unique() )
        {
      message_vision("\n���G�@�}�M���R���F����l�l.... \n\n",this_player());
      if(random(10) > 6)
                new(__DIR__"pill9")->move(ob); 
          else
                new(__DIR__"pill0")->move(ob); 
                dest_all(obs);
                destruct(armor);
           return 1;
        }

        tell_room(environment(ob),HIW"���l���z�g�X�@�}�j�� ...... �A�ݨ줦�l�̦��G�M�ҥX�s�����ơH\n"NOR);
        armor->move(ob);
        dest_all(obs);
        return 1;
}


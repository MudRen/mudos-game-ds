#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit WRISTS;

int check(mixed *space);

void create()
{
  set_name(WHT"�ջ��@��"NOR ,({ "silver wrists","wrists" }) );
  set("long",@LONG

�ջȻs���@�áA�y���Ʃ_�S�A���G���O�o�ӥ@�ɪ��F��A
�b����t�W��F�@�Ǧr�i�Ȧ�ήɪŹp�F T&S CO,.LTD�j
���o�Ǧr�O����N��A�o�L�q�o���A�A�J�Ӫ��[���o�{
�W�Y�٦��G�ӫ��s�A�@�¤@�աA�]�\�A�i�H���U�h�ոաC
(push black) �� (push white)�C

LONG
);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",3);
    set("unit", "��");
    set("value",3500);
  }
  set("armor_prop/armor",1);
  setup();
}

void init()
{
  add_action("do_push","push");
}

int do_push(string str)
{
  object *obs, *inv;
  mixed *space = allocate(4);
  int i, j;
  string msg = "", temp1, temp2;

  if(str != "black" && str !="white") return 0;
  if(!this_object()->query("equipped")) return notify_fail("�Х��N�ջ��@�îM�b��äW�C\n");

  obs = children("/obj/user");
  obs = sort_array(obs, "sort_user", this_object());

  if(str == "white")
  {
    inv = all_inventory(environment(this_player()));
    for(i=0;i<sizeof(inv);i++)
    {
      if(!userp(inv[i]) || wizardp(inv[i]) || inv[i] == this_player()) continue;
      inv[i]->set_temp("point_on_you",1);
      write("�i�t�ΰT���j��M���a�ؼ�: "+inv[i]->name(1)+"�w�즨�\\�C\n");
    }
    if(sizeof(inv) < 1) write("�i�t�ΰT���j�ؼ�: �M�䥢�ѡC\n");
    return 1;
  }

  for(i=0;i<4;i++)
    space[i] = allocate(sizeof(obs));
  for(i=0;i<sizeof(obs);i++)
  {
    if(wizardp(obs[i])) continue;
    temp1 = obs[i]->name(1);

    if(obs[i]->query_temp("point_on_you"))
    {
      if(!environment(obs[i])) temp2 = "�L�k�w�q";
      else temp2 = environment(obs[i])->query("short");
      if(obs[i]->query_temp("netdead")) temp2 += " [�_�u��]";
    }
    else temp2 = NOR"�|���аO";

    switch(obs[i]->money_type())
    {
      case 1 : j = check(space[1]);
               space[1][j] = sprintf(HIW"%13s�G %-8s ���b %s\n"NOR,temp1,"�j�N�ɪ�",temp2);
               break;
      case 2 : j = check(space[2]);
               space[2][j] = sprintf(HIC"%13s�G %-8s ���b %s\n"NOR,temp1,"�{�N�ɪ�",temp2);
               break;
      case 3 : j = check(space[3]);
               space[3][j] = sprintf(HIG"%13s�G %-8s ���b %s\n"NOR,temp1,"���Ӯɪ�",temp2);
               break;
      default : j = check(space[0]);
                space[0][j] = sprintf(HIR"%13s�G %-8s ���b %s\n"NOR,temp1,"�L�k�w�q",temp2);
                break;
    }
  }
  write(HIC"\n----------[ �ջ��@�ç�g�X�@�D�T���v�H ]-----------\n\n"NOR);
  for(i=0;i<4;i++)
    for(j=0;j<sizeof(space[i]);j++)
    {
      if(!space[i][j]) continue;
      msg += space[i][j];
    }
  write(msg);
  write(NOR""WHT"\n�P�±z���R��, "HIW"T & S"NOR""WHT" �b�����z�A��\t"HIC"-Time & Space-\n\n"NOR);
  return 1;
}

int check(mixed *space)
{
  int i;
  for(i=0;i<sizeof(space);i++)
    if(!space[i]) return i;
  return 0;
}

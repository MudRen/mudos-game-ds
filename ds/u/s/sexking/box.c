#include <ansi2.h>
inherit COMBINED_ITEM;

void create()
{
  set_name(HIM"����"NOR, ({"box"}));
  set("long","������l���p�p�����C\n�ϥΤ�k: ���� pra <�Y��(�H)>\n���� unpra\n");
  set("unit", "��");
  set("base_unit", "��");
  set("base_weight", 1);
  set_amount(1);
}

void init()
{
  if( this_player()==environment() )
  add_action("do_pra","pra");
  add_action("do_unpra","unpra");
}
int do_pra(string arg)
{
  object me,obj,*inv;
  int i,max;        
  me=this_player();
  inv = all_inventory(environment(me));
  if(!arg) return notify_fail("�A�n�ꦨ��?\n");        
  if(me->query_temp("pra") == 1) return notify_fail("�Х����� <unpra>�C\n");
  for(i=0; i<sizeof(inv); i++)
  {
    if( arg == inv[i]->query("id"))
    {
      me->set_temp("bak_name",       me->query("name"));
      me->set_temp("bak_title",      me->query("title"));
      me->set_temp("bak_nickname",   me->query("nickname"));
      me->set_temp("bak_id",         me->query("id"));
      me->set_temp("bak_gender",     me->query("gender"));
      me->set_temp("bak_guild_rank", me->query("guild_rank"));

      me->set_temp("pra", 1);

      me->set("name",       inv[i]->query("name"));
      me->set("title",      inv[i]->query("title"));
      me->set("nickname",   inv[i]->query("nickname"));
      me->set("id",         inv[i]->query("id"));
me->set("gender",     inv[i]->query("gender"));
      me->set("guild_rank", inv[i]->query("guild_rank"));

      write(HIW"�A���X�������������ꦨ�F"HIY+inv[i]->query("name")+"\n"NOR);
      say("�A��Mı�o��������l�A�n�����ѤO�q�Q�H�a�l���F�C\n"NOR);
      return 1;
    }
  }
  return notify_fail("�o�̨S�o�ӤH\n");
}

int do_unpra(string arg)
{
  object me,obj;
  int i,max;        
  me=this_player();
  if(!me->query_temp("pra")) return notify_fail("�A�S����!!\n");  
      
  me->set("name",       me->query_temp("bak_name"));
  me->set("title",      me->query_temp("bak_title"));
  me->set("nickname",   me->query_temp("bak_nickname"));
  me->set("id",         me->query_temp("bak_id"));       
  me->set("gender",     me->query_temp("bak_gender"));
me->set("guild_rank", me->query_temp("bak_guild_rank"));

  me->delete_temp("pra");

  me->delete_temp("bak_name",       me->query("name"));
  me->delete_temp("bak_title",      me->query("title"));
  me->delete_temp("bak_nickname",   me->query("nickname"));
  me->delete_temp("bak_id",         me->query("id"));
  me->delete_temp("bak_gender",     me->query("gender"));
  me->delete_temp("bak_guild_rank", me->query("guild_rank"));

  write(HIW"�A�N�ۨ��F, �^�_�쥻������\n"NOR);
  return 1;
}


#include <ansi2.h>
#inherit NPC;
void create()
{
  set_name(HIY"�G�A���ݤH"NOR, ({"liquefaction metal man","man"}));
  set("long",@LONG
�@�ӥ������G�A���ݰ��������ݤH..���i�H�ܦ�����H
���S���H���D�����ϥΤ�k�A�]�\�A�i�H�Q��k�h����
���A�N�i�����ܦ�����H�F�C
LONG
);
  set("unit", "��");
  set("level", 1);
  set("age",1);
  set("gender","����");
 setup();
}

void init()
{
  add_action("do_be","be");
  add_action("do_unbe","unbe");
  add_action("hest","hest");; 
}
int do_be(string arg)
{
  object who,me,obj,*inv;
  int i,max;    
  me=this_object();
  inv = all_inventory(environment(me));
  if(!arg) return notify_fail("�A�n�����ܦ���?\n");        
  if(me->query_temp("be") == 1) return notify_fail("�Х������ܦ^�ӭ�����ˤl <unbe>�C\n");
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
      me->set_temp("be", 1);
      me->set("name",       inv[i]->query("name"));
      me->set("title",      inv[i]->query("title"));
      me->set("nickname",   inv[i]->query("nickname"));
      me->set("id",         inv[i]->query("id"));
      me->set("gender",     inv[i]->query("gender"));
      me->set("guild_rank", inv[i]->query("guild_rank"));
      write(HIW"�G�A���ݤH��M�Ĥƺ������Ʀ��F"HIY+inv[i]->query("name")+"\n"NOR);
   return 1;
    }
}
}
int do_unbe(string arg)
{
  object me,obj;
  int i,max;        
  me=this_object();
  if(!me->query_temp("be")) return notify_fail("���٨S�ܦ��O�H\n");  
  
  me->set("name",       me->query_temp("bak_name"));
  me->set("title",      me->query_temp("bak_title"));
  me->set("nickname",   me->query_temp("bak_nickname"));
  me->set("id",         me->query_temp("bak_id"));       
  me->set("gender",     me->query_temp("bak_gender"));
  me->set("guild_rank", me->query_temp("bak_guild_rank"));
  me->dele
te_temp("be");

  me->delete_temp("bak_name",       me->query("name"));
  me->delete_temp("bak_title",      me->query("title"));
  me->delete_temp("bak_nickname",   me->query("nickname"));
  me->delete_temp("bak_id",         me->query("id"));
  me->delete_temp("bak_gender",     me->query("gender"));
  me->delete_temp("bak_guild_rank", me->query("guild_rank"));

  write(HIY"�G�A���ݤH�G���ܦ^�F��Ӫ��Ҽ�\n"NOR);
  return 1;
}
int hest(string str)
{ command(str);
  return 1; }





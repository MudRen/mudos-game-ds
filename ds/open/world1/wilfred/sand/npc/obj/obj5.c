#include <ansi.h>
#include <login.h>
inherit ITEM;

string *club_area = ({ 
	"/open/world1/cominging/area/dragon/",
	"/open/world1/god_club/",
	"/open/world1/baal/ming_club/",
	"/open/world1/acme/area/sky/",
	"/open/world1/acme/area/moon/",
	});

void create()
{
  set_name(WHT"�����"NOR,({"walk tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�o�O�@�D���몺�ůȡA�ůȤW�g�F�@��_�Ǥ�r�A���ԵL��C\n�ϥΤ�k: send <�Y���a���^��W>");
    set("value",2000);
    set("unit","�i");
  }
  setup();
}
void init()
{
  add_action("do_send","send");
}

int do_send(string str)
{
  object obj, me = this_player(), ob = this_object();
	int i;
  if(!str) return notify_fail("�п�J��誺�^��W�C\n");

  if(ob->query("in_use")) return notify_fail("���ũG�u��Τ@���C\n");
  if( !obj=find_player(str) )
    return notify_fail("�S���o�Ӫ��a�C\n");

	if( me->query_temp("ride") ) 
		return notify_fail("�M�����S��௫�y��z~?~?\n");
  if(obj->money_type() != me->money_type() )
    return notify_fail(obj->name(1)+ "��A�ҳB���ɪŤ��P�A�L�k�i��ǰe�C\n");
  if(!environment(obj) || wizardp(obj) || environment(obj)->query("no_goto") || environment(me)->query("no_goto"))
    return notify_fail("���G���ѤO�q���A�L�k��G�C\n");
	for(i = 0;i<sizeof(club_area);i++)
	{
	if( strsrch(file_name(environment(obj)), club_area[i]) != -1 ) 
		return notify_fail("���b���|�ϰ�C\n");
	}

  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  message_vision(HIR"$N�|�_�⤤��$n�A�}�l�����G�A�u��$N�P�򪺪Ů�}�l�̰ʰ_�� ....\n"NOR,me,ob);
  ob->set("in_use",1);
  me->start_busy(1);
  call_out("walk",2,obj,me,ob);
  return 1;
}

void walk(object obj, object me, object ob)
{
  if(obj)
  {
    message_vision(HIC"\n�@�}�g������A$N�v�����b���H�����e�C\n\n"NOR,me);
    me->move(environment(obj));
    write(NOR""WHT"������ۧA���D�G��F�ت��a�F�A�D�H�C\n"NOR);
    message_vision(HIC"\n�H�ۤ@�}�g���A$N��M�X�{�b���a�I\n"NOR,me);
    write(HIR"����Ŭ�M�N�F�_�ӡI\n"NOR,me);
    destruct(ob);
    return;
  }
  message_vision(HIR"..... ���G����Ƴ��S�o��\n"NOR,me);
  ob->delete("in_use");
  return;
}


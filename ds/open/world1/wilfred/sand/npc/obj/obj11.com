// ........................ �L��  wilfred@DS

#include <ansi.h>
inherit ITEM;
void do_heal(object me);

void create()
{
  set_name("�ϥֱb��",({"tent"}));
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("short","�b�O��");
    set("long",@LONG
�o�O�@�ӥί�÷�i���@���A�H�ϥֻs�����p���b�O�A
�����~����کҨϥΪ��X�j�]�A���ݷf�ذ_�Ӥ~���
�ΡC�i���s�u�Ƭ����W�A�����l�a�C
�ϥΤ�k: use tent
LONG
);
    set("value",400);
  }
  set("no_recall",1);
  set("no_clean_up",1);
  set("no_goto",1);
  set_max_encumbrance(1);
  setup();

}

void init()
{
  add_action("do_sleep","use");
}

int do_sleep(string str)
{
  object ob = this_object(), me = this_player(), *inv;
  int i;
  if(!str || str != "tent") return 0;

  if(me->is_ghost()) return notify_fail("�A�{�b�O����L�k�ϥΦϥֱb�O!\n");
   if(me->query_temp("killer"))
          return notify_fail("�A���F�H�Ȯɤ��i�H�ϥΦϥֱb�O!\n");
   if(me->query_temp("invader"))
     return notify_fail("�A�����F���a�ȮɵL�k�ϥΦϥֱb�O!\n");

  if(me->is_busy() || me->is_fighting())
  {
    write("�A���b���A�S�ŧ@��L�Ʊ��C\n");
    return 1;
  }
  if(me->query("hp") < 0) return notify_fail("�A�֭n�h���Fù���F��I\n");

  if(query("useing") || query("used"))
  {
    inv = all_inventory(environment(this_player()));
    for(i=0;i<sizeof(inv);i++)
      if(inv[i]->query("id") == "tent" && inv[i] != ob) return 0;
    inv = all_inventory(this_player());
    for(i=0;i<sizeof(inv);i++)
      if(inv[i]->query("id") == "tent" && inv[i] != ob) return 0;

    write("�S���h�l���ϥֱb�O�i�ѧA�ϥΤF�I\n");
    return 1;
  }

  set_max_encumbrance(999999);
  if(environment(ob) == me)
  {
    message_vision(CYN"$N���X�@��$n�A�ܧ֪���$n弦n�F�C\n"NOR,me,ob);
    ob->move(environment(me));
  }
  message_vision(HIW"\n$N�@�ӸG���A��$n�p�F�i�h�C\n\n"NOR,me,ob);
  set("long","�o��" +ob->name(1)+ "���b�ϥΤ��C\n");

  set("useing",1);
  set("no_get", 1);
  set("no_sac", 1);

  me->move(ob);
  me->set_temp("sleeping",1);
  me->start_busy(16);
  call_out("do_sleep_1",5,0,me);
  return 1;
}

void do_sleep_1(int index, object me)
{
  object ob = this_object();
  object *obs;
  int i;
  if(!me) destruct(ob);
  if(me->is_ghost() || !environment(me))
  {
    obs = all_inventory(ob);
    for(i=0;i<sizeof(obs);i++)
      obs[i]->move(environment(ob));
    delete("useing");
    delete("no_get");
    delete("no_sac");
    set("used",1);
    call_out("dest_obj",1);
    return;
  }
  if(environment(me) != ob)
  {
    me->delete_temp("sleeping");
    call_out("dest_obj",1);
    return;
  }

  switch(index)
  {
    case 0 : tell_room(environment(ob),HIM+ob->name(1)+"�̶ǨӰ}�}���I�n�C\n"NOR,me);
             write(HIR"\n[�Aı�o���֨I���A���W�N�εۤF]\n\n"NOR);
             do_heal(me);
             break;

    case 1 : write(HIR"\n .......... ��Z�Cz��\n\n"NOR);
             do_heal(me);
             break;

    case 2 : write(HIG"\n���ӫ�Aı�o�믫�n�F�ܦh�A���F�Ө���A�q" +ob->name(1)+ "�̨��F�X�ӡC\n\n"NOR);
             tell_room(environment(ob),HIW+me->name(1)+"�q"+ob->name(1)+"�̨��F�X�ӡC\n"NOR,me);
             set("long","�]�ϥιL���ܱo�}�l������"+ob->name(1)+"�C");
             set_name("�}�l���b��",({"broken tent","tent"}));

             delete("useing");
             delete("no_get");
             delete("no_sac");

             set("used",1);
             me->start_busy(0);
             me->delete_temp("sleeping");
             me->move(environment(ob));
             break;
  }
  index++;
  if(index < 3) call_out("do_sleep_1",12,index,me);
    else call_out("dest_obj",5);
  return;
}

void do_heal(object me)
{
  if(me->query("hp")+450 < me->query("max_hp")) me->add("hp",random(100)+350);
    else me->set("hp",me->query("max_hp"));
  if(me->query("ap")+250 < me->query("max_ap")) me->add("ap",random(50)+150);
    else me->set("ap",me->query("max_ap"));
  if(me->query("mp")+250 < me->query("max_mp")) me->add("mp",random(50)+150);
    else me->set("mp",me->query("max_mp"));
}

void dest_obj()
{
  message_vision("�@�}���j�ӡA�N$N�j���F�C\n",this_object());
  destruct(this_object());
}


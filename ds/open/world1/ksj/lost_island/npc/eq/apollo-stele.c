#include <ansi.h>
inherit ITEM;
        
void create()
{
  set_name(HIY"�Ӷ����۸O"NOR, ({"apollo stele","stele"}) );
  set("long",@LONG
�@�ӤT�H�����j�۸O�A�o�Xģ�������~�A�۸O�W��۩_�Ǫ���r�A��
�r�������ۤ@�ǥW�ѡA�ݼˤl�n���O�n��J����F��(putting)�H
LONG
);
  set_weight(1000);
//  set_max_capacity(4);
//  set_max_encumbrance(50000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "�y");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_putting","putting");
}

int do_putting(string str)
{
  object me=this_player();
  object ob;

  if(str=="armor")
  {
    if(!ob=present("gold armor",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("armor_ok")==1)
    {
      write("�����Z�Ҥw�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�����Z�ҴO��b�۸O�W�����Ҫ��W�Ѥ��C\n"NOR,me);
    set_temp("armor_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="leggings")
  {
    if(!ob=present("gold leggings",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("leggings_ok")==1)
    {
      write("�����H�Ҥw�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�����H�ҴO��b�۸O�W���H�Ҫ��W�Ѥ��C\n"NOR,me);
    set_temp("leggings_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="earring")
  {
    if(!ob=present("gold earring",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("earring_ok")==1)
    {
      write("���������w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N���������O��b�۸O�W���������W�Ѥ��C\n"NOR,me);
    set_temp("earring_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="boots")
  {
    if(!ob=present("gold boots",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("boots_ok")==1)
    {
      write("�������u�w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�������u�O��b�۸O�W���u���W�Ѥ��C\n"NOR,me);
    set_temp("boots_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="finger")
  {
    if(!ob=present("gold finger",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("finger_ok")==1)
    {
      write("�����٫��w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�����٫��O��b�۸O�W���٫����W�Ѥ��C\n"NOR,me);
    set_temp("finger_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="mask")
  {
    if(!ob=present("gold mask",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("mask_ok")==1)
    {
      write("��������w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N��������O��b�۸O�W�����㪬�W�Ѥ��C\n"NOR,me);
    set_temp("mask_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="necklace")
  {
    if(!ob=present("gold necklace",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("necklace_ok")==1)
    {
      write("��������w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N��������O��b�۸O�W�����쪬�W�Ѥ��C\n"NOR,me);
    set_temp("necklace_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="shield")
  {
    if(!ob=present("gold shield",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("shield_ok")==1)
    {
      write("�����޵P�w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�����޵P�O��b�۸O�W���޵P���W�Ѥ��C\n"NOR,me);
    set_temp("shield_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="waist")
  {
    if(!ob=present("gold waist",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("waist_ok")==1)
    {
      write("�����y�a�w�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�����y�a�O��b�۸O�W���y�a���W�Ѥ��C\n"NOR,me);
    set_temp("waist_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }
  if(str=="wrists")
  {
    if(!ob=present("gold wrists",me))
      return notify_fail("�o�˪F��O�����i�h���C\n");
    if(this_object()->query_temp("wrists_ok")==1)
    {
      write("�����@�äw�g�O�W�۸O�F�I\n");
      return 1;
    }
    destruct(ob);
    message_vision(HIY"$N�N�����@�ôO��b�۸O�W���@�ê��W�Ѥ��C\n"NOR,me);
    set_temp("wrists_ok",1);
    call_out("summon_apollo",1);
    return 1;
  }


}

void summon_apollo()
{
  object me,b,ob,env;
  me=this_player();
  ob=this_object();
  env=environment(ob); 

  if(ob->query_temp("armor_ok")==1 && ob->query_temp("shield_ok")==1 
  && ob->query_temp("boots_ok")==1 && ob->query_temp("leggings_ok")==1
  && ob->query_temp("waist_ok")==1 && ob->query_temp("mask_ok")==1
  && ob->query_temp("necklace_ok")==1 && ob->query_temp("earring_ok")==1
  && ob->query_temp("finger_ok")==1 && ob->query_temp("wrists_ok")==1)
  {
    message_vision(HIY"\n�۸O�Ƭ����W���R�ѻڡA�Ӷ����Ъ��iù�q�Ѧӭ��A�N�@����ⲯ�ҥ浹$N�C\n"NOR,me);
    new(__DIR__"apollo-armor")->move(me);
    message("world:world1:vision",
    HIG"\n\t�i��@�q�j�G"+HIY"�Ӷ����Ъ��iù�{���q�W�A�N���W�����ҽ�P"+me->name(1)+"�C\n\n"NOR,users());
    env->set_temp("give_armor",1);
    destruct(ob);
    return;
  }
  else
  {
    message_vision(HIY"\n�۸O���o�X�ƹD�����C\n"NOR,me);
    return;
  }
}

#include <ansi.h>
#include <weapon.h>
#include <path.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
  set_name(HIW"�s��"NOR,({"dragon tooth","tooth"}) );
  set("long",@LONG
�۶ǫC���s�����㦳���H�ٰʤѦa����b��O�A
���s�����������A�o���S��A�Ƭ��_�S�A�n�޵o
��O�q�A�i��ݭn�Y�Ǫ��ơA�ثe�o�L�k�o���C
LONG
);
  set_weight(2500);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit","��");
    set("value",20000);
    set("wield_msg","$N�˳�$n�@�Z���A�y�ɳQ�@�ѱj�l���L�ή�l����¶�C\n");
    set("replica_ob",WD_PAST+"sand/npc/eq/eq23");
  }
  set("beast_weapon_prop/damage",30);
  init_dagger(45);
  setup();
}

void init()
{
  add_action("do_blooding","blooding");
}

int do_blooding(string arg)
{
        object me,ob,ghost,blood;
        me = this_player();
        ob = this_object();
        if(!arg || arg != this_object()->query("id")) return 0;
        if(!objectp(blood=present("dab-aqua blood",me) ) )
                return notify_fail("�A���W�S������������F��C\n");

        message_vision("$N�N�@�������j�b$n�W�C\n",me,this_object());
        call_out("power_up",1);
        destruct(blood);
        return 1;
}

void power_up()
{
  if( !query_temp("power_up") )
  {
    message_vision(HIW"����w�w�����J$N�A�u���|�P�y�ɮ�l�|�g�A�g���j�@�I\n"NOR,this_object());
    this_object()->unequip();
    init_dagger( query("weapon_prop/damage") + 10 );
    this_object()->wield();
    add("backstab_bonus",10);
    set_temp("power_up",1);
  }
  else message_vision(HIW"$N���G�z�X�@�����~�C\n"NOR,this_object());

  if( query("weapon_prop/damage") < 70 )
  {
    this_object()->unequip();
    init_dagger( query("weapon_prop/damage") + (3+random(4)) );
    this_object()->wield();
    add("backstab_bonus",5);
  }

  remove_call_out("power_change");
  if( query_temp("power_up") )
  {
    if( query("weapon_prop/damage") < 60 ) call_out("power_change", 600 + random(600) );
      else call_out("power_change", 400 + random(200) );
  }
  else call_out("power_change", 1000 + random(800) );
}

void power_change()
{
  tell_room(environment(this_object()),"�@�}�s�u���n���}�ѻڡA" +this_object()->name(1)+ "�����~�v���H�h�C\n");
  this_object()->unequip();
  init_dagger(45);
  this_object()->wield();
  set("backstab_bonus",0);
  delete_temp("power_up");
}

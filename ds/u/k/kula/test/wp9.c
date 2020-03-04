#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit STAFF;
void create()
{
  set_name( "���x�k��" , ({ "clorgy wand","wand" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�ſէ������x�Ϊk���A�~�����i��ĳ���]�O�C" HIC "\n���Ūv¡�N(heal)\n" NOR );
    set("material", "wood");
    set("value",10000);
    set("volume",1);
  }
    set("limit_int",25);
  init_staff(4);
  setup();
}

void init()
{
        add_action("do_heal","heal");
}

int do_heal(string arg)
{
        object me;
        me=this_player();

        if( arg )
                if( environment(me) );
        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����I�i�k�N�C\n");
        if( me->query("mp") < 60 )
                return notify_fail("�A���믫��q�����A�L�k�I�񦹪k�N�C\n");
        if( me->query_temp("heal"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision( NOR "$N��ۡG" HIW "\n�j�a���������k�ڡA�Ц��X�p���R������A�v¡��˲��a�I\n" HIC "\n\t�����Ūv¡�N��\n"NOR,me);

        me->set_temp("heal",1);
        me->start_busy(3);
        call_out("do_fullheal",2, me);
        call_out("do_clean",4,me);
        return 1;
}

int do_fullheal(object me)
{
    if(!me) return 0;
      message_vision(HIC"\n$N�������o�X�H�H���ť��A$N���W���ˤf���㪺�ܤ֤F�C\n\n"NOR,me);
      me->receive_heal("hp",random(70)+50);
      me->receive_damage("mp",50);
      return 0; 
}

int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("heal");
          return 1;
}

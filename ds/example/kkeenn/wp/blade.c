#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit SSERVER;
void create()
{
        set_name(HIM"�u"HIY"��"HIR"���T�M"NOR,({"really-skickel","skickel"}) );
        set("long",
        "�o�O�@�⦺���M�Ϊ��I�M, �q��o�X���������C\n"
        "�o��M�ǻ��O�Ѧ�覺���b�ѥ~��ɳB�A�M�V�쪺\n"
        "�]�𥴳y�Ӧ��A�ڻ����y���M�A��O�F�L�ƪ��H�R\n"
        "�M���A�M�C�U�h�s�~�~�������A�Ӧ����g�Q����\n"
        "���M�C( ť���b1500�~�e���������Q�s���D- �C\n"
        "�s�L���Ѥ���, �]�P�ɾP�n�θ�F�C)           \n"
        );
        set_weight(1);
                if (clonep() )
        set_default_object(__FILE__);
                else {
                set("unit","��");
                set("value",1);
                set("volume",3);
                     }
           init_blade(100);
        setup();        
}
void init()
{
        add_action("do_die","die");
}

int do_die(string arg)
{
        object me, target;
        me=this_player();

        if( arg )
                if( environment(me) ) target = present(arg, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�u���s�l��v�u���԰��������ϥΡC\n");

        if( me->is_busy() )
                  return notify_fail("�A���W�@�Ӱʧ@�٨S�������A����l��L�H�C\n");
        if( me->query("mp") < 50 || me->query("ap") < 100 )
                return notify_fail("�A�����骬�p���Ӧn�A�L�k�I��o�j�P���A�G\n");
        if( me->query_temp("die"))
                return notify_fail("�A�w���b�I�i���F�A����A�ΤF�C\n");
        message_vision(HIR"\n$N�@�n�N��, �|�_�⤤�Z��, ��ĤH�ֳt�@���I�I\n\n"NOR,me);
        me->set_temp("die",1);
        me->start_busy(1);
        call_out("do_killed",1, me, target);
        call_out("do_recall",2,me);
        return 1;
} 
int do_killed(object me,object target,int times)
{
  int i;
     if( random(100)>35 && me->query("ap")>80 && me->query("mp")>90 )
  {
    if(!me) return 0;
    if(!target) return 1;
    if(target!=present(target->query("id"), environment(me)))
    {
      me->delete_temp("die");
      return notify_fail("�ؼзW�W�i�i���k���F..\n");
      return 0;
    }
     message_vision(HIR"\n$N���ѧַN����: �^�R, �ڤS���A�l���F�@�ӥ����F�I�I\n\n"NOR,me);
     
    {
         target->set_temp("temp/death_type",MAG"[���]: �����l��]"NOR);
          target->die();
          me->receive("ap",random(2));
          me->add("PKS",1);
          me->receive("mp",random(2));
    }
      return 0; 
   }
   else {
      message_vision(HIR"\n$N���߬�_....�b�̫����Y���F���H�N��\n\n"NOR,me);
          me->receive("hp",random(300));
   return 1;
   }
}
int do_recall(object me)
{
          if(!me) return 0;
          me->delete_temp("die");
          return 1;
}



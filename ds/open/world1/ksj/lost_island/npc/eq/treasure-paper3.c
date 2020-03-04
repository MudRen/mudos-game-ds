#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("�}�ꪺ�ϥ֯�", ({"treasure paper","paper","_TREASURE_PAPER_3_"}));
  set("long",@LONG
�@�i�}�ꪺ�ϥ֯ȡA�W�����Q���N�B�M�ΡB�γE��������A�ݨӦ~�N
���Ӭ۷�[���F�A�ϥ֯ȤW�e�۹��O�a�Ϫ��ϮסC

          ��

                          
                        ��
                      �� 
                ��   
                        �С�  ��
                  �U          �U
            
                      �U    
                �С�          ��
              �U          �U  �U
              
                      �U  
                    �С�

�ϤW���ѵ۸ԲӪ��۹��m�A�b�@�ӽb�Y�ǵe�۫���(dig)���ϼˡC
LONG
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");
    set("volume",1);
    set("value",0);
  }
  setup(); 
}

void init()
{
  object me,z,env;
        if(!userp(environment(this_object()))) return;

  me=this_player();
  env=environment(me);

  if( !env->query("treasure_room3") )
    add_action("do_dig","dig");
}

int do_dig()
{
  object me,z;
  me=this_player();

  if( me->is_busy() )
    return notify_fail("�A�٦b���A�S�ɶ��i������C\n");
  if( !me->query_temp("weapon") )
    return notify_fail("�A���ŪšA�L�k�����a���C\n");

  message_vision(HIW"\n$N�ݬݬݥ|�P����A��M�Y���Ү��A��O�H���U�ȱi�}�l�����C\n"NOR,me);
  me->start_busy(5);
  call_out("dig_nothing",4,me);
  return 1;
}

void dig_nothing(object me)
{
  switch( random(3) )
  {
    case 0:
         message_vision(YEL"\n$N���F�ѥb�ѡA�u���X�F�@�Ӥj�g�ڡC\n"NOR,me);
         destruct(this_object());
         break;

    case 1:
         message_vision(YEL"\n��M���M�@�n�T�A$N�t���ѳߡA���J�Ӥ@�ݭ�ӬO�@�����Y�C\n"NOR,me);
         destruct(this_object());
         break;

    case 2:
         message_vision(YEL"\n$N���۫��۩~�M���X���ӡA�˱o�ۤv�S��Sż�A�o�@�L����C\n"NOR,me);
         destruct(this_object());
         break;
  }
}

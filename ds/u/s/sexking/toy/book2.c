#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIR"�p����L�W�ߪkv1.01(������)"NOR,({ "sexking book","book" }) );
  set("long",HIG"�@���W�j���ܺA�ߪk..�̭��õ�sexking��O�ƤQ�~�ҳЪ����@�Z�\\\n"HIR"���t�����@�Z�\\��:\n"HIC"�L���ܺA�k�o�\\(scr) �Y�H\n"HIY"��g��(pupu) �Y�H\n"HIG"�̲׶��q->"HIM"�ܺA�j���X(and) �Y�H�C"NOR);
  set("unit","��"); 
  setup();
}
void init()
{
 add_action("do_scratch","scr");
 add_action("do_pupu","pupu");
 add_action("do_and","and");
}
int do_scratch(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("�A�Q�n�k�֪��o �S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("�o�̨S���o�ӤH�C\n");
        if( me->is_busy() )
        return notify_fail("�A�٦b��,����k�H�o..\n");
        if(obj==me)
        return notify_fail("�A����ӵu����k�ۤv�o\n");
        message_vision(HIW"\n$N���۸���������$n���I��:���I�����D:���$n��:�K�K!���ѧA�w�g�k���L�ڪ��]�x�F...\n\n"NOR,me,obj);
        me->start_busy(5);
        call_out("no",5,me,obj);
        call_out("no2",8,me,obj);
        call_out("no3",9,me,obj);
        call_out("no4",14,me,obj);
        return 1;
}
int do_pupu(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("�A�Q�n��֩�X�A�S���S�������S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("�o�̨S���o�ӤH�C\n");
        if( me->is_busy() )
        return notify_fail("�A�٦b��,�����.\n");
        if(obj==me)
        return notify_fail("�A�����ä��|�䦺�ۤv\n");
        message_vision(HIY"\n$N�K�K�K�����F�X�n..���ۺC�C����Ǥl��F�U��....\n\n"NOR,me,obj);
        me->start_busy(5);
        call_out("pupu1",5,me,obj);
        call_out("pupu2",8,me,obj);
        call_out("pupu3",13,me,obj);
        return 1;
}
int do_and(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("�A�Q�n�����֪��ͩR�S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("�o�̨S���o�ӤH�C\n");
        if( me->is_busy() )
        return notify_fail("�A�٦b����...\n");
        if(obj==me)
        return notify_fail("�p�G�A���F..sexking�N���~�L�H�F..\n");
        message_vision(HIM"\n$N��M���_�F�Ƨ���..���_�f���b�L�W�٨ө�..�٤W�F�@�ﯻ\n\n"NOR,me,obj);
        me->start_busy(5);
        call_out("and1",5,me,obj);
        call_out("and2",8,me,obj);
        return 1;
}
void no(object me,object obj)
{
     if(!me) return;
     message_vision(HIR"����$N���X�]�⪺��..����$n�����U�ƨg���k�o..�C\n"NOR,me,obj);
     return;
}
void no2(object me,object obj)
{
     message_vision(HIY"$N�V�k�V�_�l..��$n�o�w�g½�_�F�ղ�.�f�R�ժj..�C\n"NOR,me,obj);
     return;
}
void no3(object me,object obj)
{
     message_vision(HIG"$n�������n�w�w�����F�U��,���F���a���O..�����T�F..�n�ޣ��C\n"NOR,me,obj);
     return;
}
void no4(object me,object obj)
{
     message_vision(HIC"����p���׺Ӫ����G..$N���T�]���F�_��..���������C\n"NOR,me,obj);
     obj->set_temp("temp/death_type",HIC"[���즺]"NOR);
     obj->die();
     return;
}
void pupu1(object me,object obj)
{
     message_vision(HIG"�S�h�[..$N�w�g�N���ȷȪ��������S�F�X��.....\n"NOR,me,obj);
     return;
}
void pupu2(object me,object obj)
{
     message_vision(HIR"��M�@�n���T:�u���u���u��..$n�@�Ӥ��p��..���F�o��....\n"NOR,me,obj);
     return;
}
void pupu3(object me,object obj)
{
     message_vision(WHT"������$n�P����O�z��..�����{�L�@�D���v..�˦a���_�F..\n"NOR,me,obj);
     obj->set_temp("temp/death_type",HIY"[�Q�䦺��]"NOR);
     obj->die();
     return;
}
void and1(object me,object obj)
{
     message_vision(HIR"$N��M�ä����ߪ���L�Y��:���$n��:�p�_��!�ڨ��o...\n"NOR,me,obj);
     return;
}
void and2(object me,object obj)
{
   if(random(3))
{
  message_vision(HIY"$N�r�O�ĦV$n..$n���F���@�Ӱ{��,���}�F$N�o�ӣ��ߪ��H�C\n"NOR,me,obj);
  call_out("miss",3,me,obj);
}
  else    
{
  message_vision(HIG"$N�r�O�ĦV$n..�N$n�ꪺ���..�åB���_���b$n���W"HIM"�د��...\n"NOR,me,obj);
  call_out("and3",5,me,obj);
}
return ;
}
void and3(object me,object obj)
{
     message_vision(WHT"$n�]�����F�o�أ����ܺA����E..�ש�r�ަۺ�.�����F�ۤv���ͩR\n"NOR,me,obj);
     obj->set_temp("temp/death_type",HIG"[�Q���ߨ즺]"NOR);
     obj->die();
     return;
}
void miss(object me,object obj)
{
     message_vision(HIR"$N���h�F����..�@�����e��..���F�����ֺL�F�ӭ��Y��..�˦b�a�W�@�ʤ]���ʤF..\n"NOR,me,obj);
     me->set_temp("temp/death_type",HIM"[�L����]"NOR);
     me->die();
     return;
}
int query_autoload() { return 1; }

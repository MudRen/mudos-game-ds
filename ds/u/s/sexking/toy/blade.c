#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"��ʤM"NOR,({ "watermelon blade","blade" }));
        set_weight(1000);
        if( clonep() )
        set_default_object(__FILE__);
        else
        {
        set("long",HIY"�@�������񰫮ɱM�Ϊ���ʤM"HIC"\n������п�J(cut xxx)�C\n");
        set("unit","��");
        set("value",100);
        }
        setup();
}
void init()
{
add_action("do_cut", "cut");
}
int do_cut(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("�A�n���M��� �S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("�o�̨èS���o�ӤH�C\n");
        if( me->is_busy() )
        return notify_fail("�A�٦b��,�����H\n");
        if(obj==me)
        return notify_fail("�A�n��ۤv?\n");
        if(me->query_temp("cutppl2")>100)
        return notify_fail("�A�H�g����ĤF.�ⳡ�@�}�@�h.�C\n");
        message_vision(HIR"\n$N���ۦ�ʤM�ƨg���_������V$n...\n\n"NOR,me,obj);
        call_out("cutcut",1,me,obj);
        me->start_busy(1);
        return 1;
        }
void cutcut(object me,object obj)
{   
     if(random(2))
        {
        call_out("cut1",1,me,obj);
        me->add("cutppl2",1);
        return ;
        }
        else
        {
        call_out("cut2",1,me,obj);
        me->add("cutppl2",1); //����ĥ�
        return ;
}
}
void cut1(object me,object obj)
{
     if(random(2))
{
     message_vision(HIR"$N���_��ʤM�������夤�F$n���y��...�A��Q�X�_�ӡC\n"NOR,me,obj);
     obj->receive_wound("body",1);
     obj->receive_damage("hp",61);
     return;
}
else
{
object bl;
if(!objectp(bl=present("watermelon blade",obj) ) )
{
        message_vision(HIC"$n�@�Ӱ{�����}�F$N���o�M.�C\n"NOR,me,obj);
        return;
}
else
{
message_vision(HIR"$N�����S���..�ٳQ$n�Ϭ�F�@�M�C\n"NOR,me,obj);
me->receive_wound("head",1);
me->receive_damage("hp",72);
return;
}
}
}
void cut2(object me,object obj)
{
     if(random(2))
{
     message_vision(HIR"$N���_��ʤM�������夤�F$n���I��..�d�U�F�@�����`���M�ˡC\n"NOR,me,obj);
     obj->receive_wound("body",1);
     obj->receive_damage("hp",69);
     return;
}
else
{
object bl;
if(!objectp(bl=present("watermelon blade",obj) ) )
{
        message_vision(HIC"$N����իo�Q$n���F�}�ӡC\n"NOR,me,obj);
        return;
}
else
{
message_vision(HIG"$n�H�����ܴ��_��ʤM�פU�F$N���o�M�C\n"NOR,me,obj);
return;
}
}
}

#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(HIY"���M"NOR,({"tea cup","cup"}));
     set_weight(999); 
     set("long",HIC"�y����ѫǪ��D�H�A���L���n�B�ͷǪ������~�A�Х�(taste tea)�ӫ~���C\n"NOR);
     set("no_sac",1);
     set("no_sell",1);
     setup();
}
void init()
{ 
     add_action("do_taste","taste");
}
int do_taste(string arg)
{ 
    object me=this_player();
    if(me->query_temp("tasted")==1) return notify_fail("�A���ܹL�F�A���|��a ^.^\n");
    if(!arg||arg!="tea") return notify_fail("�A�n�ܤ���(tea)?\n"); 
    switch(random(4))
    {
    case 0:
    message_vision(HIW"$N���_���M�A�y�ȡ��z���ܤF�@�f�A��ӤH�����P�E�E�u�n��^.^��\n"NOR,me); 
    me->set_temp("tasted",1);  
    break;
    case 1:
    message_vision(HIW"$N���_���M�A�ӲӪ��~���ۭ��J���f�����~�E�E����Pı�u�n��\n"NOR,me); 
    me->set_temp("tasted",1);
    break; 
    case 2:
    message_vision(HIW"$N���_���M�A�@��D�ۯ����A�@��C�C�~���o���s�Q�s���E�E\n"NOR,me);
    } 
    call_out("stop_tasted",10,me);
    return 1;
}
void stop_tasted()
{
     object me=this_player();
     tell_object(me,"�гܯ� ^.^\n");
     me->delete_temp("tasted");
     return;
}


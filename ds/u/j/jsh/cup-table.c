#include <ansi.h>
inherit ITEM;
void create()
{
     set_name(HIY"����"NOR,({"table"}));
     set_weight(99999999); 
     set("long",HIW"�y����ѫǪ��D�H�A�ΨөۥG�L���B�ͥΪ��A�W�����w�쪺���A�i�H��(take cup)�Ӯ����C\n"NOR);
     set("no_get",1);
     set("no_sac",1);
     set("no_sell",1);
     setup();
}
void init()
{  
     add_action("do_take","take");
}
int do_take(string arg)
{
    object me=this_player(),tcup;
    if(!arg||arg!="cup") return notify_fail("�A�n������(cup)?\n");
    message_vision(HIW"$N�q����W�ݤF�@�M���E�E\n"NOR);  
    {
    tcup=new("/u/j/jangshow/tea-cup");
    tcup->move(environment(this_player()));
    me->set_temp("taked",1);
    }
    call_out("stop_taked",10,me);
    return 1;
}
void stop_taked()
{
    object me=this_player();
     tell_object(me,"Wait la.\n");
     me->delete_temp("taked");
     return;
}


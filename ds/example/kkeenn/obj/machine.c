#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"�ﴫ��"NOR,({"change machine","machine"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�x");
                set("long",
               "�s��ҨϥΪ������A�u�n���۸g�粼�A�N�i�H��o�x���������g��ȡC\n");
             }
        set_weight(1500);     
        set("no_get",1);
        set("no_sac",1);
        setup();
} 
void init()
{
     add_action("do_change","change");
}
int do_change(string arg)
{
    object me,ob;
    me = this_player();
    if(!arg || arg != "ticket from machine") return notify_fail("�A�n������?\n");
    if(!objectp(ob = present("exp ticket",me) ) )
    return notify_fail("�A�S�����i�H�ﴫ��!\n");
    message_vision(HIM"$N��g�粼��b�ﴫ���W�����̡C\n"NOR,me); 
    destruct(ob); 
    tell_object(me,"�]���A�ﴫ���g��ȡA�ҥH�A�Ȯɤ���� 20 �^�X\n");
    me->start_busy(20);
    me->add("exp",3000);
}


inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIW"�K�����b"NOR,({"bagi scroll","scroll"})); 
        set("unit","��"); 
        set("no_give",1);
        set("no_drop",1);
        set("no_sac",1);
        set("long","���õۤK�����Z�\\���������b�A�A�i�H���}�Ӭݬ�(open)�C\n"); 
        setup();
}
void init()
{
     add_action("do_open","open");
}
int do_open(string arg)
{
    object me=this_player(); 
    if(me->query("level")<45) return notify_fail("�A�����Ť������I\n");
    if( !arg || arg=="" || arg !="scroll" ) return notify_fail("�A�n���}����S\n"); 
    { 
    me->start_busy(5); 
    me->set_skill("six_open",1);
    message_vision(HIW"�u���@��ե��q��b��«�X�A$N���O�Q�ĤF�����...\n"NOR,me);
    tell_object(me,HIW"�@�D�D���Z�\\�ۦ����b�X�{�A�A�c�c���O��F�o�ǩۦ��C\n"NOR); 
    write(HIC"�A��M��u�K�����j�}-��v���F��`�@�h���⮩�T(���@�ܲ�1��)\n"NOR); 
    }
    return 1;
}

inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIW"�K�����b"NOR,({"bagi scroll","scroll"})); 
        set("unit","��"); 
        set("no_give",1);
          set("no_get",1);
          set("no_put",1);
         set("value",0);
        set("no_sac",1);
        set("long","���õۤK�����Z�\\���������b�A�A�i�H���}�Ӭݬ�(nopen)�C\n"); 
        setup();
}
void init()
{
     add_action("do_nopen","nopen");
}
int do_nopen(string arg)
{
    object me=this_player();   
    if(me->query("class1") != "�K����")
      {
        write("�A���O�K�������Ǯ{�C\n");
        destruct(this_object());
        return 1;
      }
    if(me->query("level")<45) return notify_fail("�A�����Ť������I\n");
    if( !arg || arg=="" || arg !="scroll" ) return notify_fail("�A�n���}����S\n"); 
    if(me->query_skill("six_open")>0 )
    {   
    tell_object(me,"�A�ǹL���j�}-��F\n"); 
    destruct(this_object());
    return 1;
    } else{
    me->start_busy(5); 
    me->set_skill("six_open",1);
    message_vision(HIW"�u���@�D�ե��q���b��«�X�A$N���O�Q�ĤF�����...\n"NOR,me);
    tell_object(me,HIW"�@�D�D���Z�\\�ۦ��q���b�X�{�A�A�c�c���O��F�o�ǩۦ��C\n"NOR); 
    write(HIC"�A��M��u�K�����j�}-��v���F��`�@�h���⮩�T(���@�ܲ�1��)\n"NOR); 
    destruct(this_object());
    } 
    return 1;
}



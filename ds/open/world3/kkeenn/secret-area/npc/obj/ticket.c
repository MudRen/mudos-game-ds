#include <ansi.h>
inherit ITEM;
void create() 
{
          set_name(HIC"����"NOR,({"ticket"}) );
           set("long","�@�i�B���[�a�U��->�D��]������(use ticket)\n");
               set("value",300);
               set_weight(2000);
            if(clonep() ) 
       set_default_object(__FILE__);
            else {
               set("unit","�i");
                  }
      setup();
}

void init()
{
        add_action("do_use","use");
}

int do_use(string arg)
{ 
        object me,ob;
        if( !this_object() ) return 0;        
        if( !this_object()->id(arg) ) 
   return notify_fail("�A�Q�n�b�o�̨ϥ�ԣ �S\n");
        ob=this_object();
        me=this_player(); 
                message_vision(HIY+me->query("name")+"���X��W�������@��, �@�x�q���ߨ譸�b�Өӧ�"+me->query("name")+"�����F�C\n" NOR ,me);
   me->move("/open/world3/tmr/basic/train_station1.c");
                message_vision(HIY"�q����M�X�{�b�A���e, "+me->query("name")+"�q���W�w�B���X�C\n" NOR ,me);
        destruct(ob);
  return 1;
}


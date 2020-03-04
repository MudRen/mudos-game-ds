#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����",({"sun rock","rock"}));
        set("unit", "��");
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set("inlay_msg","�W������F�賣�S��");        
        setup();
}

void init()
{
        add_action("do_inlay","inlay");
        add_action("do_peen","peen");
        call_out("slong",0);
}

int do_inlay(string arg)
{
        object me,obj,ob;
        ob=this_object();
        me=this_player();
        if(me->is_busy()) return notify_fail("�A�����ۡA�S�ŧ@��L�ơC\n");
        if(arg!="stone into rock" && arg!="alien-beast stone into rock" )
        {
                notify_fail("�A�n�O����W�h?\n");
                return 0;
        }
        if(ob->query("inlayed",1)) return notify_fail("�W�����F�褣��A�O�W�h�F");
        if(obj=present("alien-beast stone",me))
        {
                              
                  message_vision("$N�N$n��W�F�����C\n",me,obj);
                  destruct(obj);
                  ob->set("inlay_msg","�W�����ۤ@���ǲ������Y�i�H�V��(peen)");
                  ob->set("inlayed",1);      
                  call_out("slong",0);
                  return 1;
        }
         else
        {
                tell_object(me,"�A���W�S���i�H�O�W�h���F���\n");
                return 1;
        }
}

int do_peen(string arg)
{
       object me,ob,hammer;
       ob=this_object();
       me=this_player();  
       if(me->is_busy()) return notify_fail("�A�����ۡA�S�ŧ@��L�ơC\n");
       if(arg!="stone")
       {
               notify_fail("�A�n�V������F��?\n");
               return 0;
       }
       if(!hammer = present("hammer",me)) return notify_fail("�A�ݭn�@��l�l�ӺV���C\n");
       if(!ob->query("inlayed")) 
       return notify_fail("�W������F�賣�S���C\n");
       message_vision("$N�|�_�⤤���l�l�A�ϫl���µ۲��~�ۺV�h�C\n",me);
       me->start_busy(2);
       ob->set("inlayed",0);
       call_out("peening",2);
       return 1;
}

int peening()
{
  object me = this_player();
  message_vision("�԰աI���~�۵�������C\n",me);
  new(__DIR__"item/haltdragon-stone")->move(environment(me));
  new(__DIR__"item/halttiger-stone")->move(environment(me));
  return 1;
}

void slong()
{
this_object()->set("long",
"�@����~�l�����𪺥��Y�A�W�����@�ӥW�ѡC�p�G�^�O(inlay)����F��\n"
"�W�h�ݬݪ��ܡA�����w�|���ƻ�_�����Ʊ��o�͡C                   \n"
HIC"" +query("inlay_msg")+ ""NOR"                               \n" 
);
}






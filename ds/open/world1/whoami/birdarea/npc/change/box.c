#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(HIC"�]�N"HIW"��"NOR,({"magic box","box"}));
        set("long","�@�ӥR���]�O�����l�A�A�û������D�̭��|������E�A�i�H���}(reopen)���E\n");
        set("unit", "��");
        set("value", "0"); 
        set("needaward",1000);
        setup();

}

void init()
{
        add_action("do_open","reopen");
}


int do_open(string arg)
{
        object ob,ob1,ob2,me;
        me = this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n���}����H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "box" && arg != "magic box") return 0;

        switch( random(250) ){
        case 0..100:        
         ob = new("/obj/money/coin");
         ob->set_amount(5000+random(50000));
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O�@"+ob->query("unit")+ob->query("name")+"�E\n",me,this_object());         ob->move(this_player()); 
         destruct(this_object());
         break;
        case 101..150: 
         ob1 = new(__DIR__"scroll");
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O"+ob1->query("name")+"�E\n",me,this_object());
          switch(random(3)){
          case 0:
           new(__DIR__"scroll")->move(this_player());  
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player());  
           new(__DIR__"scroll")->move(this_player()); 
           break; 
          case 1: 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           break;
          case 2:
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           new(__DIR__"scroll")->move(this_player()); 
           break;
         }         destruct(this_object());
         break; 
        case 151..200:
         ob2 = new(__DIR__"scroll1"); 
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O"+ob2->query("name")+"�E\n",me,this_object());
         switch(random(3)){
          case 0:
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player());  
           new(__DIR__"scroll1")->move(this_player()); 
           break; 
          case 1: 
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player());  
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player()); 
           break;
          case 2: 
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player());  
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player()); 
           new(__DIR__"scroll1")->move(this_player()); 
           break;
         }         destruct(this_object());
         break; 
        case 201..210:
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M�O"HIY"�m�A�դ@���n"NOR"�E\n",me,this_object());
         break; 
        default:
         message_vision
("\n$N�����Ϋݪ��N$n���}�@�ݡA���G�̭��~�M���򳣨S���H�I\n",me,this_object());
         destruct(this_object());
         break;
        }  return 1;

}


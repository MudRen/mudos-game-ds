#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(HIC"魔術"HIW"盒"NOR,({"magic box","box"}));
        set("long","一個充滿魔力的盒子，你永遠不知道裡面會有什麼•你可以打開(reopen)它•\n");
        set("unit", "個");
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
        return notify_fail("你要打開什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "box" && arg != "magic box") return 0;

        switch( random(250) ){
        case 0..100:        
         ob = new("/obj/money/coin");
         ob->set_amount(5000+random(50000));
         message_vision
("\n$N迫不及待的將$n打開一看，結果裡面居然是一"+ob->query("unit")+ob->query("name")+"•\n",me,this_object());         ob->move(this_player()); 
         destruct(this_object());
         break;
        case 101..150: 
         ob1 = new(__DIR__"scroll");
         message_vision
("\n$N迫不及待的將$n打開一看，結果裡面居然是"+ob1->query("name")+"•\n",me,this_object());
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
("\n$N迫不及待的將$n打開一看，結果裡面居然是"+ob2->query("name")+"•\n",me,this_object());
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
("\n$N迫不及待的將$n打開一看，結果裡面居然是"HIY"《再試一次》"NOR"•\n",me,this_object());
         break; 
        default:
         message_vision
("\n$N迫不及待的將$n打開一看，結果裡面居然什麼都沒有？！\n",me,this_object());
         destruct(this_object());
         break;
        }  return 1;

}


#include <ansi.h>
inherit NPC;
void create()
{
  set_name(HIW"飄靈體"NOR, ({"afflated"}) );
  set("long",@LONG
由怨氣所構成的一種靈體，會依人的外貌，進而去模仿並擁有
對方所有的屬性，是一種可怕的靈體。
LONG
);
  set("unit","顆");
  set("age",300);
  set("level",25);  
  set("chat_chance", 13);
  set("chat_msg",({  
  (:random_move():),
  "飄靈體散發出淡淡的白光....\n",  
        }));
  setup();
}   
/*
void init()
{       
        object ob;
        ::init();
        if( environment(this_player())->query("no_kill") ) return;
        if( environment(this_player())->query("no_fight") ) return;
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        //object me=this_player(); 
        int e_str,e_con,e_int,e_dex,e_name; 
        e_str=ob->query("str");
        e_con=ob->query("con");
        e_int=ob->query("int");
        e_dex=ob->query("dex"); 
        e_name=ob->query_name();
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIW"\n飄靈體發出一道白光！慢慢換化為"+ob->name()+"的模樣...\n"+NOR,ob);  
        this_object()->set("name",e_name); 
        this_object()->set("str",e_str);
        this_object()->set("con",e_con);
        this_object()->set("int",e_int);
        this_object()->set("dex",e_dex);       
        this_object()->save();
        this_object()->receive("hp",2000,this_object());
        } 
}  
*/
void die()
{
   object obj,ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",1);  
  switch( random(100) )
  {
    case  0..1: new(__DIR__"white")->move(this_object());
          break;
    case  2..49: new(__DIR__"red")->move(this_object());
          break;
    case  50..80: new(__DIR__"con")->move(this_object());
          break; 
    case  81..99: new(__DIR__"dex")->move(this_object());
  }

        ::die();
        return;
}



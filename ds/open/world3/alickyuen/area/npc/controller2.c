//updated
#include <ansi.h>
inherit ITEM;
void end_war();
 string *animal=({"animal"});
string *place=({"zoo","zoo2","zoo3","zoo4",
        "zoo5","zoo6","zoo7","zoo11"});
void create()
{
        set_name(RED"��"NOR, ({ "controller" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"�A�u�O�ݨ�o�Ө�W�����@�ӹϮ�\n"
         RED"�@�@�@�@�@�@�U�@�@��\n"NOR
         RED"�@�@�@�@�@�@�U�@���@\n"NOR
         RED"�@�@�@�С@�@�U���@��\n"NOR
         RED"�@�@�@�СССССС�\n"NOR
         RED"�@�@�@�á@���U�@�@��\n"NOR
         RED"�@�@�@�@���@�U�@�@�@\n"NOR
         RED"�@�@�@���@�@�U�@�@�@\n"NOR
                        );
                set("value", 0);
                set("no_get",1);
                  set("no_sac",1);
        }
}
void init()
{
        add_action("typepush","push");
}
int typepush(string arg)
{
        int i;
        object me, ob1, ob2, obj;
obj=this_object();
        me=this_player();
if(obj->query_temp("open_war") ) return 0;
else {
  if(me->query_temp("quest/animal") )
   {
        if (arg != "controller") return 0;
     {
          me->delete_temp("quest/animal");
obj->set_temp("open_war",1);
        message("world:world3:vision",
HIW"\n  "+me->query("name") +HIW "Ĳ�o�FST�CCyberzoo��ĵ����.......\n"
HIW"         ST�CCyberzoo��M�@���V��.....\n"
,users() );
          ob1=new(__DIR__+"controller" );
        ob1->move("/open/world3/alickyuen/area/zoo19.c"); 
        for(i=0;i<=12;i++)
{
        ob2=new(__DIR__+"animal" );
        ob2->move("/open/world3/alickyuen/area/"+place[random(sizeof(place))] ); 
}
call_out("end_war",180);
      return 0;
     }
    }
  }
}
void end_war()
{
        object animal, obj;
obj=this_object();
          if(objectp(animal=find_living("reward-war-animal") ) )
{
       if(!environment(animal)) destruct(animal);
                  call_out("end_war",30);
        }
        else {
                message("world:world3:vision",
HIW"\n\n               �ʪ��骺�޲z�H������F�o���V��...\n\n"NOR
HIW"    �åB�����Fĵ����.....\n\n" NOR
                ,users() );
             obj->delete_temp("open_war");
destruct(obj);
        }       
        return 0;
}

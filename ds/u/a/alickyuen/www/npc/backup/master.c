#include <ansi.h>
#define IN_ROOM "/open/world1/god_club/eldership"

inherit NPC;
inherit SELLMAN;
int qwiz(string arg);

void create()
{
        set_name(HIY"Mr.�����"NOR, ({ "game master","man","master" }) ); 
        set("level",30);
        set("age",45);
        set("gender", "�k��"); 
        set("race", "human");        
        set("long",HIR"���G�i�H�q�o���W���줰��F��H\n"NOR);
        set_temp("freeze",1); 
        set_temp("float",1);
        set("sell_list",([ 
               "/open/always/god_mark" : 1,
               "/open/always/sky_mark" : 1,
               "/open/always/doll"     : 1, 
        ]) );
        setup(); 
 }

void init()
{       
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() )
    {
       remove_call_out("meeting");
       call_out("meeting", 1, ob);
       call_out("qwiz",0);
    }
    add_action("do_fuck","fuck");
    add_action("do_sex","sex");
    add_action("do_doll","doll");
    add_action("do_list","list");
    add_action("do_buy","buy");
}
  
void meeting(object ob)
{
   string id;
   object me = this_player();
   id=me->query("id");
   if( id == "fedex"  ) 
   { 
      message_vision("$N���q����$n���G����z�^�өԡI\n"NOR,this_object(),me);
      this_object()->set("creater",me); 
   }
   else
   {
      message_vision(HIY"$N"NOR+"�K�۬��Y��$n���G�A�O�֡H\n"NOR,this_object(),me);
   }
}

int do_fuck(string arg)
{
   object me;
   me = this_player();
        
   if(arg!="game master" && arg!="master" )
   { return notify_fail("�A�n�F���H\n"); }

   message_vision("$N�λ��ƪ��f���$n���G�A�O�b��ԣ�p�H\n",me,this_object());
   tell_room(environment(me),HIW"�áH�I"+me->name()+"����M�����F�H�H\n"NOR,({me}));
   me->move(IN_ROOM);
   write(HIG"�A��F���ѫǡC\n"NOR);
   tell_room(environment(me),HIW+me->name()+" �q�u�@�Ǩ��F�L�ӡC\n"NOR,({me}));
   return 1;    
}

int do_doll(string arg)
{
   object me,obj;
   me = this_player();
   obj = new("/open/always/doll");
   message_vision("$N�������F�@"+obj->query("unit")+obj->name()+"��$n�C\n",this_object(),me);
   obj->move(me);
   return 1;     
}

int do_sex(string arg)
{
   object me,obj; 
   me = this_player();
   obj = new("/obj/money/coin");    
   obj->move(environment(me)); 
   message_vision("$N��U�@"+obj->query("unit")+obj->name()+"�C\n",this_object());
   return 1;    
}

int qwiz(string arg)
{
   int i,j=1,n,idle;
   object *user_list,where;
   string status1,status2,status3,status4,status5;
   user_list = users();
   n = sizeof(user_list);
   write(sprintf("��"HIC"�ڤۤC��"NOR"   %s\n",ctime(time())));
      write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
       for( i=0 ;i<n ;i++)
       {
           if(wizardp(user_list[i]))
           {
              where = environment(user_list[i]);
              idle = query_idle(user_list[i]);
              if(user_list[i]->query_temp("invis")) status1=HIB"(����)"NOR;
                  else status1="";                         
              if(idle>=60) status2=sprintf(HIY"(�o�b"+"%d"+"����)"NOR,idle/60);
                  else status2=""; 
              if((in_edit(user_list[i]))) status3 = sprintf(HIY"([�s��]: %s)"NOR,in_edit(user_list[i]));
                  else status3="";
              if(in_input(user_list[i])) status4=HIC"<��J>"NOR;
                  else status4="";
              if(user_list[i]->query_temp("netdead")) status5=HIB"(�_�u)"NOR;
                  else status5="";
              write(sprintf("%12s "WHT+"%10s"NOR+"(%10s) ���b %s(%s)%s%s%s%s%s\n",RANK_D->query_rank(user_list[i]),
                  user_list[i]->query("name"),
                  user_list[i]->query("id"), 
                  (string)where->query("short"),
                  (string)file_name(where),
                  status1,status2,status3,status4,status5)); 
                  j++;
           }
       }
       write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
       this_player()->start_more(sprintf("�ثe�@�� %d ��wiz�b�u�W.\n",j-1));
       return 1;
}

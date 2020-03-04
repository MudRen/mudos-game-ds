#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);
int room_effect(object me);
int check_light();
string look_mirror();
mapping turn_mirrors = ([        "north":                "�_",
        "south":                "�n",
        "east":                 "�F",
        "west":                 "��",
        "northeast":            "�F�_",
        "northwest":            "��_",
        "southeast":            "�F�n",
        "southwest":            "��n",
        ]);
void setroom()
{      
       string *mirrors;
       mirrors=keys(turn_mirrors);
       set("no_clean_up",0);
       set("light",1);
       set("no_map",1);
       set("no_recall","�o�̳���ӭ��W��ť����A�I�ꪺ\n");
       set("light_on",mirrors[random(sizeof(mirrors))]);
}  

void init()
{ 
      add_action("do_turn","turning");
}

int room_effect(object me)
{      
      int light,co;
      co=me->query_con()/15;
      if(!userp(me))  //���a�~�|�Q����
      return 0;
      if(co>8)
         light=8;          
      else if(co>=7)
         light=7;
      else if(co>=6)
         light=6;
      else if(co>=5)
         light=5;
      else if(co>=4)
         light=4;
      else if(co>=3)
         light=3;
      else if(co>=2)
         light=2;
      else   
         light=1;
       if(light>6)
        light-=random(2);
       if(light<3)
        light+=random(2);
       if(random(2))
       switch(light){
    case 8: message_vision(HIY"$Nĵı��@�D���Wŧ��,$N���j�j�u������\n"NOR,me);
            me->receive_damage("hp",15+random(20));
            return 1;
    case 7: message_vision(HIY"$N�ݨ�P����u����l,$N�ܧ��ਭ�k�L�u���@�I��\n"NOR,me);  
            me->receive_damage("hp",15+random(30));
            return 1;
    case 6: message_vision(HIY"����r�M�X�{�@�Υ���,$N�ꥩ�{�L�u���@�Ƕ�\n"NOR,me);
            me->receive_damage("hp",25+random(40));
            return 1;         
    case 5: message_vision(HIY"���䩿�M�_�X�\\�h����,$N�a���w�O���U�u���p��\n"NOR,me);
            me->receive_damage("hp",35+random(40));
            return 1;         
    case 4: message_vision(HIY"$N���ǫ����@�n�X�{����,$N�j�j���U���F�ж�\n"NOR,me);
            me->receive_damage("hp",35+random(50));
            return 1;    
    case 3: message_vision(HIY"$N�S�`�N�쨭��X�{���W,$N�Q���N�ˤF\n"NOR,me);
            me->receive_damage("hp",35+random(60));
            return 1;    
    case 2: message_vision(HIY"$N��פ����h���n,$N���F�Y���ˮ`\n"NOR,me);
            me->receive_damage("hp",45+random(60));
            return 1;                  
    case 1: message_vision(HIY"$N�]�����_�Q���W����,$N���F���j�ж�\n"NOR,me);
            me->receive_damage("hp",55+random(60));
            return 1;   
    }       
}

int do_turning(string arg)
{
 object me,ob,aliroom,env;
 string turnof,str="",area;
 int lightno;
 me=this_player();
 env=environment(me);
 turnof=env->query("light_on");
 aliroom=env->query("light_room");
 lightno=env->query("light_number");
 area=env->query("light_area");
 if(me->is_busy() || me->is_fight())
 return notify_fail("�A���b��..�S�Ű��o���..\n");
 if(!lightno) return 0;
 if(!arg)
 return notify_fail("�A�Q�र��?\n");
 if(undefinedp(turn_mirrors[arg]))
 return notify_fail("�ѷ��褣���਺�Ӥ��\n"); 
 message_vision(HIY+"$N��ʤF�ѷ���,�o�X�F�@�D������~\n"NOR,me);
 aliroom->set("list/"+lightno,arg);
 if(arg==turnof)
 if(aliroom->check_light())
 {
  str+="$N�N�ѷ���������զX�n�F\n";
  str+="$N�Q�@�D��Ţ�n��...���M�����F\n"; 
  me->move(__DIR__"folight_move");
  message_vision(HIR+str+NOR,me);
  load_object(__DIR__"folight_move")->set("pass/"+area,1); }
 return 1;
}

int check_light()
{
 int i;
 string lightpath,file,turnof,*list;
 mixed newturn;
 mapping rights;
 list=query("light_list");
 rights=query("list");
 lightpath="folight_";
 for(i=0;i<sizeof(list);i++)
 {
  file = resolve_path(__DIR__,lightpath+list[i]);
  file +=".c";
  turnof=load_object(file)->query("light_on");
  newturn = rights[list[i]];
  if(newturn==turnof) continue;
  else 
   return 0;
 }
 return 1;
}    

string look_mirror()
{
 string item,chitem,msg="",*mirrs;
 object me,ob;
 int co,anti;
 me=this_player();
 ob=this_object();
 item=ob->query("light_on");
 co=me->query_con();
 anti=me->query_skill("anti_poison")/10;
 mirrs=keys(turn_mirrors);
 if(co/2 + anti > random(65) ) chitem=turn_mirrors[item];
 else
 {
  mirrs-=({item});
  chitem=mirrs[random(sizeof(mirrs))];
  chitem=turn_mirrors[chitem];
 } 
 msg+="�A�ݨ�ѷ���n���i�H���(turning)�A�ӥB���@�D���~��";
 msg+=chitem+"��V�ӨӡC\n";
 return HIY+msg+NOR;
}

int valid_leave(object me, string dir)
{
  object env=environment(me),*inv;
  mapping exits;
  int i; 
  inv = all_inventory(env);
  exits = env->query("exits");
  if(undefinedp(exits[dir])) return 0;
    for(i=0;i<sizeof(inv);i++)
   {
      if(living(inv[i]) && inv[i]->query("fong_guard")  )
      {
        if( inv[i]->is_corpse() ) continue;
        message_vision(HIW"$N�ĤF�X�Ӿצ�A���h��\n"NOR,inv[i]);
        return notify_fail("");       
      }
   }
  return ::valid_leave(me, dir);
}










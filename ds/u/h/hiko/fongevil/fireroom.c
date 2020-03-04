#include <ansi.h>
inherit ROOM;
int fire_move(object me);
int valid_leave(object me, string dir);
int room_effect(object me)
{      
      int fire,st;
      st=me->query_str()/15;
      if(!userp(me)) //�D���a���|�Q����
      return 0;
      if(st>=7)
         fire=7;          
      else if(st>=6)
         fire=6;
      else if(st>=5)
         fire=5;
      else if(st>=4)
         fire=4;
      else if(st>=3)
         fire=3;
      else if(st>=4)
         fire=2;
      else 
         fire=1;
 
    if(fire>5)
       fire-=random(2);    
    if(fire<3)
       fire+=random(2);
       if(random(2))
       call_out("fire_move",2,me);
       switch(fire){
     case 7:                   message_vision(HIR"$N�Q��Mŧ�Ӫ����yŧ��,$N�a�j�j�O�q�Y�ɰ{�L�u������\n"NOR,me);
            me->receive_damage("hp",10+random(10));
            return 1;
    case 6: message_vision(HIR"���M�X�{�@�D���W,$N�����֥u���@�I��\n"NOR,me);
            me->receive_damage("hp",10+random(30));
            return 1;         
    case 5: message_vision(HIR"���e���F���]�X�@�Τ�,$N���t�j��u���p��\n"NOR,me);
            me->receive_damage("hp",20+random(40));
            return 1;         
    case 4: message_vision(HIR"$N�}��_�X���],$N�ֳt��h���F�Ƕ�\n"NOR,me);                        me->receive_damage("hp",30+random(50));
            return 1;         
    case 3: message_vision(HIR"$N�@�ɤ��`�N����X�{���K,$N�Q�N�ˤF\n"NOR,me);                 me->receive_damage("hp",50+random(50));
            return 1;         
    case 2: message_vision(HIR"����X�{����,$N�Ӥ��ΰ{��,�Q��������\n"NOR,me);                 me->receive_damage("hp",60+random(60));
            return 1;        
    case 1:  message_vision(HIR"$N�P��@������,�@���Q�N��\n"NOR,me);                                       me->receive_damage("hp",40+random(100));
           return 1;  
      }       
}

int fire_move(object me)
{
        object env=environment(me);
        mapping exits;
        int fst=me->query_str();
        string *dirs;
        exits = env->query("exits");
        if(!me || me->is_fighting() || !userp(me)) return 0;
        if(env->query("boss")) //boss�Ф�move 
        return 0; 
        if(fst/2>60) fst=60; 
        else fst=fst/2;        
        if(fst>20+random(60)) return 0;
        if( !mapp(exits) ) return 0;
        if( sizeof(exits) < 1 ) return 0;
        dirs = values(exits);
        message_vision(HIR"$N��M�Q���K�r�P�����W�h�A�@�ɦ��դ���Q�����F�C\n"NOR,me);
        me->move(dirs[random(sizeof(dirs))]);           me->receive_damage("hp",10+random(20));                       tell_room(environment(me),"$N��M���F�L�ӡA���W�ٱa�ۤ���C\n",({me}));
        return 1;
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



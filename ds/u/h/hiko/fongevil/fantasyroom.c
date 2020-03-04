#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);
int room_effect(object me);
mapping default_dirs = ([
        "north":                "�_",
        "south":                "�n",
        "east":                 "�F",
        "west":                 "��",
        "northup":              "�_��",
        "southup":              "�n��",
        "eastup":               "�F��",
        "westup":               "����",
        "northdown":            "�_��",
        "southdown":            "�n��",
        "eastdown":             "�F��",
        "westdown":             "����",
        "northeast":            "�F�_",
        "northwest":            "��_",
        "southeast":            "�F�n",
        "southwest":            "��n",
        "up":                   "�W",
        "down":                 "�U",
        "enter":                "��",
        "out":                  "�~",
        "exit":                 "�X�f",
]);
void setroom()
{
       set("no_clean_up",0);
       set("light",1);
       set("no_map",1);
       set("no_recall","�o�̳���ӭ��W��ť����A�I�ꪺ\n");
}  
int do_chgo(object me,string arg)
{ 
     mixed newexit;
     object env,ride;
     mapping exits;
     int i,invied=0; 
     string dir,*dirs,who,min,mout,no_go;
     env=environment(me);
     exits=env->query("exits");
     no_go=env->query("no_random_move");
     ride=me->query_temp("ride");
     dirs=keys(exits);
     dirs-=({no_go});
     dir=dirs[random(sizeof(dirs))];
     newexit=exits[dir];      
     who=me->name();
     if(ride) who=who+"�M��"+ride->name();
     if( !undefinedp(default_dirs[dir]) )
                        dir = default_dirs[dir];
                else
                        dir = dir;
     mout = "��" + dir + "���}�C\n";
     if(me->query("race")=="human")
     min = "�Ө즹�a�C\n";
     else min = "�Ө즹�B�C\n";
     if(wizardp(me))
     message_vision(HIM"$N�Q�۹ҩҰg�b�F��V"+dir+"\n"NOR,me);   
     if(me->query_temp("invis") < 1 )
     {
                message( "vision", who + mout, environment(me), ({me}) );
     }
     else invied=1;
     me->move(newexit);
     if(!invied)
     {
       message("vision", who + min, environment(me), ({me}) );
       all_inventory(env)->follow_me(me, arg);
     }
     return 1;   
} 
int room_effect(object me)
{      
      int fantasy,fin,lin;
      fin=me->query_int()/15;
      lin=me->query_skill("literate",1)/23;
      if(!userp(me))  //���a�~�|�Q����
      return 0;
      if(fin+lin>=8)
         fantasy=8;          
      else if(fin+lin>=7)
         fantasy=7;
      else if(fin+lin>=6)
         fantasy=6;
      else if(fin+lin>=5)
         fantasy=5;
      else if(fin+lin>=4)
         fantasy=4;
      else if(fin+lin>=3)
         fantasy=3;
      else if(fin+lin>=2)
         fantasy=2;
      else   
         fantasy=1;
       if(fantasy>6)
        fantasy-=random(2);
       if(fantasy<3)
        fantasy+=random(2);
       if(random(2)) //���v�A1/2..���C�X�{�v
    switch(fantasy){
    case 8: message_vision(HIM"$N���e���M�X�{�ۼv,$N���ֿ�{�X�u���u������\n"NOR,me);
            me->receive_damage("hp",10+random(10));
            return 1;
    case 7: message_vision(HIM"$N�Q��M�{�{���ۼv����,$N�Y�ɹ�ı�u���@�I��\n"NOR,me);  
            me->receive_damage("hp",10+random(20));
            return 1;
    case 6: message_vision(HIM"���e�X�{�@���۹�,$N���t�o�{�}��u���@�Ƕ�\n"NOR,me);
            me->receive_damage("hp",20+random(30));
            return 1;         
    case 5: message_vision(HIM"���e��ۼv�s�����_,$N�ή�ĵı�u���p��\n"NOR,me);
            me->receive_damage("hp",25+random(30));
            return 1;         
    case 4: message_vision(HIM"$N����@�ɶ��۶H�j�@,$N�oı�ӱߨ���ж�\n"NOR,me);
            me->receive_damage("hp",25+random(40));
            return 1;    
    case 3: message_vision(HIM"$N�S�`�N�쨭�ǥX�{�ۼv,$N�Q�ۼv���ˤF\n"NOR,me);
            me->receive_damage("hp",25+random(50));
            return 1;    
    case 2: message_vision(HIM"$N�L�k���O���e�۹�,$N���F�Y���ˮ`\n"NOR,me);
            me->receive_damage("hp",35+random(50));
            return 1;                  
    case 1: message_vision(HIM"$N�]���@���Q�۶H���F����,$N���F���j�ж�\n"NOR,me);
            me->receive_damage("hp",45+random(50));
            return 1;   
    }       
}

int valid_leave(object me, string dir)
{
  object env,*inv;
  int i,fin,lit;
  env=environment(me);
  inv = all_inventory(env);
  fin = me->query_int()/2;  //���z/2  
  lit = me->query_skill("literate",1)/7; //sk literate/7  
  for(i=0;i<sizeof(inv);i++)
   {
      if(living(inv[i]) && inv[i]->query("fong_guard")  )
      {
        if( inv[i]->is_corpse() ) continue;
        message_vision(HIW"$N�ĤF�X�Ӿצ�A���h��\n"NOR,inv[i]);
        return notify_fail("");       
      }
   }  
   if(random(fin)*3/4 + lit + fin > 20 + random(60))
   {
     return ::valid_leave(me, dir);
   }
   else
   {
    do_chgo(me,dir);  //�γo�ؤ覡�O�]���p�G�ϥ�do_go...�|�����a�i�H��alias x xxx             
    return 0;         //�Ӱk�L�P�w...���L�ܳ·дN�O..-.-
   } 
}











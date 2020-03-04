#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);
int room_effect(object me);
void setroom()
{
       set("no_clean_up",0);
       set("light",1);
       set("no_map",1);
       set("no_recall","�o�̳���ӭ��W��ť����A�I�ꪺ\n");
}  

void init()
{ 
      add_action("do_unsling","unsling");
}

int room_effect(object me)
{      
      int water,de,swim;
      de=me->query_dex()/14;
      swim=me->query_skill("swim",1)/18;
      if(!userp(me))  //���a�~�|�Q����
      return 0;
      if(de+swim>8)
         water=8;          
      else if(de+swim>=7)
         water=7;
      else if(de+swim>=6)
         water=6;
      else if(de+swim>=5)
         water=5;
      else if(de+swim>=4)
         water=4;
      else if(de+swim>=3)
         water=3;
      else if(de+swim>=2)
         water=2;
      else   
         water=1;
       if(water>6)
        water-=random(2);
       if(water<3)
        water+=random(2);
       if(random(2))
       switch(water){
    case 8: message_vision(HIB"$N�ݨ�e��X�{�@�D���W,$N�a���ֳt�װ{�L�u������\n"NOR,me);
            me->receive_damage("hp",10+random(20));
            return 1;
    case 7: message_vision(HIB"$N�Q��Mŧ�Ӫ����W����,$N���t�j���׹L�u���@�I��\n"NOR,me);  
            me->receive_damage("hp",10+random(30));
            return 1;
    case 6: message_vision(HIB"���M�X�{�@�Τ��y,$N�ֳt�{�L�u���@�Ƕ�\n"NOR,me);
            me->receive_damage("hp",20+random(40));
            return 1;         
    case 5: message_vision(HIB"���e��M�ԼM�ԽĥX��,$N�j�O�{�L�u���p��\n"NOR,me);
            me->receive_damage("hp",30+random(40));
            return 1;         
    case 4: message_vision(HIB"$N����r�M�X�{����,$N��������L���F�ж�\n"NOR,me);
            me->receive_damage("hp",30+random(50));
            return 1;    case 3: message_vision(HIB"$N�S�`�N�쨭��X�{����,$N�Q�����ˤF\n"NOR,me);
            me->receive_damage("hp",30+random(60));
            return 1;    case 2: message_vision(HIB"$N�@����j�j����,$N���F�Y���ˮ`\n"NOR,me);
            me->receive_damage("hp",40+random(60));
            return 1;                  
    case 1: message_vision(HIB"$N�]�����_�Y���Ӷ��,$N���F���j�ж�\n"NOR,me);
            me->receive_damage("hp",50+random(60));
            return 1;   
    }       
}

int do_unsling(string arg)
{
        object me,ob,oproom;
        string open,moveto,cango;
        int fde,swim;
        me=this_player();
        ob=environment(me);
        open=ob->query("open_room");       
        cango=ob->query("can_go");
        fde=me->query_dex()/2; //�ӱ�/2
        swim=me->query_skill("swim",1)/4; //sk ��a/4
        moveto=ob->query("move_room");
        if(!open) return 0;
        if(arg!="robe" && arg!="÷�l") return notify_fail("�A�n�񱼤���?\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�L�k�M�����I���ʧ@�C\n");         
        if(!oproom=load_object(open)) return notify_fail("�X���D�F..�֧�wiz��\n");
        if(random(fde*3/2) + fde/2 + swim > 20+random(65))
          {
            message_vision(HIB"$N��÷�l��}��,�ǨӤ@�}�F�F�n...������h����\n"NOR,me);
            oproom->set(cango,1);
            return 1;
          }         else
          {
           message_vision(HIB"$N�@�ɤ��`�N�Q���W������,���M�Q�R���F\n"NOR,me);
           me->move(moveto);  
           return 1;
          }
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
   if(env->query("high_water")==dir) //�ˬd�O���O=�����쪺��V
    {
      if(!env->query("can_go1") && !env->query("can_go2")) //�ˬd���S�������} 
       { 
        message_vision(""+dir+"����Ӱ��F$N�L�k��L\n",me);
        return notify_fail("");
       }
      //�аO�R��
      env->delete("can_go1");       env->delete("can_go2");
      message_vision("$N�X�ۤ�����h�ɻ������h\n",me);
      return ::valid_leave(me, dir);
    }
   return ::valid_leave(me, dir);
}









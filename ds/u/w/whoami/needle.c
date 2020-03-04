#include <weapon.h>
#include <ansi2.h>
inherit DAGGER; 
object ob2;
void create()
{
        set_name("�Ȱw", ({ "silver needle","needle" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��"); 
                set("long", "�o�O�@�ڦ���̥��ƪ��Ȱw�A�P�ɤ]�O�ѱ��бв��̪��H���E��\n"
                            "�O���D�䤤���K���A�o�u���ֳ������ѱ��̤l�̡E\n");
//                set("no_drop", 1);
//                set("no_give", 1);
//                set("no_sac", 1);
                }
        setup();
}

void init()
{
 if(this_player()!=environment(this_object())) return;
        add_action("do_help","help");
        add_action("do_acupuncture","acupuncture");
}

int do_acupuncture(string str)
{
        object ob1,me;
        string st1,st2,*limbs,limb,msg,*msgs,msg1;
     
int mywit,mydex,tdex,myint,tint,mylv,tlv,mysk,tdodge,mytec,ttec,maxhp,attackon,damage;

        me=this_player();
        mysk=me->query_spell("moxibustion");
        myint=me->query("int");
        mylv=me->query("level");
        mytec=me->query_Merits("tec");
        limbs = ({ "�Y��","����","�ⳡ","�}��" });
        msgs  = ({
HIC"\n    �ʪ�d��U���~\n"
   "                  �����������_�r\n"NOR,
HIC"\n    ���ѤѤU�a�ͺ�\n"
   "                  �t�|�ʯ�y�B�O\n"NOR,
HIC"\n    �P�s�F�Ī����I\n"
   "                  �{���k�ì��a��\n"NOR,
HIC"\n    �k���a�V�H���k\n"
   "                  ���D�o�D�n�Ѿ�\n"NOR,
HIC"\n    ���A�ʯ�ϤѤU\n"
   "                  �򯪪x���粳��\n"NOR,
HIC"\n    �t��d���W�g�s�A���D�P�s�F�ۤY\n"
   "    �M��������ڹC�A�ֻ��䤤�L�֧t\n"NOR,
HIC"\n    �~���r��d�U�^�A���o���P�~�g��\n"+
   "    �ݩt�H������Z�A�ϱo�U�F��R�^\n"NOR,
                                });
 
       msg = msgs[random(sizeof(msgs))];

        if( me->query("class1") != "�ѱ���")
           return notify_fail("�u���ѱ��бЮ{�~��ϥΪ��ްw�b�E\n");
        if( me->is_busy() )
           return notify_fail("�A�{�b���b���A�L�k�ϥΪ��ްw�b�I\n"); 
        if( !present("needle",me) )
           return notify_fail("�A�������w�~��ϥΪ��ްw�b�E\n");
        if( me->query("hp") < 300 || me->query("ap") < 300 || me->query("mp") < 300
            || me->query("wound/left_arm") > 10 || me->query("wound/right_arm") >10 )
           return notify_fail("�A�{�b���骬�p���εL�k�ϥΪ��ްw�b�E\n"); 
        if (!str || str=="") 
           return notify_fail ("�Х�help needle�d�ߥi�Ϊ��\\��E\n");
        if (sscanf( str,"%s on %s",st1,st2)!=2 )
        return notify_fail ("acupuncture <ob1> on <ob2>\n");
           if (!ob2=present(st2,environment(this_player())))
              return notify_fail("�䤣�� "+st2+" �o�ӥͪ�.\n");
           if(!ob2->is_character() || ob2->is_corpse())
              return notify_fail("�A�ݲM���@�I�A���ä��O�����C\n");

     switch( st1 ) {
       
       default:
          tell_object(me,"�Х�help needle�d�ߥi�Ϊ��\\��E\n");
        break;       

       case "rekee":

             if( me->is_fighting() )
              return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");
             if ( me->query("level") < 15 )
              return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
             if ( mysk < 5 )
              return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"����Z"NOR"�n�E\n");  
             if ( ob2->query("hp") >= ob2->query("max_hp") )
              return notify_fail(ob2->query("name")+"�èS�����ˡE\n");
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+NOR
YEL"\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"NOR+
HIW"\n    �w�w�w�m"HIY" �� �� �Z"HIW" �n�w�w�w\n"+NOR
+msg,me);
               me->start_busy(2-myint/50);  
               me->receive_damage("ap",mysk*2 - myint/2 ); 
     if ( (mysk + myint + mylv/5 ) >= random(25) ){
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
               ob2->receive_heal("hp",mysk*2); 
               me->improve_spell("moxibustion",random(myint/10));
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
        break;
      
      case "regin":      

           if( me->is_fighting() )
              return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");
           if ( me->query("level") < 15 )
              return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
           if ( mysk < 5 )
              return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIG"����Z"NOR"�n�E\n");  
           if ( ob2->query("ap") >= ob2->query("max_ap") )
              return notify_fail(ob2->query("name")+"�����l�R�K�E\n");
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+NOR
YEL"\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"NOR+
HIW"\n    �w�w�w�m"HIG" �� �� �Z"HIW" �n�w�w�w\n"+NOR
+msg,me);
                me->start_busy(2-myint/50); 
                me->receive_damage("mp",mysk*2 - myint/2); 
     if ( (mysk + myint + mylv/5 ) >= random(25) ) {
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("ap",mysk*2); 
                me->improve_spell("moxibustion",random(myint/10));
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
        
      break; 

      case "resen":
   
           if( me->is_fighting() )
                return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");
           if ( me->query("level") < 15 )
              return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
           if ( mysk < 5 )
              return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"NOR+MAG"�����Z"NOR"�n�E\n");  
           if ( ob2->query("mp") >= ob2->query("max_mp") )
               return notify_fail(ob2->query("name")+"���]�O�R�K�E\n");
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+NOR
YEL"\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"NOR+
HIW"\n    �w�w�w�m"NOR+MAG" �� �� �Z"HIW" �n�w�w�w\n"+NOR  
+msg,me);
                me->start_busy(2-myint/50); 
                me->receive_damage("ap",mysk*2 - myint/2); 
      if ( (mysk + myint + mylv/5 ) >= random(25) ){
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("mp",mysk*2); 
                me->improve_spell("moxibustion",random(myint/10));
                return 1;
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break; 
     case "advkee":
          if( me->is_fighting() )
               return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");
          if ( me->query("level") < 20 )
               return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
          if ( mysk < 20 )
               return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"���@�Z"NOR"�n�E\n");  
          if ( ob2->query("hp") >= ob2->query("max_hp") )
               return notify_fail(ob2->query("name")+"�èS�����ˡE\n");
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+NOR
YEL"\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"NOR+
HIW"\n    �w�w�w�m"HIC" �� �@ �Z"HIW" �n�w�w�w\n"+NOR
+msg,me);
                me->start_busy(3-myint/50); 
                me->receive_damage("ap",mysk*2 - myint/4); 
    if ( (mysk + myint + mylv/5 ) >= random(50) ){
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("hp",mysk*2+myint); 
                me->improve_spell("moxibustion",random(myint/10));
    return 1;
     } else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break; 

     case "sky":
          if( me->is_fighting() )
               return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");        
          if ( me->query("level") < 20 )
               return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
          if ( mysk < 20 )
               return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIR"�}�ѳZ"NOR"�n�E\n");  
          if ( ob2->query("hp") >= ob2->query("max_hp") )
               return notify_fail(ob2->query("name")+"�èS�����ˡE\n");
          if ( ob2->query("ap") >= ob2->query("max_ap") )
               return notify_fail(ob2->query("name")+"�����l�R�K�E\n");
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+NOR
YEL"\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"NOR+
HIW"\n    �w�w�w�m"HIR" �} �� �Z"HIW" �n�w�w�w\n"+NOR
+msg,me);
                me->start_busy(3-myint/50); 
                me->receive_damage("mp",mysk*2 - myint/4 + mylv); 
if ( (mysk + myint + mylv/5 ) >= random(50) ){
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_heal("hp",mysk*2+myint+mylv); // �^�_HP
                ob2->receive_heal("ap",mysk*2+myint+mylv); // �^�_AP
                me->improve_spell("moxibustion",random(myint/10));
                return 1;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break; 
     case "heal":
          if( me->is_fighting() )
               return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");
          if ( me->query("level") < 20 )
               return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
          if ( mysk < 30 )
               return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"¡���Z"NOR"�n�E\n");  
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+NOR
YEL"\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"NOR+
HIW"\n    �w�w�w�m"HIC" ¡ �� �Z"HIW" �n�w�w�w\n"+NOR
+msg,me);
               me->receive_damage("mp",mysk/4);
               me->start_busy(2-myint/50);
if ( (mysk + myint + mylv/5 ) >= random(70) ){
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
                ob2->receive_curing("all",mysk/10+myint/20); 
                me->improve_spell("moxibustion",random(myint/10));
        return 1;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break;
     case "addint": 
     if( me->is_fighting() )
        return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");     
     if ( me->query("level") < 27 )
        return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");        
     if ( mysk < 50 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIW+BLK"���߳Z"NOR"�n�E\n");  
     if ( ob2->query("int") < 30 || ob2->query("level") < 27){
        tell_object(me,ob2->query("name")+"�����L�k�Ө��m"HIW+BLK"���߳Z"NOR"�n�E\n");
        return 1;
        }
     if ( ob2->query_temp("e_int") >= 1 ){
         tell_object(me,ob2->query("name")+"�w�g�����L�m"HIW+BLK"���߳Z"NOR"�n�F�E\n");
     } else {
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+
   "\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"+NOR
HIW"\n    �w�w�w�m"BLK" �� �� �Z"HIW" �n�w�w�w\n"+NOR                   
+msg,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         call_out("enhance",2,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(110) ){
         ob2->add_temp("e_int",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         return 1;
     }
      break;
     case "addcon":
     if( me->is_fighting() )
        return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");     
     if ( me->query("level") < 28 )
        return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");        
     if ( mysk < 50 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIG"�T�J�Z"NOR"�n�E\n");  
     if ( ob2->query("con") < 30 || ob2->query("level") < 28 ){
        tell_object(me,ob2->query("name")+"�����L�k�Ө��m"HIG"�T�J�Z"NOR"�n�E\n");
        return 1;
        }
     if ( ob2->query_temp("e_con") >= 1 ){
         tell_object(me,ob2->query("name")+"�w�g�����L�m"HIG"�T�J�Z"NOR"�n�F�E\n");
     } else {
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+ 
   "\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"+NOR
HIW"\n    �w�w�w�m"HIG" �T �J �Z "HIW"�n�w�w�w\n"+NOR               
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(120) ){
         ob2->add_temp("e_con",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         call_out("enhance",2,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         return 1;
     }
      break;
     case "adddex":
     if( me->is_fighting() )
        return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");     
     if ( me->query("level") < 29 )
        return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");        
     if ( mysk < 50 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIW"�h�ƳZ"NOR"�n�E\n");  
     if ( ob2->query("dex") < 30 || ob2->query("level") < 29 ){
        tell_object(me,ob2->query("name")+"�����L�k�Ө��m"HIW"�h�ƳZ"NOR"�n�E\n");
        return 1;
        }
     if ( ob2->query_temp("e_dex") >= 1 ){
         tell_object(me,ob2->query("name")+"�w�g�����L�m"HIW"�h�ƳZ"NOR"�n�F�E\n");
     } else {
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+
   "\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"+
HIW"\n    �w�w�w�m �h �� �Z �n�w�w�w\n"+NOR           
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(130) ){
         ob2->add_temp("e_dex",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         call_out("enhance",2,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         return 1;
     }
      break;
     case "addstr":
     if( me->is_fighting() )
        return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");     
     if ( me->query("level") < 30 )
        return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");        
     if ( mysk < 50 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIY"�Ӷ��Z"NOR"�n�E\n");  
     if ( ob2->query("str") < 30 || ob2->query("level") < 30 ){
        tell_object(me,ob2->query("name")+"�����L�k�Ө��m"HIY"�Ӷ��Z"NOR"�n�E\n");
        return 1;
        }
     if ( ob2->query_temp("e_str") >= 1 ){
         tell_object(me,ob2->query("name")+"�w�g�����L�m"HIY"�Ӷ��Z"NOR"�n�F�E\n");
     } else {
message_vision(
YEL"$N�f���u�ۯ��A���~�Ǹֺq\n"+ 
   "\n           �P�ɤ⤤�Ȱw�]�Ƭ��I�I�H�~��X�I\n"+
HIW"\n    �w�w�w�m"HIY" �� �� �Z"HIW" �n�w�w�w\n"+NOR                 
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(140) ){
         ob2->add_temp("e_str",1);
         me->improve_spell("moxibustion",random(myint/10));
         }
         call_out("enhance",2,me);
         me->receive_damage("mp",mysk*2-myint/5);
         me->receive_damage("ap",mysk*2-myint/5);
         me->start_busy(3);
         ob2->start_busy(1);
         return 1;
     }
      break;
     case "god":
     if( me->is_fighting() )
        return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");     
     if ( me->query("level") < 35 )
        return notify_fail("�A���g�礣������զ۴��L�H�w���E\n");
     if ( mysk < 65 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HBCYN+HIR"�������Z"NOR"�n�E\n"); message_vision(
   "$N�y�ɻ⮩���A���x�V���|�ʯ󪺨��ҡA�y�ɦ��p���A���{\n"+
   "   �@�@�C�C�H�ⴧ�X�A�����۵M�A�۩ۤѦ��C�C\n"+
HIW"\n    �w�w�w�m"HBCYN+HIR" �� �� �� �� �Z"NOR+HIW" �n�w�w�w\n"+NOR
+msg,me);

      me->start_busy(3-mysk/100-myint/100);
      me->receive_damage("mp",mysk*5);
if ( (mysk + myint + mylv/5 ) >= random(70) ){
        msg1 = HIW"\n�|�P����Ţ�n�A�L�ƥ��v�ͮ�b�������Ƭ��I�I���y�A���ۦb$N�|�P�I�I\n"NOR ;
        message_vision(msg1, ob2);
    if( ob2->query_condition("poison") > 1){
    ob2->apply_condition("poison", ob2->query_condition("poison")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n�A�Pı�@�}�D�n�A�ݨ��餺���r�ʭ��C���֡E\n"NOR);
    } else {
    ob2->apply_condition("poison", 0);
    }
    if( ob2->query_condition("blooding") > 1){
    ob2->apply_condition("blooding", ob2->query_condition("blooding")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n�A�Pı�A�ˤf�B����y�C�C�����F�E\n"NOR);
    } else {
    ob2->apply_condition("blooding", 0);
    }
    if( ob2->query_condition("whip_gas") > 1){
    ob2->apply_condition("whip_gas", ob2->query_condition("whip_gas")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n�A�Pı�餺��������l�Q����F�U�ӡE\n"NOR);
    } else {
    ob2->apply_condition("whip_gas", 0);
    }
    if( ob2->query_condition("six_open_force") > 1){
    ob2->apply_condition("six_open_force",             ob2->query_condition("six_open_force")-(mysk/10+myint/20) );
    tell_object(ob2,HIW"\n�A�Pı�餺����l�Q����F�U�ӡE\n"NOR);
    } else {
    ob2->apply_condition("six_open_force", 0);
    } 
    if( ob2->query_condition("five-thunder") > 1){
    ob2->apply_condition("five-thunder", ob2->query_condition("five-thunder")-(mysk/10+myint/20) );
    tell_object(ob2,"\n");
    } 
      ob2->receive_heal("hp",maxhp);
      me->improve_spell("moxibustion",random(myint/10));
    return 1;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
      break;
     case "ghost":
     if( me->is_fighting() )
        return notify_fail("�������A�����ɶ���"+ob2->query("name")+"�w�b�I\n");     
if ( me->query("level") < 40 )
        return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");        
     if ( mysk < 60 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HBWHT+BLK"�����@��Z"NOR"�n�E\n");
     if ( ob2->query("level") < 40 ){
        tell_object(me,ob2->query("name")+"�����L�k�Ө��m"HBWHT+BLK"�����@��Z"NOR"�n�E\n");
        return 1;
        }
if ( ob2->query_temp("d_a_up") >= 1 ){
         tell_object(me,ob2->query("name")+"�w�g�����L�m"HBWHT+BLK"�����@��Z"NOR"�n�F�E\n");
     } else {             
  
message_vision(
HIR"$N�N�y���ްw�b�z���Ҧ������ķ|�e�q�A\n"+
   "          �⤤���w���o�X�ʷʤ����������A�s���ϥX����\n"+
HIW"\n    �w�w�w�m"HBWHT+BLK" �� �� �@ �� �Z "NOR+HIW"�n�w�w�w\n"+NOR
+msg,me);
         if ( (random(mysk) + random(myint) + mylv/5 ) >= random(150) ){
         ob2->add_temp("d_a_up",1);
         me->improve_spell("moxibustion",random(myint/10));
         }     
      me->start_busy(3);
      me->receive_damage("ap",mysk*2-random(myint));
      me->receive_damage("hp",mysk*2-random(myint));
      me->receive_damage("mp",mysk*2);
      call_out("enhance",4,me);
     }  
     break;
    
      case "attack":

    attackon = random(sizeof(limbs));
       limb = limbs[attackon];
       mydex = me->query("dex");
       tdex  = ob2->query("dex");
       myint = me->query("int");
       tint  = ob2->query("int");
       mylv  = me->query("level");
       tlv   = ob2->query("level");         
       mysk  = me->query_spell("moxibustion");
      tdodge = ob2->query_skill("dodge");
       mytec = me->query_Merits("tec");
       mywit = me->query_Merits("wit");
       ttec  = ob2->query_Merits("tec");
      damage = (mywit+mytec)*15+random(myint)+random(mysk);

          if(!me->is_fighting()) 
               return notify_fail("�m"BLINK+HIR"���d���_�Z"NOR"�n�O�@�ؾ԰��ޥ��E\n");
          if ( ob2 == me )
               return notify_fail("�� suicide ���O�|�����:P�C\n");
        if(!me->can_fight(ob2)) return 0;

     if ( me->query("level") < 35 )
        return notify_fail("�A�����Ť����A�L�k�ϥX�m"BLINK+HIR"���d���_�Z"NOR"�n�E\n");        
     if ( mysk < 70 )
        return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"BLINK+HIR"���d���_�Z"NOR"�n�E\n");  

        if(!me->is_fighting(ob2)) me->kill_ob(ob2);
        if(!ob2->is_fighting(me)) ob2->kill_ob(me);
                
message_vision(
HIC"$N���X�a�͸U�����˽��j���Ѧa�`���u�z�A����d�Y\n"+
   "\n    ��M�@�}�g�r���H���$N�⤤���w�W«�X�A�V$n�Q�G�R�����t�ӥh�I�I�I\n"+
   "\n                          "HIY"������\n"+
   "                   "HIG"������        "MAG"���c��\n"+
   "           "HIB"�褤��                       "HIC"�Үc��\n"+
   "    "HIW"�ܶ���         �m"BLINK+HIR" �� �d �� �_ �Z"NOR+HIW" �n        "HIW+BLK"�N�W��\n"+     
   "           "HIB"�ʷ|��                       "HIC"������\n"+
   "                   "HIG"������        "MAG"�Ѭ��\n"+
   "                          "HIY"���u��\n"+
HIC"\n        �w�w�w��"HIR"�Ѫk����a�͡A�����ѤU�L�Ư�"HIC"���w�w�w\n"NOR,me,ob2);

          if ( random( mysk*5 + mylv - tlv*2 - tdex - tdodge/2 + myint + mydex ) >= 30 ){
message_vision(HIB"\n�Q�G�D�H�������I�J$N�Q�G�n���I�I"+
               HIW"\n$N�Q�o�s�����w�N�����O�L�O�۬[�A�餺��l�z���Ө���۷��Y�������ˡI�I"NOR,ob2);
                   ob2->receive_damage("ap",damage);
                   ob2->receive_damage("hp",damage);
                   ob2->receive_damage("mp",damage);
                   ob2->start_busy(mysk/50);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
        if(ob2->query_temp("apply/show_damage") || ob2->query_temp("show_damage") )
                tell_object(ob2,HIR"("+damage+")"NOR+" ("+ob2->query("hp")+"/"+ob2->query("max_hp")+")");
        message_vision("\n", me);
        COMBAT_D->report_status(ob2);

if(limb == "�Y��") ob2->receive_wound("head"     ,random(mysk/20)+mytec/5+mylv/10);
if(limb == "�}��") ob2->receive_wound("left_leg" ,random(mysk/20)+mytec/5+mylv/10);
                   ob2->receive_wound("right_leg",random(mysk/20)+mytec/5+mylv/10);
if(limb == "����") ob2->receive_wound("body"     ,random(mysk/20)+mytec/5+mylv/10);
if(limb == "�ⳡ") ob2->receive_wound("left_arm" ,random(mysk/20)+mytec/5+mylv/10);
                   ob2->receive_wound("right_arm",random(mysk/20)+mytec/5+mylv/10);
          } else {
            message_vision(HIR"\n$N���F���{�L�H��A���٬O����p�p���i�ΡI"NOR,ob2,me); 
            ob2->receive_damage("hp",mysk);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+mysk+")"NOR);
        if(ob2->query_temp("apply/show_damage") || ob2->query_temp("show_damage") )
                tell_object(ob2,HIR"("+mysk+")"NOR+" ("+ob2->query("hp")+"/"+ob2->query("max_hp")+")");
        message_vision("\n", me);
        COMBAT_D->report_status(ob2);
           }    
                me->start_busy(4-mysk/50-myint/50); //�I�k�ʧ@�ɶ�
                me->receive_damage("ap",myint+ mysk*2- mytec*10); 
                me->receive_damage("mp",myint+ mysk*2- mywit*10); 
                me->improve_spell("moxibustion",random(myint/10));
      break;
        }
 return 1;
} 

void enhance()
{
    object me;
    string msg1;
    int mysk,mylv,myint,add;
    me = this_player();
    mysk = me->query_spell("moxibustion");
    myint = me->query("int");
    mylv = me->query("level");
    add = mysk/5+mylv/5;
     
if( ob2->query_temp("e_str") == 1 ){
    msg1 = HIY "$N�����v�]�H�ۺ����ܱo���j�j���A�٦תȵ��ʾw����I�I�I\n" NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("addstr",add);
    ob2->apply_condition("addstr",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/str",add);
    ob2->add_temp("e_str",1);
    return;
} else if ( ob2->query_temp("e_con") == 1 ){
    msg1 = HIY "$N�����v�]�H�ۺ����ܱo���j�j���A�٦תȵ��ʾw����I�I�I\n" NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("addcon",add);
    ob2->apply_condition("addcon",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/con",add);
    ob2->add_temp("e_con",1);
    return;
} else if ( ob2->query_temp("e_dex") == 1 ){
    msg1 = HIC"�@�D���m�F���b�n�b$N�Y��,$N�_�����Y,������G���ۤ���m��,���p���A�A�@�E\n"NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("adddex",add);
    ob2->apply_condition("adddex",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/dex",add);
    ob2->add_temp("e_dex",1);
    return;
} else if ( ob2->query_temp("e_int") == 1 ){
    msg1 = HIC"�@�D���m�F���b�n�b$N�Y��,$N�_�����Y,������G���ۤ���m��,���p���A�A�@�E\n"NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("addint",add);
    ob2->apply_condition("addint",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/int",add);
    ob2->add_temp("e_int",1);
    return;
} else if ( ob2->query_temp("d_a_up") == 1 ){
    msg1 = HIY "$N�����v�]�H�ۺ����ܱo���j�j���A�٦תȵ��ʾw����I�I�I\n" NOR ;
    message_vision(msg1, ob2); 
    ob2->set_temp("ghost",add);
    ob2->apply_condition("ghost",(mysk+myint)/10+mylv);
    ob2->add_temp("apply/damage",add);
    ob2->add_temp("apply/armor",add);
    ob2->add_temp("d_a_up",1);
    return;
} else {
    ob2->receive_damage("mp",random(mysk));
    ob2->receive_damage("ap",random(mysk));
    if ( ob2 == me ){
    message_vision(HIB"\n$N�@�Ӥ��ߡA�w�����F�ަ�A$N�h�o�s�U�y�ӡE\n"NOR,me);
    } else { 
    msg1 = HIB"\n$N�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR ;
    message_vision(msg1, me, ob2);
    }
}
   return;
}

int do_help(string str)
{
if(!str || str != "needle") return 0; 
if( this_player()->query("level") > 25 ){
write(@HELP
        ���ްw�b�ϥΤ�k:       acupuncture <�\��> on <�Y�H>
        
        �D�԰��\��G
             �m����Z�nrekee       ���Ӥ��l�I��(AP)�Ӧ^�ХͩR�I��(HP)
             �m����Z�nregin       �����]�k�I��(MP)�Ӧ^�Ф��l�I��(AP)
             �m�����Z�nresen       ���Ӥ��l�I��(AP)�Ӧ^���]�k�I��(MP)
             �m���@�Z�nadvkee      ���Ӥ��l�I��(AP)�Ӧ^�Фj�q�ͩR�I��(HP)
             �m�}�ѳZ�nsky         �����]�k�I��(MP)�Ӧ^�Ф��l�I��(AP),�ͩR�I��(HP)
             �m¡���Z�nheal        �����]�k�I��(MP)�Ӫv¡���˳B 
             �m���߳Z�naddint      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�ϴ��z(INT)����  
             �m�T�J�Z�naddcon      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�����(CON)���� 
             �m�h�ƳZ�nadddex      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�ϱӱ�(DEX)���� 
             �m�Ӷ��Z�naddstr      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�ϤO�q(STR)���� 
             �m�������Z�ngod     ���Ӥj�q�]�k�I��(MP)�A������¡�ô�C���}���A 
             �m�����@��Z�nghost   ���Ӥ��l�I��(AP)�A�]�k�I��(MP)�A�ͩR�I��(HP)
                                   �Ϫ��z�����O�M���z���m�O���� 
       �԰��\��G
             �m���d���_�Z�nattack  ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)��ĤH���n�޵o�X
                                   �P�R���@��
HELP);
} else {
write(@HELP
        ���ްw�b�ϥΤ�k:       acupuncture <�\��> on <�Y�H>
        
        �D�԰��\��G
             �m����Z�nrekee       ���Ӥ��l�I��(AP)�Ӧ^�ХͩR�I��(HP)
             �m����Z�nregin       �����]�k�I��(MP)�Ӧ^�Ф��l�I��(AP)
             �m�����Z�nresen       ���Ӥ��l�I��(AP)�Ӧ^���]�k�I��(MP)
             �m���@�Z�nadvkee      ���Ӥ��l�I��(AP)�Ӧ^�Фj�q�ͩR�I��(HP)
             �m�}�ѳZ�nsky         �����]�k�I��(MP)�Ӧ^�Ф��l�I��(AP),�ͩR�I��(HP)
             �m¡���Z�nheal        �����]�k�I��(MP)�Ӫv¡���˳B 
HELP);
} 
return 1;
}

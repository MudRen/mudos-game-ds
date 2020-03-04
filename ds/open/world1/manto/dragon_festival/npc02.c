/* 
edit by whoami 2006�ݤȯS�O���� 
�]��l��npc, ������player�ۦ榬��, 
��player�ݦۦ���զ�ح�����]�X�Y�غ�l,
������������h���ɭ�, ���i��|�]�X���Ѫ���l. 
*/ 


#include <ansi2.h>
inherit NPC;

void start(int money, object who);
void zong_zi_check(int zong_zi, object who);
void give_zong_zi(int zong_zi_no, object who);

string *item=({
"a","glutinous rice","zong string","seasoning","peanut","green beans","red beans","bamboo leaf",
"mushroom","chestnut","walnut","hen's egg","duck's egg","dried shrimp","wax","radish","li rong",
"puree","fish meat","beef","pork","san bao rice","fen ye","lian rong","orange peel","green plum",
"hua jiao",
});

void create() 
{ 

 set_name("�]��C",({"bao zong po","bao","po"}));
 set("age",60);
 set("gender","�k��");
 set("level",50);
 set("title",WHT"�]���C���C"NOR);
 set("no_fight",1);
 set("chat_chance",10);
 set("chat_msg", ({
                   (:command("say �C����o�ɭԯu�O�����ѱC�l�ڤF..."):),
                   (:command("pace"):), 
 }));
 setup();
}

void relay_say(object me, string str)
{
  object ob = this_object(),item;
  int zong_zi;
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�x���պ�") != -1 || strsrch(str,"���n�J��") != -1 ||
     strsrch(str,"���֤��׺�") != -1 || strsrch(str,"�|�t���Q����") != -1 ||
     strsrch(str,"�ʪG��l") != -1 || strsrch(str,"����������") != -1 ||
     strsrch(str,"���d����") != -1 || strsrch(str,"�s�FĪ�º�") != -1 )
  if( !ob -> query_temp("money_received") ){
      command("say �a�M!�A�S������!"); 
      return;
      }
  if(strsrch(str,"�x���պ�") != -1) zong_zi = 1; //command("say �x���պ�");
  if(strsrch(str,"���n�J��") != -1) zong_zi = 2; //command("say ���n�J��");
  if(strsrch(str,"���֤��׺�") != -1) zong_zi = 3; //command("say ���֤��׺�");
  if(strsrch(str,"�|�t���Q����") != -1) zong_zi = 4; //command("say �|�t���Q����");
  if(strsrch(str,"�ʪG��l") != -1) zong_zi = 5; //command("say �ʪG��l");
  if(strsrch(str,"����������") != -1) zong_zi = 6; //command("say ����������");
  if(strsrch(str,"���d����") != -1) zong_zi = 7; //command("say ���d����");
  if(strsrch(str,"�s�FĪ�º�") != -1) zong_zi = 8; //command("say �s�FĪ�º�");
  if( zong_zi > 0 )
  call_out("zong_zi_check",0,zong_zi,this_player());         

  return;
}

int accept_object(object who, object ob)
{
//    string *item;
    object obj;
    int money,x=0;
    obj=this_object();

       if( ob->value() ){
//           if( ob->query_temp("money_received") ) 
           message_vision("$N��$n�F�@"+ob->query("unit")+ob->name()+"�C\n",who,obj);       
           message_vision("�}�l�P~~\n",who,obj); //testing =.= 
           obj -> set_temp("money_received",1);
           destruct(ob);
           money = ob->value();
           start(money,who);
           return 1;
       }
                       
       for(x;x<27;x++){                
       if( ob->query("id") != item[x] ) continue;
         if( ob->query("id") != item[x] ){
         command("say �o�ӪF��ڤ��n");
         return 0;             
         } else {
         this_object()->add_temp("temp_item/"+item[x],1);
         message_vision("$N��$n�F�@"+ob->query("unit")+ob->name()+"�C\n",who,obj);
         destruct(ob);
         return 1;                
         }       
       }

//    start(money,who);
}         

void start(int money, object who)
{             
     object ob=this_object();

     switch ( money ){
            case 0..1000: // ����򭹧����]�F! 
                 ob->set_temp("temp_item/fail",1);
                 break;               
            case 1001..5000: // 80%���vfail!
                 if (random(100) < 80) ob->set_temp("temp_item/fail",1);     
                 break;
            case 5001..10000: // 60%     
                 if (random(100) < 60) ob->set_temp("temp_item/fail",1);     
                 break;         
            case 10001..20000: // 40%     
                 if (random(100) < 40) ob->set_temp("temp_item/fail",1);     
                 break;                     
            case 20001..40000: // 20%     
                 if (random(100) < 20) ob->set_temp("temp_item/fail",1);     
                 break;    
            case 40001..170000: // 1%     
                 if (random(100) <  1) ob->set_temp("temp_item/fail",1);     
                 break;    
            case 170001..250000: // 0%     
                 break;                     
            default: //Special Gift XD
                 ob->set_temp("temp_item/special",1);
                 break;
                 }
//     zong_zi_check(zong_zi,who);
     return;
}     

void zong_zi_check(int zong_zi, object who)
{
     object ob=this_object();
     int zong_zi_no = 0;
     if( ob->query_temp("temp_item/fail") )
          call_out("give_zong_zi",0,zong_zi_no,who);         

     switch ( zong_zi ){
//hp+500 �x���պ� 
//1,2,3,7,8,11,20            
            case 1:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) ||
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[7]) ||
                  !ob->query_temp("temp_item/"+item[8]) || !ob->query_temp("temp_item/"+item[11]) ||
                  !ob->query_temp("temp_item/"+item[20]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 1;
//                        give_zong_zi(zong_zi_no);                                                          
                        } 
                        
                        break;
                        
//ap+400 ���n�J��
//1,2,3,7,4,5,12
            case 2:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[7]) ||
                  !ob->query_temp("temp_item/"+item[4]) || !ob->query_temp("temp_item/"+item[12]) ||
                  !ob->query_temp("temp_item/"+item[5]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 2;
//                        give_zong_zi(zong_zi_no);                                                          
                        } 
                        break;
//str+5 ���֤��׺�
//1,2,3,5,7,20,24
            case 3:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[7]) ||
                  !ob->query_temp("temp_item/"+item[20]) || !ob->query_temp("temp_item/"+item[5]) ||
                  !ob->query_temp("temp_item/"+item[24]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 3;
//                        give_zong_zi(zong_zi_no);                                                          
                        } 
                        break;
//con+5 �|�t���Q����  
//1,2,3,6,7,20,26
            case 4:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[7]) ||
                  !ob->query_temp("temp_item/"+item[20]) || !ob->query_temp("temp_item/"+item[6]) ||
                  !ob->query_temp("temp_item/"+item[26]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 4;
                        } 
                        break;
//dex+5 �ʪG��l 
//1,2,3,7,10,14,25
            case 5:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[7]) ||
                  !ob->query_temp("temp_item/"+item[10]) || !ob->query_temp("temp_item/"+item[25]) ||
                  !ob->query_temp("temp_item/"+item[14]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 5;
                 } 
                        break;
//int+5 ����������   
//1,2,3,7,8,13,15,18,21
            case 6:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[7]) ||
                  !ob->query_temp("temp_item/"+item[8]) || !ob->query_temp("temp_item/"+item[13]) ||
                  !ob->query_temp("temp_item/"+item[28]) || !ob->query_temp("temp_item/"+item[21]) ||                  
                  !ob->query_temp("temp_item/"+item[15]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 6;
                 } 
                        break;
//random(Sou,Tec,Wit)+1, con,int+random(3) ���d���� 
//1,2,3,4,7,8,9,10,15,21,22
            case 7:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[4]) ||
                  !ob->query_temp("temp_item/"+item[7]) || !ob->query_temp("temp_item/"+item[8]) ||
                  !ob->query_temp("temp_item/"+item[9]) || !ob->query_temp("temp_item/"+item[10]) ||
                  !ob->query_temp("temp_item/"+item[21]) || !ob->query_temp("temp_item/"+item[22]) ||
                  !ob->query_temp("temp_item/"+item[15]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 7;
                 } 
                        break;
//random(Bar,Bio,Sou)+1, str,dex+random(3) �s�FĪ�º�
//1,2,3,6,7,16,17,21,23
            case 8:
              if( !ob->query_temp("temp_item/"+item[1]) || !ob->query_temp("temp_item/"+item[2]) || 
                  !ob->query_temp("temp_item/"+item[3]) || !ob->query_temp("temp_item/"+item[6]) ||
                  !ob->query_temp("temp_item/"+item[7]) || !ob->query_temp("temp_item/"+item[16]) ||
                  !ob->query_temp("temp_item/"+item[23]) || !ob->query_temp("temp_item/"+item[17]) ||
                  !ob->query_temp("temp_item/"+item[21]) ) {
                 ob->set_temp("temp_item/fail",1);
                 } else {
                        zong_zi_no = 8;
                 } 
                        break;     
            default:
                    break;                        
            }                        
          call_out("give_zong_zi",0,zong_zi_no,who);                           
          return;
}          

void give_zong_zi(int zong_zi_no, object who)
{
     object item;
     if( this_object()->query_temp("temp_item/special") )
         zong_zi_no = 9;
     switch( zong_zi_no ){
             case 1: item = new(__DIR__"obj/zong01"); break; 
             case 2: item = new(__DIR__"obj/zong02"); break; 
             case 3: item = new(__DIR__"obj/zong03"); break; 
             case 4: item = new(__DIR__"obj/zong04"); break;                           
             case 5: item = new(__DIR__"obj/zong05"); break; 
             case 6: item = new(__DIR__"obj/zong06"); break; 
             case 7: item = new(__DIR__"obj/zong07"); break; 
             case 8: item = new(__DIR__"obj/zong08"); break;            
             case 9: item = new(__DIR__"obj/zong_special"); break;                
             default: item = new(__DIR__"obj/zong_fail"); break;     
             }
     message_vision("$N���X"+item->name()+"��$n\n",this_object(),who); 
     item->move(who);
     this_object()->delete_temp("temp_item");
     this_object()->delete_temp("money_received");
     return;
}     

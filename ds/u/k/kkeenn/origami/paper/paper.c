/*   �F�P����  ���e -�P�ȾԤh- �i��ޢպ��e�����j�P��v�ҵe*
 *   �Ҽ{�@�����Ӫ�Class , ��S�⬰����, ����d��@�Ө��⪺*
 *   ����, �p�G�i�H, �N�⥦�s�����Ӥu�|���@�C              *
 *   �����@�}�l���H���P��, ��i�H�馨�����F�P�Ȧp: �s��..��*
 *                            editor by kkeenn@ds 2002/6/1 */
#include <ansi.h>
inherit ITEM; 
void create()
{
  set_name("�L��P��", ({ "none paper", "paper" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");
    set("long", " 
    �o�O�@�i�w�Q�|���Q�馨����F�誺�ƨ��P�ȡC
"HIG"�P�ȡGorigami xxx"NOR"
"HIW"�ثe��骺���F���G
"HIC"1.�s��(dragon)  2.���(flower)  3.�b��(bird)
"HIC"4.�T��(wolf)    5.�߱�(rabbit)  6.����(fish)
"NOR);
    set("value",0);
    set("no_drop",1);
    set("no_sell",1);
    set("no_get",1);
    set("no_sac",1);
    set("no_give",1);
  }
   setup();
}
int query_autoload() { return 1; }
void init()
{ 
    add_action("do_origami","origami");
}
int do_origami(string arg) 
{
  object obj,me; 
  int limit;
  string race,word,file,gift;
  obj = this_object(); 
   me = this_player(); 
  file = __DIR__"paper2.c"; 
 if(!arg) return notify_fail("�A�쩳�Q�N���馨ԣ�F�裫�H\n"); 
   if(me->query("family")) return notify_fail("�A�w�g�����F�ƨ��F�C\n"); 
switch(arg)
{ 
case "dragon":
  limit = 60;
  gift = "fire";
  race = "�s��";
  word = "�s";
  break;
case "flower":
  limit = 15;
  gift = "wood";
  race = "���";
  word = "�P";   //������D�w�g ��A�D�@�����P�l�]
  break;
case "bird":  //��...�t�X�U�����r���Ӷ��[
  limit = 10;
  gift = "wind";
  race = "�b��";
  word = "�b";
  break;
case "wolf":
  limit = 24;
  gift = "electric";
  race = "�T��";
  word = "�T";
  break;
case "rabbit":
  limit = 30;
  gift = "earth";
  race = "�߱�";
  word = "��";
  break;
case "fish":
  limit = 41;
  gift = "water";
  race = "����";
  word = "��";
  break;
default:
return notify_fail("���F�ɨS���o�����F�C\n");
break;
}
if(me->query_skill("origami") < limit ) 
         return notify_fail("�A���P�ȧޥ������P�X" + word +"�Y�P�ȡI\n"); 
      switch(random(10) + 1) 
     {
    case 1 : me->set("family/name","�g"+ word);
             break;
    case 2 : me->set("family/name","��"+ word);
             break;
    case 3 : me->set("family/name","�]"+ word);
             break;
    case 4 : me->set("family/name","�t"+ word);
             break;
    case 5 : me->set("family/name","��"+ word);
             break;
    case 6 : me->set("family/name","�t"+ word);
             break;
    case 7 : me->set("family/name","�a"+ word);
             break;
    case 8 : me->set("family/name","��"+ word);
             break;
    case 9 : me->set("family/name","�R"+ word);
             break;
   case 10 : me->set("family/name","��"+ word);
             break;
     }  
  me->set("family/race",race);
  me->set("family/gift",gift);   //�M�w�ϥΪk�N���ݩ�
  me->set("family/id",arg);
       switch(me->query("level")/5) 
{
   case 1 :
 me->set("family/level",1);
 me->set("family/color","����");
             break;
   case 2 :
 me->set("family/level",2);
 me->set("family/color","�Q��");
   break;

   case 3 :
 me->set("family/level",3);
 me->set("family/color","�Ŧ�");
   break;
   case 4 :
 me->set("family/level",4);
 me->set("family/color","���");
   break;
   case 5 :
 me->set("family/level",5);
 me->set("family/color","����");
   break;
   case 6 :
 me->set("family/level",6);
 me->set("family/color","���");
   break;
   case 7 :
 me->set("family/level",7);
 me->set("family/color","����");
   break;
   case 8 :
 me->set("family/level",8);
 me->set("family/color","�զ�");
   break;
   case 9 :
 me->set("family/level",9);
 me->set("family/color","�¦�");
   break;
   case 10 :
 me->set("family/level",10);
 me->set("family/color","�Ǧ�");
   break;
}
message_vision(HIW"$N�B�ΰ��W���ޥ��N�@�i�L��P�ȧ馨�F�@��"+ word +"�Y�P�ȡI\n" NOR,me);new(file)->move(me);
destruct(obj);
return 1;
}


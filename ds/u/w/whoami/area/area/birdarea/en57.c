#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"�F�_"NOR"�A�L"NOR"��"YEL"�d�h��"NOR);
 set("long",@LONG
�A��J�d�h�Ϫ��P�ɧA�Pı���ʤQ�����K, ���G�ֳQ�d�h
�ҧ]��, �|�B���o�ۨ�󪺯��, ���H�D�`�Q�R. �A�o�{�|�B��
�@�Ǳq�����L�����ΩM�Ӫ�, ���T�g�Ĥj�۵M������.
LONG);
 set("exits",(["west":__DIR__"en56",
               "east":__DIR__"en58",
               "south":__DIR__"en62",
               "northeast":__DIR__"en54",
               "northwest":__DIR__"en52",
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 set("can_summon",1);
 setup();
}        

void init()
{
        object ob;
        object me=this_player();
        if( objectp(ob=present("summon seal",me))) 
        tell_object(me,HIW"�A���W���l��Ŧ��G�惡�a�������E�E�E\n"NOR);
        add_action("do_summon","summon");
}

int do_summon()
{
 object ob = this_object();
 object me = this_player();
 object ob1,ob2;
 if( objectp(ob1=present("summon seal",me)) ){

  if( objectp(ob2=present("corpse",environment(me))) )
  {
   message_vision("$N�N���~�\\�b�@�ǡA�f�����ۻy�a��۩G��E�E�E\n",me);
   destruct(ob1);
   ob->set_temp("summoning",1);
   me->start_busy(5);
   call_out("gosummon",1,ob);
   } else {
   tell_object(me,"�b�l��e���ӥ��ǳ��I���~�a�H\n");
   }
   
 } else {
 tell_object(me,"�A���W�S�S���l��šE�E�E\n" NOR);
        }
}

void gosummon()
{
 object ob=this_object();
 object me=this_player(); 
 object ob1= present("corpse",environment(me));
 object mob,mob1;
 int i = ob->query_temp("summoning");
   switch( i ) {
     case 1:
      message_vision(HIR"\n\n���M���b$N���䲽�~�����F�E�E�E\n",me);  
      destruct(ob1); 
      ob->add_temp("summoning",i+1);
      call_out("gosummon",1,ob);
      break;
     case 2:
      message_vision(HIW"\n\n�@�}�}�C�q�n�q$N���䪺�h�A���ǥX�E�E�E\n",me);  
      ob->add_temp("summoning",i+1);
      call_out("gosummon",1,ob);
      break;
     case 3:
      if ( ob->query("can_summon") >= 1 ) {
      mob=new(__DIR__"npc/dark_crocodile.c");
      mob->move(environment(me));
      message("world:world1:vision", HIY+BLK"\n\t�F�_�誺�˪L���ǨӤ@�}�C�n����q���\n\n"NOR,users());
      message_vision(HIW+BLK"��M���@��"+mob->query("name")+HIW+BLK"�q$N����«�F�X�ӡI�I\n",me);
      call_out("summonagain",900,ob);
      ob->delete("can_summon");
      ob->delete_temp("summoning");
      } else {
      mob1=new(__DIR__"npc/h_crocodile.c");
      mob1->move(environment(me));
      message_vision(HIC"\n��M���@��"+mob1->query("name")+HIC"�q$N������F�X�ӡI�I\n"NOR,me);      
      ob->delete("can_summon");
      ob->delete_temp("summoning");
      } 
          break;
     }
}            

void summonagain()
{ 
 object ob = this_object();
 ob->set("can_summon",1);
}


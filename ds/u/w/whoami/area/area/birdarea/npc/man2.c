#include <ansi.h>
#include <dbase.h>
inherit F_VENDOR;
inherit NPC;
string *file=({"scroll","scroll1","box"});
void create()
{
 set_name("���_",({"chen biaw","chen","biaw"}));
 set("long","�L�O�y�����������A���M�L���y�W�w�g�G�����몺����F�A���O\n"
            "�L���ժZ���O�����ߡA�o�@�I���S�����O�ѤH���ˤl�C�L�ݨӦ�\n"
            "�G���I�дo�E\n");
 set("age",60);
 set("gender","�k��");
 set("level",20);
 set("title",HIR"�y����"NOR"����");
 set_skill("parry",50);
 set_skill("unarmed",50);
 set_skill("dodge",50);
 set("no_fight",1);
 set("chat_chance",10);
 set("chat_msg", ({ YEL"���_�C�n���ۨ��ۻy:����...�쩳�ӫ���....\n"NOR,
                   (:command("sigh"):),
 }));
 set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
 set("reborn",3600);
 setup();
} 

void init()
{ 
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
  add_action("do_no_ask","ask"); 
  add_action("do_list","list");
  add_action("do_change","exchange");
}

void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query("quest/ko_fox") >= 200  ){
    command("tsk "+me->query("id"));
    command("say �o��"+RANK_D->query_respect(ob)+"�u�O��²��A�~�M���U����h���W���Y�E");   
    command("say �o�˧a�A�ڥi�H���I�F��Ӹ�A���A��U���Y�E");
    command("say �Х�list�d�߷Q�������F��I"); 
    } else {
    command("hi "+ me->query("id") );   
    command("say �o��"+RANK_D->query_respect(ob)+"�ӧڭ̧��̦�����ƶܡH");
    }
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

void relay_say(object me, string str)
{
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�дo") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1 ){
    command("say �ڨS����дo��.."); 
    command("hoho");  
    } else {
    command("say �ЧA���ڧ�^�Ѫ��֡A���O�ڪ��Ǯa�_�A�аȥ��n��^�ӡC");
    command("thank "+ this_player()->query("id"));
    }
  }   
  if(strsrch(str,"�Ѫ���") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1 ){
    command("say ���O�ڪ��Ǯa�_��..�H"); 
    command("say �ڥi�O���|���A�ݪ�");
    command("giggle "+ this_player()->query("id")); 
    } else {
    command("say ���@���j���X�ڤ��`�N�ɡA��Ѫ��ֵ��p���F�I�I");
    command("say �e�n���O���F�_�A�L�w�d�h�Ϫ���V���h�C");
    }
  }
  if(strsrch(str,"�y����") != -1)
  { 
    command("hoho");
    command("say �o�N�O�ڭ̪������A��������D�ܡH");
  } 
  return;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "tengu fur")
        {
           command("flop "+who->query("id"));
           command("say �o���O�ڭn���F���..");
          return notify_fail("");
} 
if( query_temp("can_not_give") ){
           command("?");
           command("say ���ڳo��ԣ�H");
           return notify_fail("");
}        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
           if( present("godwind bag", who) )
           {
             command("?");
             return 0;
           }

             message_vision("$N���F$n�@"+ob->query("unit")+ob->query("name")+"�C\n",who,obj);
             command("think"); 
             obj->set_temp("can_not_give",1);  
             obj->set_temp("givebag",1);
             destruct(ob); 
             call_out("rb",1500);
             call_out("givebag",1,who);
return 1;
        }
}
void givebag()
{
      int i;
      object me,obj,wind;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givebag");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"���_�J���@�F�@�o�i�֡C\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 2:
            command("say �Ӧn�F�A�N�O�o�i�֡C");
            obj->set_temp("givebag",i+1);
            call_out("givebag",2,me);
            break;
          case 3:
            say(HIY"���_�ˤF�˳o�i�֨åB��:�ڦ��ӪF��n�e�A�A�A�����C\n"NOR);
            command("dance");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 4:
            say(HIY"���_�b���Ǫ��c�l���F½��䪺�A�����D�L�b�䤰��F��C\n"NOR);
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 5:
            command("say �o�O�ڿ˦۰����U�l�A�K�e���A��@�S�ҧa�C");
            obj->set_temp("givebag",i+1);
            call_out("givebag",3,me);
            break;
          case 6:
            wind=new(__DIR__"obj/bag");
            wind->move(obj);
            command("give bag to "+ me->query("id") );
            obj->delete_temp("givebag"); 
            obj->set("long","�L�O�y�����������A���M�L���y�W�w�g�G�����몺����F�A���O\n"
                            "�L���ժZ���O�����ߡA�o�@�I���S�����O�ѤH���ˤl�C\n");
            obj->set("chat_msg", ({ (:command("say �̫��٬O���F.."):),
                                    (:command("sweat"):),
                                  }));
          break;
          }
}

string item_desc(object ob)
{
        if(ob->query("skill_type")) return HIG+"�Z��"+NOR;
        else if(ob->query("armor_type")) return HIY+"����"+NOR;
        else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"�^�_"+NOR;
        else return "�D��";
}
int do_list(string arg)
{
  string dir,list;
  object awardeq;
  int i,a,awardcost;
  dir = "/open/world1/whoami/birdarea/npc/change/";
  i = sizeof(file);
  list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
  list +="�x �һݪ��W�Y        ����   �ثe�i�H�I�������~          �x\n";   
  list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
  for(a=0;a<i;a++) {
    if(load_object(dir+file[a])) {
      awardeq = load_object(dir+file[a]);
      awardcost = awardeq->query("needaward");
list += sprintf("%6d ------------- %4s  %-30s",awardcost,item_desc(awardeq),awardeq->short()); }
    else break; 
    list += "\n";
  } 
    list += "\n\t�A�ثe�� "+this_player()->query("quest/ko_fox")+" �����W�Y�E\n";    list += "\t�Х�exchange <���~���W>�ӥ洫�Q�����F��E\n";
    list += "\t���~����W�[���E\n"; 
    list += "\n";
  this_player()->start_more(list);
  return 1;
}
int do_change(string arg)
{
  int a,b,c,awardcost,i,j=1;
  object awardeq,me,ob;
  string name,dir;
  dir = "/open/world1/whoami/birdarea/npc/change/";
  me=this_player();
  if(!arg) return notify_fail("�A�n�I������F��H\n");
  name = arg;
  i = sizeof(file);
  for(a=0;a<i;a++) {
    awardeq = load_object(dir+file[a]);
    if(awardeq->query("id") == name) { 
      j=0; break; }
  }
  if(j!=0)
  return notify_fail("���_���D�G ���H�ä��I���o�تF��(�Ъ`�N�z�O�_���i�D�ڸӪ��~�����W).\n");
  else {
  awardcost = awardeq->query("needaward");
  if( me->query("quest/ko_fox") < awardcost )
    return notify_fail("���_���D�G ��p�I�z��U�����W�Y�����I���o�ӪF��I\n");
  if( awardeq->query_weight() + me->query_encumbrance() > me->query_max_encumbrance() )
    return notify_fail("���_���D�G �z�����ʳo�F��F�a�H \n");
  if( awardeq->query("volume") + me->query_capacity() > me->query_max_capacity() )
    return notify_fail("���_���D�G �z���W�񤣤U�o�F���o! \n");
  me->add("quest/ko_fox", -awardcost);
  message_vision("$N�� "+awardcost+" �����W�Y���o�F�G "+awardeq->query("name")+" �I\n",me);
  ob = new(dir+file[a]);
  if(ob->is_character()) ob->move(environment(me));
  else ob->move(me);
  me->save();
  return 1;
  }
}
int rb()
{ 
    delete_temp("can_not_give");
    set("long","�L�O�y�����������A���M�L���y�W�w�g�G�����몺����F�A���O\n"
               "�L���ժZ���O�����ߡA�o�@�I���S�����O�ѤH���ˤl�C�L�ݨӦ�\n"
               "�G���I�дo�E\n");
    set("chat_msg", ({ YEL"���_�C�n���ۨ��ۻy:����...�쩳�ӫ���....\n"NOR,
                     (:command("sigh"):),
                     }));
    message_vision(YEL"$N�y�F���n�C\n"NOR,this_object());
    return 1;
}


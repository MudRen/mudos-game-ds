// Room: /u/l/luky/workroom.c
#include <ansi.h>  //�Y�n�Φ��C�⪺���[����
#include <room.h> //�n�[���n�o�@��
#include <path.h>
inherit ROOM;
inherit DOOR;
void entercheck(object ob);
void create()
{
 set("short",HIG"��������"NOR);  //�u�ԭz
 set("long","\n"
 HIB"�o"NOR"                      �o�̬O�����l�����̲`�B�E�E�E�E�E�E�E�E�E�E\n"
 HIB"�p"HIW"  o"NOR"�X             �X���D�`�u�����`�����q�A�����L�A�@��"HIY"������"NOR"��\n"
 HIB"�p"NOR"      �X          "HIY"�p�s��"NOR"��M�b�A�����S�X�F�e���Y�A�٦R�X�@������\n"
 BLU"�o"NOR"  �X    "HIG"�i �p"NOR"     �p��w�A�A�`�N��e���䪺�����W�٨�F�X�Ӥj�r�C\n"
 BLU"�n"HIY"��"NOR"�X"HIB"  ���i�h�i�i��"HIW"�X"NOR+GRN"�i      "NOR"�X"HIG"    �p"NOR"\n"
 BLU"�o"HIY"�H��"HIB"���i"HIC"�Ф�����"HIB"�i"BLU"�h�g"HIB"�f�e�e�f�e�e�f�e�e�f�e�d�c�b"NOR"\n"
 BLU"�i"HIB"�i�h�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�h�g�f�e"BLU"�d�c�b"NOR"\n"
 ); //���ԭz

 set("light",1);
 set("exits", ([  //���ж��s�����X�f��V���ɮ�
 "east": __DIR__"lukyroom1",
 "west": __DIR__"lukylab1",
 "fonsan": LUKY+"fonsan/eega1",
 "wiz": "/d/wiz/hall1",
 ]));
 set("hide_exits", ([
 "ship":__DIR__"workroom",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 set("objects",([
  __DIR__"npc/passenger":1,
  __DIR__"npc/pig":1,
  __DIR__"box":1,
  __DIR__"redkey":1,
 ]));
 create_door("east","����j��","west",DOOR_LOCKED,"redkey");
// set("never_clean",1); //�@��ж������i�[����.
 setup();
// call_other( "/obj/board/luky_b", "???" );
}

void init()
{
 call_out("leave_message",3,this_player());
 call_out("entercheck",2,this_player());
}

void entercheck(object ob)
{
 if(userp(ob))
 {
   if(wiz_level(ob) < wiz_level("(immortal)"))
   {
     message_vision(HIR"�藍�_ "+ob->name()+" �A����i�ӳ�!!\n"NOR, ob);
     ob->move("/d/slake/start");
   } else 
   {
     message_vision(HIY"\n �p�s����: ��!! "+ob->name()+"�j�j! �ڦn�Q�A��!!\n"NOR, ob);
   }
 }
 return;
}

void leave_message(object me)  //*****�X�Ȱʧ@*****
{
 object luky,ob1,ob2;
 if(luky=find_player("luky")) //���H�b�C����
 {
  if(me->query("id")!="luky") //�O�H�i�J
  {
   ob1=find_object(__DIR__"workroom");
   ob2=present("luky",ob1);
   if(ob2) return; //���H�b�ж����Y�����ʧ@
   add("guest",me->query("id")+" - "); //�����X��
   tell_object(luky,"[1;37m���X�Ȩ��o!("+me->query("name")+")[m\n");
   tell_object(me,"[1;37m�s��(Luky)�i�D�A: ��!�w����{!!�ڰ��W�^�ө۩I�A![m\n");
  } else //of if(me->query("id")!="luky") ���H�i�J
  {
   if(query("guest")) //���X�Ȭ���
   {
    tell_object(me,"[1;37m���Ѫ��X�Ȧ�:"+query("guest")+"[m\n");
    delete("guest");
   } else //of if(query("guest")) �S���X�Ȭ���
   {
          //tell_object(me,"[1;37m�����٨S���X�ȨӹL[m\n");
   }
  }
 } else //of if(luky=find_player("luky")) ���H���b�C����
 {
  add("guest",me->query("id")+" - ");  //�����X��
  tell_object(me,"[1;37m�p�s��(Lobster)�i�D�A: Luky�٨S�ӳ�..[m\n");
 }
 
 if( file_size("/u/l/luky/note")>0 )
 {
  write(WHT"=======================�s���Ƨѿ�=========================\n");
  me->start_more( read_file("/u/l/luky/note") ); //me->cat("/u/l/luky/note");
  write("\n"NOR);
 }
 
}


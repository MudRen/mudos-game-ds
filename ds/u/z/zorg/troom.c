#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short",HIW"�i"HIG"��"HIR"��"HIC"�Z���Ѩ�"HIY"��"HIW"�j"NOR);
        set ("long", @LONG[33m [0m   
[0;1;36m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[1m [1m [1m [1m [1m�[1mO[1m�[1m@[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mM[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[0m
[0;1;36m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[1m [1m [1m [1m [1m�[1mO[1m�[1m�[1m�[1mR[1m�[1m�[1m�[1mw[1m�[1m�[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[1m [1m [1m [0m
[0;1;36m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[1m [1m [1m [1m [1m�[1m�[1m�[1m�[1m�[1ma[1m�[1m�[1m�[1m�[1m�[1m@[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[0m
[0;1;36m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[1m�[1mi[1m [1m [1m [1m [1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mw[1m�[1mg[1m�[1m�[1m�[1mF[1m�[1mw[1m�[1m�[1m [1m [1m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1mi[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mi[1m�[1mi[1m [1m [1m [0m
[0;1;36m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1mi[1m�[1mi[1m�[1m�[1m�[1m�[1m�[1mi[1m�[1mi[1m�[1mi[1m [1m [1m [1m [1m�[1mo[1m�[1mS[1m�[1m`[1m�[1mn[1m�[1mb[1m�[1mo[1m�[1m�[1m�[1m�[1m�[1m~[1m [1m [1m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1mi[1m�[1mi[1m�[1m�[1m�[1m�[1m�[1mi[1m�[1mi[1m�[1mi[1m [0m
[0;1;36m [1m [1m [1m [1m [1m [1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m [1m [1m [1m [1m�[1mC[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m][1m�[1mt[1m�[1mP[1m�[1m�[1m�[1mG[1m.[1m.[1m.[1m [1m [1m [1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m�[1mi[1m [1m [0m
[0;1;36m [1m [1m [1m [0m  [0;1;35m�[1m`[1m [1m [1m�[1m�[1m [1m [1m�[1m�[1m [1m [1m�[1ml[1m-[1m-[1m�[1m}[1m�[1mG[0;36m [0;1;5;32m�[1;5mi[1;5m [1;5m�[1;5m`[1;5m [1;5m [1;5m�[1;5m�[1;5m [1;5m [1;5m�[1;5m�[1;5m [1;5m [1;5m�[1;5ml[1;5m [1;5m�[1;5mj[0;1;35m [1m�[1m}[1m�[1mG[1m-[1m-[1m�[1m`[1m [1m [1m�[1m�[1m [1m [1m�[1m�[1m [1m [1m�[1ml[0m
LONG);
        set("valid_startroom", 1);
        set("exits", ([
        "future" : "/open/world3/meetroom",
        "wiz":"/d/wiz/hall1",
        "mulder" : "/u/m/mulder/workroom", 
        "naboo" : "/u/m/mulder/area/naboo/middle.c",       
        "npc" : "/u/z/zorg/area/laboratory",
        ])); 
//        set("objects", ([ 
//        __DIR__"area/npc/michel.c" : 1,
//        __DIR__"area/npc/uriel.c" : 1,
//        __DIR__"area/npc/notfair.c" : 1,
//        __DIR__"area/npc/gabla.c" : 1, 
//        ]));  
set("valid_startroom", 1);
set("no_kill", 1);
set("light", 1);
set("no_fight", 1);
set("no_clean_up", 1);
        setup(); 
call_other("/obj/board/zorg_b","???");
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
       message_vision("[0;1;5;31m�[1;5mF[1;5m�[1;5mJ[1;5m�[1;5m�[1;5m�[1;5m�[1;5m�[1;5m@[1;5m�[1;5mF[0m�G"+ob->name()+" �A��|�]�ӳo�C(-_-)�I\n"NOR, ob);
     ob->move("/d/slake/start");
   } else 
   {
message_vision(HIY"\n[0;1;5;31m�[1;5mF[1;5m�[1;5mJ[1;5m�[1;5m�[1;5m�[1;5m�[1;5m�[1;5m@[1;5m�[1;5mF[0m�ĤF�@�f���D: �ڻ��I�I "+ob->name()+"�դU�I�I�A�o...........\n"NOR, ob);
   }
 }
 return;
}

void leave_message(object me)  //*****�X�Ȱʧ@*****
{
 object zorg,ob1,ob2;
 if(zorg=find_player("zorg")) //���H�b�C����
 {
  if(me->query("id")!="zorg") //�O�H�i�J
  {
   ob1=find_object(__DIR__"workroom");
   if(ob2) return; //���H�b�ж����Y�����ʧ@
   add("guest",me->query("id")+" - "); //�����X��
   tell_object(zorg,"���X�Ȩ��o!("+me->query("name")+")\n");
   tell_object(me,"�Z���Ѩ�(zorg)�i�D�A:���I�A���I���ڻ��I�A���ڻ��I�`�Ю��l�}���}�G�H�H�H\n");
  } else //of if(me->query("id")!="zorg") ���H�i�J
  {
   if(query("guest")) //���X�Ȭ���
   {
    tell_object(me,"���Ѫ��X�Ȧ�:"+query("guest")+"\n");
    delete("guest");
   } else //of if(query("guest")) �S���X�Ȭ���
   {
          //tell_object(me,"�����٨S���X�ȨӹL\n");
   }
  }
} else //of if(zorg=find_player("zorg")) ���H���b�C����
 {
  add("guest",me->query("id")+" - ");  //�����X��
tell_object(me,"[0;1;5;31m�[1;5mF[1;5m�[1;5mJ[1;5m�[1;5m�[1;5m�[1;5m�[1;5m�[1;5m@[1;5m�[1;5mF[0m�i�D�A: �Z���Ѩ�-�|��k �|���r��,�L�U����Q�F�I");
 }
 }


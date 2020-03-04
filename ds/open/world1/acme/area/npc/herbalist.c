#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("�ľQ�x�d" , ({ "herbalist" }) );
        set("level",5);
        set("race","�H��");
         set("gender","�k��");
        set("age", 23);
        set("no_fight",1);
        set("long","�L�O�M���ľQ���x�d�C\n");
        set("sell_list",([
         __DIR__"obj/god_pill" : 15,
         __DIR__"obj/head_pill" : 20,
         __DIR__"obj/hand_pill" : 20,
         __DIR__"obj/body_pill" : 20,
         __DIR__"obj/foot_pill" : 20,
        ]) );
        setup();
}
void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}
int accept_object(object who,object ob)
{
        object me,obj;
        me=this_player();
        obj=this_object();
        if(ob->name()!="�������߯�" && ob->name()!="�C�P������" && ob->name() != "�sŽ���Ū�" &&ob->name() != "�M�H�ۺ�G" && ob->name() != "�f�H�F�Ǯ�" )
        {
           command("eh");
           command("say �ڤ��ݭn�o�تF��C");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+me->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
message_vision("$N���F���E�x�d�@��"+ob->query("name")+"�C\n",me);
             command("hmm");
             obj->set_temp("makepill/pill",1);
             obj->set_temp("makepill/name",ob->query("name"));
             obj->start_busy(7);
             destruct(ob);
             call_out("makepill",1,me);
             return 1;
        }
} 
void makepill()
{
   int i;
   object me,obj,pill;
   me=this_player();
   obj=this_object();
   i=obj->query_temp("makepill/pill");
     switch( i ) {
           case 1:
               say(HIY"���E�x�d�J�Ӫ��ݤF��"+obj->query_temp("makepill/name")+"�C\n"NOR);
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",2,obj);
               break;
           case 2:
               command("say �o��"+obj->query_temp("makepill/name")+"�i�N�����������ġC");
               command("say �ڳo�N���A�N�C");
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",2,obj);
               break;
           case 3:
               say(HIY"���E�x�d��"+obj->query_temp("makepill/name")+"��i�������Y�C\n"NOR);
               say(HIY"���E�x�d���ۧ⤦����i�C�ɤ��l�̡A���I�U�F�X�ڤ����i�C�ɤ��l�C\n"NOR);
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",4,obj);
               break;
           case 4:
               say(HIY"�S�h�[�ɶ��A�u�������_�X�@�������ϡC\n"NOR);
               command("say ���F�I���F�I");
               obj->set_temp("makepill/pill",i+1);
               call_out("makepill",2,obj);
               break;
           case 5:
               if(obj->query_temp("makepill/name")=="�������߯�")
               {
                 pill=new(__DIR__"obj/pill.c");
               }
               if(obj->query_temp("makepill/name")=="�C�P������")
               {
                 pill=new(__DIR__"obj/pill2.c");
               }
               if(obj->query_temp("makepill/name")=="�sŽ���Ū�")
               {
                 pill=new(__DIR__"obj/pill3.c");
               }
               if(obj->query_temp("makepill/name")=="�M�H�ۺ�G")
               {
                 pill=new(__DIR__"obj/pill4.c");
               }
               if(obj->query_temp("makepill/name")=="�f�H�F�Ǯ�")
               {
                 pill=new(__DIR__"obj/pill5.c");
               }
               pill->move(obj);
               say(HIY"���E�x�d�q�������X�F�@�Ӥ��ġC\n"NOR);
               command("give pill to "+me->query("id"));
               obj->delete_temp("makepill");
               break;
        }
 }

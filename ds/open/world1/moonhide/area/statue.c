#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG"�����J��"NOR, ({"statue"}) );
      set("long", @LONG 
�@���j��������[0;1m�[1mA[0m���䦳�@���_�F�k�u�B�ܵۤ@�ǯ}
�ܭ����H[0;1m�[1mA[0m�����٭I�ۤ@�`���C[0;1m�[1mA[0m�����D�O�� ? 
[�o�y�J���n���i�H����(move)���ˤl?]
LONG
 );

        set_weight(9999999);
        set("unit", "�y");
        set("no_sell", 1);
        set("no_give", 1);
        set("no_get", 1);
        set("no_drop", 1);

        setup();
}
void init()
{
    add_action("do_move","move");
}
int do_move(string arg)
{ 
    object me=this_player(),ob=this_object(),mobp; 
    if(ob->query_temp("moved")) return notify_fail("��観�H���ʹL�F�C\n");
    if(!arg||arg!="statue") return notify_fail("�A�n���ʤ���?\n");
     switch (random(4) ){ 
                case 0:
      message_vision("$N�N"+ob->name(1)+"���ʤF�@�I�I�I�o�X�F�y�ɹɡz���n�T..\n",me); 
      tell_object(me,"�èS�o�ͤ����...\n");
                      me->start_busy(2); 
                      ob->set_temp("moved",1); 
                      call_out("stop_moved",600,ob);
                      break;
               case 1:
      tell_object(me,"�`�N�I\n");
      message_vision("$N�N"+ob->name(1)+"���ʤF�@�I�I�I�o�X�F�y�ɹɡz���n�T..\n"
                     "��M�@�D���j���¼v���{....\n",me);
                     me->start_busy(3);
                     mobp=new(__DIR__"god-prey"); 
                     mobp->move(environment(this_player()));   
                     mobp->kill_ob(this_player()); 
                     ob->set_temp("moved",1); 
                     call_out("stop_moved",600,ob);
                     break;   
/*�s�W By Jangshow */

               case 2:
       message("world:world1:vision","\n\n"+HIW"�@�}�g���I�����b�j�Ӫ��~��I���V����ѪŤ����U�I\n\n"+NOR,users());
                     mobp=new(__DIR__"god-prey");
                     mobp->move(environment(this_player()));
                     mobp->set("level",70+this_player()->query("level")/6);   
                     mobp->kill_ob(this_player());
                     me->damage("hp",500);
                     ob->set_temp("moved",1); 
                     call_out("stop_moved",1000,ob); 
                     break;
                 }  
        return 1;
}
void stop_moved(object ob)
{
     if(!ob) return; 
     ob->delete_temp("moved");
}


// quest mob
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���]¾��", ({"keeper"}) );
	set("long", "�L�O�o�����]��¾��,�i�H�V�L���Х�(book)�C\n");
	set("race", "�H��");
	set("age", 49);
	set("level", 5);
        set("chat_chance",6);
        set("chat_msg",({
        (:command("sigh"):),           
        (:command("say ���ӫ�˿�n�O......"):),   
        }) );
	setup();
}
void init()
{
        add_action("do_book","book");
}
int do_book(string arg) 
{
        object me,ob;
        me = this_player();
        ob = this_object();
          if(!arg || arg !="room" )
                return notify_fail("�A�n�q�жܡH(book room)�u�n�������ӳ�쪺�q�l���C\n");
{
                if( !me->can_afford(300) )
                        return notify_fail("�A���b�����������q�l����C\n");
                me->receive_money(-300);
                me->add_temp("sleep",1);
                message_vision("$N�ǰe�F�������ӳ�쪺�q�l�������]¾���C\n",me,ob);
               // command("nod "+me->query("id"));
command("say �и�ڨӳo��C\n"); //debug
me->move("/open/world3/alickyuen/area/inn3"); 
}
        return 1;
}

int accept_object(object who,object ob)
{
        object card;
          if(ob->name()!="�ϥd")  return 0;
        else {
                
          if(this_object()->query_temp("give_card")) 
          {
              command("say ���ڷFԣ�A�o���O�ڪ��C");
            return 0;
          }    
        message_vision("$N���F���]¾���@�i$n�C\n",who,ob);
        destruct(ob);
        command("flip"+who->query("id"));
          command("say �٦n��^�o�i�ϥd�A���M���ڴN.....");
        command("thank "+who->query("id"));
        command("whisper "+who->query("id")+" �ڴN�K�O�۫ݧA�@���a�A�и�ڨӡC");
        who->move("/open/world3/alickyuen/area/inn3"); 
        set("chat_msg",({
        (:command("hmm"):),            
        }) );
        set_temp("give_card",1);

        return 1;
        }

}
void reset()
{
        if(query_temp("give_card") )
                delete_temp("give_card");
}


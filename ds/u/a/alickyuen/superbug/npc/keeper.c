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
                if( !me->can_afford(150) )
                        return notify_fail("�A���b�����������q�l����C\n");
                me->receive_money(-150);
                me->add_temp("sleep",1);
                message_vision("$N�ǰe�F�������ӳ�쪺�q�l�������]¾���C\n",me,ob);
               // command("nod "+me->query("id"));
command("say �и�ڨӳo��C\n");
me->move("/open/world3/alickyuen/superbug/inn"); 
}
        return 1;
}

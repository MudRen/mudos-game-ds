#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"����C�C"NOR, ({"goldflower grandmother","grandmother"}) );
        set("long", @LONG
�@�Ӭݰ_�ӤQ���~�ڪ��Ѧ~���H�A�n�w���I(pay)�o���N�i�H�F�C
LONG
   );
        set("age",91);
        set("level",1);
        set("race","�H��");
        set("gender","�k��");
        set("chat_chance",7);
        set("chat_msg",({
  "����C�C�����D:�ڨӳo�X�~�F?...��F..�Q�o�ӷF��? !\n",
  (: command,"grin" :),
  (: command,"think" :),
}));
        
        set("inquiry",([
  "�w��" : "�h�Ӫw�����q���߰��d�I\n",

]));
setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
    add_action("do_pay","pay");
}
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "����C�C��A��:�ɥR��O�ӳo�N��F  !\n");
                        break;
                case 1:
                        say( "����C�C��:�A��夣�����ܡA�w�����q���d��C\n");
                        break;
      }
}
int do_pay(string arg) 
{
        object me,grandmother;
        string c;
        me = this_player();
        grandmother = this_object();

        if( !arg || arg!="grandmother")
        {
notify_fail("�Ы��w�H�W�C\n");
                return 0;
        }

        if( !me->can_afford(500) )
                return notify_fail("�n�I500���~��w����C\n");
        if( me->query_temp("suds_1")>0 )
                return notify_fail("�A�w�I�L���F...�i�h�w���a..�C\n");
        me->receive_money(-500);
        me->add_temp("suds",1);
        message_vision("$N�I���F$n���ʤ��C\n",me,grandmother);
        command("hoho "+me->query("id"));
        return 1;
}


#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p��" , ({ "child" }) );
        set("level",10);
 set("race", "�H��");
    set("chat_chance",10);
        set("age", 50);
        set("long","�@�Ӥp�ġA���������򥿦b�j���C\n");
    set("chat_chance",10);
        set("chat_msg",({
                         (:command,"cry":),}));
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
add_action("do_nod","nod");
}

int do_nod(string arg)
{
      object me;
      me=this_player();
          if(!me->query_temp("find_child")) return 0;
 {
        command("say ���A�ֱa�ڪ����ӧ�ڡA���¡A�֭�C");
command("smile");
me->delete_temp("find_child");
me->set_temp("go_child",1);
}
}
void greeting()
{
object me;
me=this_player();
          if(!me->query_temp("gived_key")) return 0;
 {
        command("cry");
command("say �A�O�ӱϧڪ��ܡH�ڰg���F������^�a�h�C");
me->delete_temp("gived_key");
me->set_temp("find_child",1);
}
}

#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"Dontpkme�Z���M�a"NOR, ({ "weapons expert","expert","w","e" }) );
        set("chat_chance", 15);
           set("long",@STORY
�A�i�H�ХL���A���A���Z�����W�A�Ϋa�W�A�ҳ��w���ٸ�
�ϥΤ�k: sign <wp>
STORY);  

        set("combat_exp",5);
        set("score",20);
        set("age",80);
        set("no_kill", 1);
        set("kind", "�����ر�");
        set("kill_msg", "�O�ñ��L,�|�Q�Ův�|!\n");
        setup();
}
void init()
{
        add_action("do_wish", "sign");
}

int do_wish(string arg)
{
object me,wp;
me=this_player();

        if(!arg)
                return notify_fail("�A�Q������F��a�W��?\n");
        if( !(wp = present(arg, me)))
                return notify_fail("�A���W�S���o�تZ���C\n");
        if( !wp->query("skill_type"))
                return notify_fail("�o���O�Z���A�Z���M�a�u���A�a�Z�����ٸ��C\n");

        write("�Z���M�a�q�A��W���L"+wp->name()+"�ݹD�G�A�Q�n�a����˪��ٸ��H\n�п�J�G");
          input_to ("test1",me,wp);

                return 1;    
}

int test1 (string rep,object me,object wp)
{
        wp->set("name",rep+wp->query("name"));
        write("\n�Z���M�a���D�G�̷ӧA���h�J�A�����F�I\n");
          return 1;
}


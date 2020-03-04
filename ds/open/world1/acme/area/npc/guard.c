#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�@�|�Z�v" , ({ "guard" }) );
        set("level",10);
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
        set_skill("staff", 20);
        set_skill("unarmed",15);
        set_skill("parry", 10);
        set_skill("dodge", 20);
        set("long","�L�O�O�ê����w�����Z�v�A�ݨӪZ�\\�ä��z�C\n");
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                (:command("wield stick"):),
                YEL"�@�|�Z�v�ܹD�G�S�̡̭I��o�å뵹�_�F�I\n"NOR,
        }) );        
        setup();
        carry_object(__DIR__"wp/stick.c");
}
void init()
{
        ::init();
        add_action("do_kill","kill");
}
int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;

        if( is_fighting(me) ) return 0;
        command("say ���D�R�x�H�y�ϰաH�����ñ��H�I�I�h���a ...\n");

        ob=all_inventory(environment());
        for(i=0;i<sizeof(ob);i++)
        {
                ob[i]->soldier_assist(this_object(), me);
        }
        return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
            ||      is_fighting(me) )
                return;

          switch(random(4)) {
        case 0: command("say ���D�R�j�x�N���T�������M�x���T\n"); break;
        case 1: command("say �ܹD�R�ϤF�ϤF�T�S�̡̭M���U�o�ӭ�{�T\n"); break;
        case 2: command("say �ޡT�A�Q�F����S"); break;
        case 3: command("say �ӤH���T���U���ӥi�ê��å�T"); break;
        }
         me->fight_ob(alert);
         kill_ob(me);
}

#include <npc.h>
#include <ansi.h>

void create()
{
        set_name("�C��", ({ "swordsman" }) );
        set("long",@long
    �o�O�@�Ӥ����W���C�ȡA���y�宣���Ȫ��ҼˡA�Ҭ諸�@��զ�A�]
�g�F���֦��A��W���۪��u�C�]�o�ݵo�Ӥ����A
long
);
        set_race("human");
        set("age", 28);
        set_skill("sword",60);
        set_skill("dodge",50);

        set_attr("str",25);
          set("chat_chance", 20);
        set("chat_msg", ({
                (: command("shiver") :),
                "�C�Ȥ@���樣�A�A�H�Y�@��Ԧ�A�A�߰ݹD�G�u�����A�O�_��a�ڨ��X�o���˪L�ڡH�v�C\n",
                "�C�ȴ����������o�ݡA�L�̤����a��ۡG�u�ڤ��Q���b�o�̡A�ڱo���I���}�o�̡C�v\n",
        }));

        setup();
        set_level(2);                  // ��C��
        carry_object("/d/obj/shortsword")->wield();
}

void init()
{
        string env;
        object me,ob;
        if( query("quest_ok") ) return;
        ob=this_object();
        me=ob->query_leader();
        env=file_name(environment(this_object()));
        // �w�g���\��F�����˪L�J�f
        if( env=="/d/duli_forest/map_0_9" ) {
                set("quest_ok",1);
                call_out("do_quest",1,me,ob);
        } // end if
        ::init();
}
int do_quest(object me,object ob)
{
        object item;
        // �԰����N��F
        if( ob->is_fighting() ) return 1;
        // ���Ѱg
        if( !query("quest_ok") ) return 1;
        // �S���Ѱg�̡A����destrcut..
        if(!me) {
                message_vision(CYN"�C�ȴ��F����A�֨B���}�o�̤F�C\n"NOR,ob);
        } else {
                // �Ѱg�� �o�� �ܤ������U(unlimted skin)
                item=new("/d/obj/unlimted-skin");
                if(!item->move(me))
                        item->move(environment());
                        command("jump");
                        message_vision(CYN"�C�ȳ߹D�G�u�u�O���§A�F�A�o�ӪF��N�e���A�a�C�v\n"NOR,ob);
        		message_vision("$N���F$n�@�Ӥ��U�C\n"NOR,ob,me);
                        message_vision(CYN"�C�ȴ��F����A�֨B���}�o�̤F�C\n"NOR,ob);
                }
                destruct(ob);
        return 1;
}
int accept_fight(object ob)
{
        do_chat("�C�ȷn�n�Y���G�u�ڥu�Q�������}�o�˪L�A�����Ųz�A�ڡC�v\n");
        return 0;
}

/* Quest:�a�C�Ȱk���g���˪L */
void relay_say(object me, string arg)
{
        object ob=this_object();
        if(arg=="��" && !ob->is_fighting() )
        {
                do_chat("�C�Ȱ����a���D�G�u�u�O���§A�A�N���ڸ�ۧA�@�_��ʧa�C�v \n");
                ob->guard_ob(me);
                ob->set_leader(me);
                return;
        }
        if(arg=="����" && !ob->is_fighting() )
        {
                do_chat("�C�ȥ���a���D�G�u�n�a�A���U���A���F�C�v \n");
                command("follow none");
                command("guard cancel");
                return;
        }
        
}

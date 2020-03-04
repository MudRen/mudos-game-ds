#include <ansi.h>
inherit NPC;
void combat_ai();

void create()
{
        set_name("����X" , ({ "mo yue-rou", "mo", "yue","rou" }) );
        set("long",@long
����X�O�O�H�����[�D���빩���W�ͤk�A���o���p�ѥP�A�����Ť�
�@���j�F��Ǫ��j�������A�ݱo��u�١C
long
);
        create_family( "�H����", 3, "�H�߫��D");
        set("level", 35);
	set("race","celestial");
        set("age",25);
        set("class1","�H����");
        set("gender","�k��");
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("fall-thunder",100);

        set("inquiry", ([
                "���j��" : "�����A�{�ѭʾ]�������j���ܡH",
                "���Q�f" : "��...�O�ڡA�������o���j���ӳo�వ�ȡA���L�n����ơA�S���Ÿ�ڨ����C",
        ]) );

          set("chat_chance", 5);
        set("chat_msg",({
                (: command("sigh") :),
                (: command("sob") :),
                (: command("say �u�Q�������j���@����...") :),
        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil",-30);
        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
                  carry_object(__DIR__"wp/qing-yang-claw")->wield();
                carry_object(__DIR__"eq/frostarmor")->wear();
                carry_object(__DIR__"eq/frostboots")->wear();
                carry_object(__DIR__"eq/frostcloth")->wear();
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
}

void init()
{
        ::init();
        add_action("do_speak","say");
}


void clear_quest() {
    if(!objectp(this_object())) return;
        delete("quest");
}

int do_speak(string arg)
{
        object me, ob;
        me=this_player();

        if(arg == "����" && !me->query_temp("frost_quest/rou") ) {
                if(query("quest")) {
                        command("say �u�O���§A�F�A��w�g���H���ڳo�Ӧ��F�C");
                } else {
                        command("say �p�G�A�@�N���ܡA�O�_��Щp���ڧ�o�ӵ��S�浹�L�O�H");
                        me->set_temp("frost_quest/rou",1);
                }
        }
        if(arg == "�@�N" && me->query_temp("frost_quest/rou")==1 ) {
                set("quest",1);
                command("jump");
                command("say ���u�O���§A�F�C");
                ob = new(__DIR__"obj/silk-cloth");
                ob->move(me);
                message_vision("$N�q�h�����X�@�����S�浹�F$n�C\n",this_object(), me);
                me->delete_temp("frost_quest/rou");
                call_out("clear_quest", 600);
        }

        return 0;
}



void combat_ai()
{
        int i;
        object *target;
        object liu=this_object();

        target = all_inventory(environment(liu));

        /* �Z���Q�����A�h�˦^�h */
        if( !liu->query_temp("weapon") ) 
                command("wield fist");

        i = sizeof(target);
        while( i-- )
        {
                if( liu->is_killing(target[i]) || liu->is_fighting(target[i]) )
                {
                        if( !target[i]->is_busy() ) continue;
                        if( userp(target[i]) )
                                 command("cast fall-thunder on " + getuid(target[i]) );
                        else
                                command("cast fall-thunder on " + target[i]->query("id") );
                            return;
                }
        }
        // �䤣��busy���ĤH�A�N�o�ʴH�y
        command("cast freeze-ball");
        return;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
                HIG"\n�i�D�������j"HIM"�H�����[�D���빩���W�ͷR�k�u����X�v�����b" +ob->name(1)+"����W�F�I�I\n"+NOR,users());
        ob->add("popularity", 1); //�n��
        tell_object(ob,HIW"(�A�o��F���I�n��C)"NOR);
        ::die();
        return;
}


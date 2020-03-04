inherit NPC;
#include <ansi.h>
void create()
{
 set_name(HIG"�C�h��"NOR, ({ "master sie of ce", "master", "sie","ce" }) );
 set("nickname", HIW"�F�۱�-"HIC"�ѫ�"NOR""CYN"����"HIC"�¥D"NOR);
set("title", HIW"�F�۱�"HIR"�ĥ|�N"NOR""RED"�¥D"NOR);
        set("gender", "�k��");
        set("class","fighter");
        set("age", 40);
        set("adv_class",1);
        set("class1","�F�۱�");

 set("guild_gifts",({7,4,1,8}));
        set("long",
"�L�O�@���F�۱Цb�ѫ����ª��¥D�A�ݥL�����եխD�D���A���I���H���H��\n"
"�H�L�O�@��g�L�h�~�W�ת�����H�A�C�@���F�۱Ъ��¥D���n�g���t�a���T\n"
"�~����M�W�סA�~����������C\n"
        );
        set("max_ap",2225);
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
        "bagi_fist":({150,3,60}),
          "horse-steps":({130,4,100}),
        "dodge" : ({120,2,60}),
        "parry" : ({120,3,70}),
        "unarmed":({110,3,80}),
        "fork":({120,3,70}),
            "da-fork":({150,3,60}),
        ])  );
        set_skill("unarmed", 80);
        set_skill("sword",100);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_temp("apply/armor",38);
        set("no_check_class",1);
        set("chat_chance",20);
        set("chat_msg",({
          "�C�h���w�w�����D�G�u�C�j�M��W�۹�C�v\n" ,
          "�C�h���C�C�����D: �u�e�����M�l�׼C�C�v\n",
          "�C�h����A���D: �Q�[�J�F�۱жܡH\n",
          "�C�h����A���D: �A�����ڶܡH\n",
          "�C�h�����a���D: �����D�֯����ڧ����ơC\n",
        (:command("peer"):),
        (:command("sigh"):),
        (:command("hi"):),
        (:command("wahaha"):),
         }) );


                set("chat_chance_combat", 100);
                set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
                (:command("exert da-fork"):),
         }) );
        
        create_family("�F�۱�", 4, "���¾¥D");
        setup();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_kick","kick");
}
int do_slap(string arg)
{
object ob1,ob2;
ob1 = this_player();
ob2 = this_object();
if(!arg) return notify_fail(YEL"�A�Q��֡S"NOR);
if(arg != "master" && arg != "sky" && arg != "wind");
message_vision(YEL"$N�@�}��b�C�h��(Master sie of ce)�������W�M�L�X�@�ӲM�����c�L�C\n"NOR,this_player());
command("say �i�c�I�ڳ̰Q���O�H��ڧ����F�I�I");
ob1->kill_ob(ob2);
ob2->kill_ob(ob1);
return 1;
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();
        message_vision("$N�Q�[�J�u"+ arg+ "�v�C\n",me); 
        if(arg != "�F�۱�") return notify_fail("�C�h�����D�G�A�n�[�J����H\n");
        if(me->query("adv_class")) return notify_fail("�A�w�������F�C\n");
        if(me->query_temp("can_join_bo"))
        {
                i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
                switch(i)
                {
                case 1:
                        me->set("adv_class",1);
                        me->set("class1","�F�۱�");
                        me->create_family("�F�۱�",5,"�Ю{");
                        message_vision("$N�[�J�F�F�۱СC\n",me);
                        me->delete_temp("can_join_bo");
//  message("world:world1:vision",HIR"\n�F�۱Фѫ����¾¥D�C�h���j�ۡG" +HIC"�w��"+me->query("name")+"�[�J�F�۱СI\n\n"+NOR,users());
                        return 1;
                case -1: return notify_fail("�A�w�������F�C\n");
                case -2: return notify_fail("�A�w�������F�C\n");
                case -8: return notify_fail("�S���o�ت����C\n");
                }
                return 0;
        }
        if(me->query_temp("join_bi") )
                command("say �o��"+ RANK_D->query_respect(me) +"�A�٨S���ڧ��ܡH\n");
if(me->query_temp("join_bl") )
     command("say "+ RANK_D->query_respect(me) +"�٨S��C�����t�@��¥D�ܡH�֥h�a�C");
else
        {
                command("say �ڭ̥t�@�Ӥ��ª��¥D��@��Z���A��n�ڤS���D��򰵡C");
                command("say �i�O��ʤ@�ӧ��ƭC�A�A�����ڧ�쥦�ܡH");
                command("addoil");
                me->set_temp("join_bi",1);                  
        }

        return 1;
}
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
                if(me->query("class1")=="�F�۱�" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("�A���O�F�۱Ъ��̤l�C\n");
}
int accept_object(object me, object ob)
{    
if(me->query_temp("join_ll") && me->query_temp("join_bi") )return  notify_fail("�A�n���֤���F��? \n");
if( ob->query("join_blade") == 1 ) {
message_vision("$N�N�@��M�浹"HIG"�C�h��"NOR"�C\n",me);
command("say ���§A�j�ѻ�����M���ӵ��ڡA�A�����C");
message_vision("$N�ݵ��C�h�����ۤ@�ʫH���F�X�ӡC\n",me);
command("say �A���ڧ�o�ʫH�浹�C�ѭ��a�C");
me->set_temp("join_ba",1);
me->delete_temp("join_bl");
new(__DIR__"obj/notea")->move(me);
}else if( ob->query("lione1_join_quest") == 1 && me->query_temp("join_bi")) {
message_vision("$N�N�s�y�Z�������ƥ浹�F�C�h��\n",me);
                command("say ���¡A�A������I");
message_vision("$N�ݨ��C�h�����ۧ��ƥ�i���l�̡A���@�|�@��C�N�X�ӤF�C\n",me);
                command("say �A���۳o��C�h���ڭ̥t�@��¥D�a�C");
                me->set_temp("join_bl",1);
new(__DIR__"eq/sword.c")->move(me);
                me->delete_temp("join_bi");
}else if( ob->query("lione1_join_quest") == 2 && me->query_temp("join_ba"))
{
message_vision("$N�N�P�¨�浹�F�C�h���C\n",me);
                command("say ���������A���W�A�F�A�ڴN���A�J�ڪ��U�a�C");
                command("smile");
                me->set_temp("can_join_bo",1);
                me->delete_temp("join_ba");
        }
else
return notify_fail("�C�h�����Q���A���F���C\n");

        return 1;
}

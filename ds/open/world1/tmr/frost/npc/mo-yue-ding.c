#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("���빩" , ({ "mo yue-ding master", "mo", "yue","ding", "master" }) );
        set("long",@long
���빩�O�H�����ĤG�N�x���H�A�����譱�j�աA�����G�u�A
�i�O�@�L��鯺�e�����A�D�`���N�ۤw���ͬ��C
long
);
        create_family( "�H����", 2, "�D��");
        set("level", 40);
	set("race","celestial");
        set("age",45);
        set("class1","�H����");
        set("gender","�k��");
        set("adv_class",1);
          set("guild_gifts",({0,5,9,6}));
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("fall-thunder",100);
          set_skill("swallow-flying",100);
         map_skill("dodge","swallow-flying");

        set("guild_skills",([
               "dodge" : ({120,3,70}),
               "parry" : ({130,2,60}),
               "unarmed" : ({130,3,70}),
               "pick-plumblossom" : ({130,3,70}),
                 "swallow-flying" : ({130,3,80}),
                 "meditate" : ({130,3,80}),
        ])  );
        set("guild_spells",([
               "freeze-ball" : ({130,3,90}),
               "fall-thunder" : ({130,3,90}),
                 "life-death-symbol" : ({130,3,50}),
                   "ice-puppet" : ({130,3, 80}),
        ]) );
        
                set("chat_chance", 20);
        set("chat_msg",({
                (: command("smile") :),
        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil",-60);
        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
                carry_object(__DIR__"wp/taoism-claw")->wield();
                carry_object(__DIR__"eq/frostarmor")->wear();
                carry_object(__DIR__"eq/frostboots")->wear();
                carry_object(__DIR__"eq/frostcloth")->wear();
                carry_object(__DIR__"eq/frosthands")->wear();
                carry_object(__DIR__"eq/frosthead")->wear();
                carry_object(__DIR__"eq/frostlegging")->wear();
                carry_object(__DIR__"eq/frostmask")->wear();
                carry_object(__DIR__"eq/frostneck")->wear();
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
           carry_object("/daemon/spell/frost-obj/ice-puppet")->set("hp",4000);
        apply_condition("frost_harvest",100);
        apply_condition("frost_dust",100);
}

void init()
{
    ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");

        add_action("do_skill_train","train");
         add_action("do_join","join");
        add_action("do_advance","advance");
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


int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        return 1;
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
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") == "�H����") return notify_fail("�A�w�O�H�����̤l�F�C\n");
        if( me->query("adv_class") ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
        if(arg != "frost") return notify_fail("�A�n���J���@�Ӫ���?\n");
        command("say �Q�n�[�J�H�����צ�ڡH���A�i�M�����媺�̲ץؼжܡH");
        message_vision(YEL"$N���U�Ӥj�n���D�G�l�p�B�B�}�����B�\\�P�ѦX�I�I\n"NOR,me);
        command("say �n�n�n�I�I�A�N�[�J�ڭ̴H�����n�n��߭׽m�a�C");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","�H����");
        me->create_family("�H����",3,"�D��");
        me->set("guild_rank","�H�����ĤT�N�D��");
    me->set("guild_gifts", query("guild_gifts") );
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="�H����") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O�H�����̤l�C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // �N rank �������Ӽh��
        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                        case 0: rank = "�H�����ĤT�N�D��"; break;
                        case 1: rank = "�H�����ĤT�N�D�h"; break;
                        case 2: rank = "�H�������H�߫��D"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "�H�����ĤT�N�D��"; break;
                        case 1: rank = "�H�����ĤT�N�D�h"; break;
                        case 2: rank = "�H�������H�߫��D"; break;
                }
        }
        return rank;
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
                HIG"\n�i�D�������j"HIM"�\\�P�ѦX���H�����[�D�u���빩�v�D���Ѧb" +ob->name(1)+"���⤤�F�I�I\n"+NOR,users());
        ob->add("popularity", 3); //�n��
          if( objectp(present("ice-puppet", this_object() ))) destruct(present("ice-puppet", this_object() ) );
        tell_object(ob,HIW"(�A�o��F3�I�n��C)"NOR);
        ::die();
        return;
}


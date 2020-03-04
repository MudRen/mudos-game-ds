#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("�����l" , ({ "yun zhong-zi master", "yun", "zhong","zi", "master" }) );
        set("long",@long
�����l�O�H�������Хߩl���A�P���D���A���p�s�����A
�L�������S�A�M�_��U�A��@�ӿW�ߡC�����l�i���O�D�Ф����
�~�Ӫ��Ĥ@�H�A�׬��w��G�ѹD�C
long
);
        create_family( "�H����", 1, "�u�H");
          set("level", 55);
        set("race","celestial");
        set("age", 120);
        set("class1","�H����");
        set("class2","�H����");
        set("gender","�k��");
        set("adv_class", 2);
       set("guild_gifts",({0,5,9,6}));
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("sevenfold-freeze",100);
        set_spell("thunder-doom",100);
        set_spell("fall-thunder",100);
          set_skill("constant-virtue",50);
        set_skill("swallow-flying",100);
        map_skill("dodge","swallow-flying");

        set("guild_skills",([
                 "meditate" : ({130,3,100}),
                 "pure-energy" : ({130,3, 60}),
                  "force" : ({130,3, 80}),
        ])  );
        set("guild_spells",([
               "life-death-symbol" : ({130,3, 90}),
               "ice-puppet" : ({130,3, 90}),
               "thunder-doom" : ({180,3, 40}),
               "sevenfold-freeze" : ({180,3, 40}),
        ]) );
        
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil",-180);
        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
                carry_object(__DIR__"eq/frostarmor")->wear();
                carry_object(__DIR__"eq/frostboots")->wear();
                carry_object(__DIR__"eq/frostcloth")->wear();
                carry_object(__DIR__"eq/frosthands")->wear();
                carry_object(__DIR__"eq/frosthead")->wear();
                carry_object(__DIR__"eq/frostlegging")->wear();
                carry_object(__DIR__"eq/frostmask")->wear();
                carry_object(__DIR__"eq/frostneck")->wear();
                  carry_object(__DIR__"wp/break-hell-claw")->wield();
        carry_object("/daemon/spell/frost-obj/ice-puppet")->set("hp", 40000);
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
        object target;

        // non-fight
        if(!is_fighting()) return; 

        target = select_opponent();
        /* �Z���Q�����A�h�˦^�h */
        if( !query_temp("weapon") ) 
                command("wield fist");

        if(! target) return;

        if( target->is_busy() )
                command("cast thunder-doom");
        else 
                command("cast sevenfold-freeze");
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

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") != "�H����") return notify_fail("�o�ण�O�A�ӨӪ��a��C\n");
        if( me->query("class2") == "�H����") return notify_fail("�A�w�O�H�����̤l�F�C\n");
        if( me->query("adv_class") == 2 ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
        if(arg != "frost") return notify_fail("�A�n���J���@�Ӫ���?\n");

        if( me->query("level") < 25 
        || me->query_spell("fall-thunder") < 75
        || me->query_spell("freeze-ball") < 75
        || me->query_spell("life-death-symbol") < 50
        ) {
                command("shake");
                command("say �A�A�h�h�m�m�a");
        return 0;
        }

        command("say �n�n�n�I�I���@�A��W�׽m�]��@�w�{�פF�A�A�N�[�J�ڪ����U�a�C");
        command("smile "+me->query("id"));
        me->set("adv_class",2);
        me->set("class2","�H����");
        me->create_family("�H����", 2,"�D�H");
        me->set("guild_rank","�H�����ĤG�N�D�H");
        return 1;   
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();

        if( me->query("class2") != "�H����") return notify_fail("�o�̤��O�A�ӨӪ��a��C\n");
       //�s�ץ��Aadv level ���n�� (lv-20)^2
        j = me->query("popularity");
        if(j < 3 ) return notify_fail("�A���n�椣���C\n");
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("�A���n�椣���C\n");

        return GUILDMASTER->do_advance(ob,me,arg);
}

// advance  ���\�� GUILDMASTER�|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "�H����")
               return notify_fail("�A�ä��O�H�����̤l�C\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("�ݨӶ����l�ä��Q�ЧA��`�@�h�C(���D�A��"+cost+"�I�n��)\n");

        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}

int do_spell_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "�H����")
               return notify_fail("�A�ä��O�H�����̤l�C\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("�ݨӶ����l�ä��Q�ЧA��`�@�h�C(���D�A��"+cost+"�I�n��)\n");

        return  GUILDMASTER->do_spell_train(ob,me,arg);
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_spell_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
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
                        case 3: rank = "�H�������ФƦ��P"; break;
                        case 4: rank = "�H�������\\�P�ѦX"; break;
                        case 5: rank = "�H�������P���D��"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "�H�����ĤT�N�D��"; break;
                        case 1: rank = "�H�����ĤT�N�D�h"; break;
                        case 2: rank = "�H�������H�߫��D"; break;
                        case 3: rank = "�H�������ФƦ��P"; break;
                        case 4: rank = "�H�������\\�P�ѦX"; break;
                        case 5: rank = "�H�������P���D��"; break;
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
                HIG"\n�i�D�������j"HIM"�P���D�����H�����l���u�����l�v�u�H���Ѧb" +ob->name(1)+"����W�F�I�I\n"+NOR,users());
        ob->add("popularity", 3); //�n��
          if( objectp(present("ice-puppet", this_object() ))) destruct(present("ice-puppet", this_object() ) );
        tell_object(ob,HIW"(�A�o��F3�I�n��C)"NOR);
        ::die();
        return;
}


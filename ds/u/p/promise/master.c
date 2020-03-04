#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�W�x�ٶ�",({"master shang-guan","shang-guan","master"}));
         set("long" ,@LONG
    �W�x�a�ڪ�˳˳�̡A�W�x�E�����S�A�֦~�N�H�Ѩ��C�k�B�P
�����B�߳Z���Q�n�Z�L�A�P�a�կP�B�d��æC�T�j���̤��@����
�̡A���~�ѫṽ�¦��򪺬O�D���H�ơA�ҥH�ްh��W�x���a�F�n
��A�۳иU�P���A���~�ۤѹp�s���A���ަ��򮦫�C
LONG
        );

        set("nickname", HIY"�ѿA�t�H"NOR );
        set("attitude", "friendly"); 
        set("age", 55);
        set("gender","�k��");
        set("combat_exp", 120000);
        set("level", 55);
        set("title",HIY "�U�P���}�Э��H" NOR );
        set("max_ap",4000);
        set("max_hp",30000);
        set("class1","�U�P��");
        set("flurrydodge",1);
        create_family("�U�P��",10,"�}�Э��H");
        set_temp("apply/armor",40);
        set_skill("fogseven",85);
        set_temp("sorgitimes",10);
        set_skill("unarmed", 80);

        set_skill("sword",90);
        set_skill("moon_force",50);
        set_skill("dodge", 80);
        set_skill("force", 70);
        set_skill("parry", 100);
        set_skill("sorgi_sword",80);
        map_skill("sword","sorgi_sword");
        map_skill("dodge","fogseven");
        set("guild_gifts",({ 4,6,4,6 }));
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "parry" : ({ 110,3,80 }),
  "unarmed":({ 130,2,60 }),
  "sorgi_sword" : ({ 150,3,80 }),
  "moon_force" : ({ 175,4,85 }),
  "force" : ({ 135,3,85 }),
  "sword" : ({ 100,3,80 }),
  "fogseven" : ({ 140,3,80 }),
]));
        set("no_check_class",1);
        set("adv_class",1);
        set("chat_chance",8);
        set_temp("class_wind/power",200);

        set("chat_msg", ({
    (:command("sigh"):),
  (:command("exert moon_force recover"):),
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command,"exert sorgi_sword":),
  (:command,"exert sorgi_sword":),
  (:command("exert moon_force moon-arc"):),
}));

        //set("inquiry/�p�g","�L�N�O�ڨ�l�A������ƶܡH\n");
        setup();
        //carry_object(__DIR__"wp/shangsword")->wield();
        //carry_object(__DIR__"eq/sandal")->wear();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");

        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        
        if( arg=="moon_force" )
        {
                if( this_player()->query_skill( "moon_force", 1 ) == 0 )
                return notify_fail("�A�èS���ݤ�ߪk��¦�A�]���L�k�׽m�C\n");
        }
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
        object ob=this_object() , me=this_player();

        string gender;

        if( !arg && !me->query_temp("join_f") )
                return notify_fail("�аݭn�[�J��������H\n");
        if( me->query_temp("join_f") && !arg ) arg = "�U�P��";
        if( strsrch(arg, "�U�P��") == -1 || strsrch(arg, "��") > -1)
                return notify_fail("�аݭn�[�J��������H\n");
        if( me->query("gender") == "�k�m" ) gender="�k�L";
        else gender = "��?";
    message_vision("$N�Q�[�J"HIY"�U�P���C\n"NOR,me); 

        if( me->query("class1") )
                return notify_fail("�A�w�O"+me->query("class1")+"�̪��M�ȤF�C\n");
        if( me->query("family/family_name")=="�U�P��" )
                return notify_fail("�A�w�O�U�P�����M�ȤF�C\n");
                command("cong "+me->query("id"));
                message("world:world1:vision",
        HIG "\n\t�W�x�ٶ����D  "HIW+me->name(1)+HIY""HIG"�[�J�ڸU�P���A�ЦU��^���n�~�h�h���U�I�I\n"NOR
        ,users() );

                message_vision("$N�����U�P�����̤l�A�l�H�W�x�ٶ����@���C\n",me);
                
                me->set("class1","�U�P��");
                me->create_family("�U�P��",4,"�M��");
                me->set("adv_class",1);
                return 1;
        }
//      return 1;


int do_advance(string arg)
{
        if (this_player()->query("family/family_name")=="�U�P��") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        else return notify_fail("�A�ëD�U�P�����̤l�C\n");
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
                                // LV 1 ~ 9
                        case 0: rank = "�U�P���ĥ|�N�M��"; break;
                                // LV 10 ~ 19
                        case 1: rank = HIB"�U�P�M�Ⱦr���N��"NOR; break;
                                // LV 20 ~ 29
                        case 2: rank = HIC"�U�P�������y�M��"NOR; break;
                                // LV 30 ~ 39
                        case 3: rank = HIM"�M���H�M���H����"NOR; break;
                                // LV 40 ~ 49
                        case 4: rank = HIG"�a��M���Ƥ@����"NOR; break;
                                // LV 50
                        default: rank = HIW "�U�P�ǩ_�M������" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "�U�P���ĥ|�N�M��"; break;
                                // LV 10 ~ 19
                        case 1: rank = HIB"�U�P�k�M�H�ߩұ�"NOR; break;
                                // LV 20 ~ 29
                        case 2: rank = HIC"�U�P�k?�j���ѤU"NOR; break;
                                // LV 30 ~ 39

                        case 3: rank = HIM"�ߤM�è�U�P�X�@"NOR; break;
                                // LV 40 ~ 49
                        case 4: rank = HIG"�M�U�`��ƥH�U�p"NOR; break;
                                // LV 50
                        default: rank = HIY "�U�P�ǩ_�M������" NOR;
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
HIW"\n�i�Z�L�ǻD�j"HIY"�U�P���}�Э��H "NOR"�W�x�ٶ� "HIG"�Q�Z�L�s�_�դO "HIC+ob->name(1)+NOR" "HIG"�����F�I�I\n\n"+NOR
        ,users());

        ob->add("popularity", 3); 
        ::die();
        //destruct(this_object());
        return;
}


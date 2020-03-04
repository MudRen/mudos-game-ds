#include <ansi.h>
inherit NPC;

    void heal_ap();
string book(object me);

string *to_say = ({
  GRN"�a�կP���R�u�O�����D�n���P�E�L�̴X��....\n"NOR,
  "",
  GRN"�a�կP���R�����D�L�̲{�b�L���i�w�n�H�\\�[�S�h���L�̤F... \n"NOR,
  GRN"�a�կP���R�����p�U�l��.. �ڤw�Ǳµ����ϤF, �p�G�A�n����, �N�h�䥪�ϧa�I\n"NOR,
});

string *msg_dunno = ({
        "�Sť���L�C\n",
        "�L�i�^�i�C\n",
        "��....�o�ڥi���M���M�A�̦n�ݰݧO�H�a�C\n",
        "�藍�_�M�A�ݪ��Ƨڹ�b�S���L�H�C\n"
});

void create()
{
        set_name(HIY"�a�կP"NOR, ({"shiuan yuan lieh master","lieh","yuan lieh","shiuan", "master"}) );
        set("long",@LONG
    �o�ӥ����������~�H�N�O�e�������}�s���v�u�a�կP�v�A�L�q
�p�ɭԴN�m�N�F�@���w�����\�Ҧۥ��K���Z�����١A�b�@�������M��
�J���A���t�ХL�|�A�Z�\�ѥ~�Ӥ��A���\�����j�i�A�b���򤤻P�Ѥ�
���x��  �N�b�ú٪Z�L�⵴�A�L�b�®x�w�ĩR�\�[�A�~�w�ӥߡA�ثe
�x��j�λ�A�b�L 25 �����~�b�a�m�ХߤF�e�����C
LONG);
        set("level",60);
        set("evil",-20-random(50));
        set("combat_exp",59000);
        set("age",80);
	set("race","evil");

        set("chat_chance",8);
        set("chat_msg",({
  (: command("say �̪�@�Ưu�h��") :),
  (: command("say �Ѧ���\\�A�a���ѽL") :),
  (: command("say ���n���~�B�A�����Q�N��") :),
  (: command("exert moon_force recover") :),
}));
        set_temp("class_wind/power",300);
    set("max_ap",6000);
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                  (: command("do wield sword,exert moon_force long-arc"):),
                  (: command("exert moon_force recover"):),
                    (: heal_ap :),
                    (: command("do wield sword,exert sorsin_force one") :),
                      (: command("do wield sword,exert sorsin_force two") :),
                    (: command("do wield sword,exert sorsin_force three") :),
                    (: command("do wield sword,exert sorsin_force final") :),
                  (: command("do wield sword,exert star-sword rain") :),
                  (: command("do wield sword,exert star-sword rain") :),
                  (: command("do wield sword,exert star-sword vigor") :),
                  (: command("do wield sword,exert star-sword vigor") :),
                  (: command("do wield sword,exert star-sword brightly_heart") :),
}));

        set("class1","�e����");
        set("class2", "�e����");
        set("adv_class", 2);
        set("title","�e�����ФH");
        set("nickname",HIR"�Z��"NOR);
        set("can_defend", 1); // by alick

// -- guild
// ========================================================================
//      �ɮv���ݩʤ��t��(�v��) �� more /doc/wiz/�ݩʻP����.txt
//      �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
//      �ӥB�|�����`�M�n��n���� 20
// ========================================================================
//            set("guild_gifts",({ 4,6,4,6 }));
            set("guild_gifts",({ 5,7,0,8 }));
// ========================================================================
//      �u�|�ɮv�i�H�бª��ޯ�C��
// ========================================================================
        set("guild_skills",([   // ����, ����1 �i�Ǩ쪺�ޯ൥�ŭ��v, �W��
    "star-sword" : ({ 150, 4, 80 }),
    "moon_force" : ({ 175, 4, 80 }),
    "force" : ({ 175, 4, 80 }),


]));
// -- guild

        set("flurrydodge",1);

        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("combat",100);
        set_skill("sorgi_sword",100);
    set_skill("sorsin_force",100);
         set_skill("constant-virtue",50);
        set_skill("force", 100);
        set_skill("moon_force",100);
        set_skill("fogseven",100);

    set_skill("star-sword",100);
    map_skill("sword","star-sword");
        map_skill("dodge","fogseven");

        set("inquiry", ([
  "�p�U�l" : (: book :),
  "�U�l" : (: book :),
]));


        setup();

        carry_object(__DIR__"wp/sevenstar")->wield();
        carry_object(__DIR__"eq/flurryneck.c")->wear();
        carry_object(__DIR__"eq/hookgloves")->wear();
        carry_object(__DIR__"eq/incrystate")->wear();
}

void init()
{
        object me = this_player(), ob = this_object();
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_say", "say");

        if( me->query_temp("find_lieh") )
        {
                me->delete_temp("find_lieh");
                me->set_temp("meet_lieh",1);
                call_out("find_lieh",2,me,ob);
        }
}

void heal_ap()
{
    object me=this_object();
     message_vision(HIY"�a�կP"HIW"�V�W�@�D�A�y�b�Ť��A�l�ޤj�a����l\n"NOR,me,this_player());
    me->receive_heal("ap",1000);
    return;
}
void find_lieh(object me,object ob)
{
        message_vision("$N�ݨ��F$n�A�N�N�������ϴM��$n���Ƨi���C\n",me,ob);
        command("sigh");
        command("say "+RANK_D->query_respect(me)+"�ЧA��i�L���ڦb��餧���|�^�h�C");
        command("thank "+me->query("id"));
        return;
}

string book(object me)
{
        me = this_player();
        if( me->query_temp("book") )
                return "�����p�U�l�H.... �O�X�~�e�X�찪�H���ڪ��ܡH\n";
        else return msg_dunno[random(sizeof(msg_dunno))];
}

int do_say(string arg)
{
        object me = this_player();
        if( arg == "�O" && me->query_temp("book") )
        {
                message_vision(YEL"$N���R"+arg+"\n"NOR, me);
                me->set_temp("get_book", 1);
                call_out("delay", 2, me, 0);
                return 1;
        }
        return 0;
}

void delay(object me, int flag)
{
        message_vision(to_say[flag], this_object());
        if( ++flag < sizeof(to_say) )
        {
                call_out("delay", 1, me, flag );
                return;
        } 
        tell_object(me, HIC" ����o, �A���D�A���ӥh��֭n�U�l�F�I \n"NOR);
        return;
}

void delay2(object me, object ob)
{
        message_vision(GRN"�a�կP���R�o..�o...���O���ڦb�s�W�ҥΪ�����۶ܡH\n"NOR, ob);
        message_vision(GRN"�a�կP�򴤵�$N���⻡�G���§A�F, "+ RANK_D->query_respect(this_player()) + ", �J�M�A���F�ڳo�Ӧ�, �ڴN���A���{�a�I\n"NOR, me, ob);
        return;
}

void delay3(object me)
{
        message_vision(GRN"�a�կP���R�o..�o...���O���ڦb�s�W�ҥΪ�����۶ܡH\n"NOR, me);
        message_vision(GRN"�a�կP�򴤵�$N���⻡�G���§A�F, "+ RANK_D->query_respect(this_player()) + ", �J�M�A���F�ڳo�Ӧ�, �ڴN�e�o�Ӥp§���A�a�I\n"NOR, me);
        return;
}

int accept_object(object me, object ob)
{
        object stone;
        if( !ob->id("open-war-stone") ) return 0;
        if( !userp(me) ) return notify_fail("�a�կP�������t������F��C\n");
        else if( me->query("class1") == "�e����" && me->query("level") == 25 && !me->query("class2") && me->query_temp("got_stone") )
        {
                me->delete_temp("got_stone");
                me->set("class2", "�e����");
                me->create_family("�e�����i��", 3, "�C�h");
                me->set("guild_rank", WHT"�g�~���m���s�C�h"NOR);
                message_vision("$N��$n�@" + ob->query("unit") + ob->name() + "�C\n", me, this_object());
                me->set("adv_class", 2);
                me->set("guild_gifts",({ 4,6,5,5 }));
                message("world:world1:vision", WHT"�W�Ťp���G"HIR" [ " + me->name(1) + " �����F�a�կP���U�������C�h�F�I ] \n"NOR, users());
//                 write_file("/u/c/cominging/log/wind_adv.log" , sprintf("%s became the member of advenced wind party at %s\n", geteuid(me), ctime(time())));
                call_out("delay2", 1, me, ob);
                return 1;
        }
        else
        {
                message_vision("$N��$n�@" + ob->query("unit") + ob->name() + "�C\n", me, this_object());
        }

        stone = new(__DIR__"obj/heal_stone.c");

          if( stone->violate_unique() || me->query_temp("get_heal_stone")) //add by whoami 07/03/17
        {
            me->add("exp", 3000);
            tell_object(me, "�A�o��F 3000 �I�g��C\n");
            destruct(ob);
            destruct(stone);
            return 1;
        }
        
        stone->move(me);
        destruct(ob);
        message_vision("$N��$n�@" + stone->query("unit") + stone->name() + "�C\n", this_object(), me);
        me->set_temp("get_heal_stone", 1);
        this_object()->set("give_heal_stone", 1);
        call_out("delay3", 1, me);
        return 1;
}





int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
          int temp;
        if( this_player()->query("class2") != "�e����" )
                return notify_fail("�A���O�e���i���C�h�I\n");
        if( arg=="moon_force" )
        {
                if( this_player()->query_skill( "moon_force", 1 ) == 0 )
                return notify_fail("�A�èS���ݤ�ߪk��¦�A�]���L�k�׽m�C\n");
        }
         temp = 3 + this_player()->query_skill(arg) / 30;
         if( this_player()->query("popularity") < temp )
                return notify_fail("�A�S���������n��C\n");

        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

void train_skill_cost(object me, string skill)
{
         int temp = 3 + me->query_skill(skill)/30;

        me->add("popularity",-temp);
        return;
}

int do_advance(string arg)
{
        object me = this_player();
        int pop = me->query("popularity"), lev = me->query("level") - 21;

        if( me->query("class2") != "�e����" )
                return notify_fail("�A���O�e���i���C�h�I\n");
        if( (( !arg || arg == "level" ) && pop < (lev*lev+1)) || ( pop < 3 ) )
                return notify_fail("�A���n�椣���ΥH�ɯšI\n");
        
        return GUILDMASTER->do_advance(this_object(), me, arg);
}

// advance ���\�� GUILDMASTER �|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost = ( me->query("level")-21 ) * ( me->query("level") - 21 );

        if( !arg || arg=="level" )
                me->add("popularity",-cost );
        else if( me->query("popularity") < 3 )
                me->set("popularity",0 );  
        else me->add("popularity",-3);
        me->save();
        return;
}

string guild_rank(object me)
{
        string rank;
        int lv, force, sword;
        force = me->query_skill("force", 2);
        sword = me->query_skill("star-sword", 1);
        lv = ( me->query("level") - 25 ) / 6;

        if ( sword > 80 && force > 99 && force > sword ) rank = HIW"�C�N���W�����\\�v"NOR;
    else if ( force > 80 && sword > 99 && sword > force ) rank = HIW"���O���p���C�N�h"NOR;
        else if ( force > 99 && sword > 99 ) rank = HIC"�n�p�y��"HIW"����C�h"NOR;
        else if ( force > 70 ) rank = WHT"���\\�������e���H"NOR;
        else
        {       switch( lv )
                {
                        case 0: rank = WHT"�g�~���m���s�C�h"NOR; break;
                        case 1: rank = WHT"�ᦳ�W�𪺤p�C�h"NOR; break;
                        case 2: rank = WHT"�\\�O���Z���C�N�v"NOR; break;
                        case 3: rank = WHT"�e�������X�v���{"NOR; break;
                        case 4: rank = HIW"�a��ѤU�@�N�C�h"NOR; break;
                        default: rank = WHT"�e���i���d��ʷ�"NOR;
                }
        }
        return rank;
}

void die()
{
        object ob,key;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", WHT"\n �W�Ťp���G [ �ǻD"HIW"�e�������D "HIY"�a�կP "NOR WHT"�b "HIR + ob->name(1) + " "NOR WHT"����U�A�`�U�F�R�����̫�@�f��C ] \n\n"NOR, users());
        ob->add("popularity", 7); //�n��
        "/open/world1/cominging/area/boo-lin"->open_moon(); // �s������
      key=new("/open/world1/tmr/bagi/npc/wood-key")->move(this_object());
        ::die();
        return;
}

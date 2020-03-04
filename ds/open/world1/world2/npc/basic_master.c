#include <ansi.h>

inherit NPC;
//inherit GUILDMASTER;    // �s����GUILDMASTER �i�H�����~��

void create()
{
	set_name("�ȧJ", ({"master ark","master","ark"}) );
    set("gender", "�k��");
    set("combat_exp", 100000);
    set("long",
    "�L�O�Ѧ�s�⪺���ɱЮv�A���Ѱ򥻪��ޥ��V�m�C�A�i�H\n"
    "�ϥ�"HIY"list"NOR"�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)�C�]�i\n"
    "�H��advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ���ϥ�\n"
    "level ���O�Ӭd�\\�һݭn���g��ȡC\n"
    );
	set("title","�h��i��");
	set("race","human");
	set("no_join", 1);
	set("level", 62);
	set("age", 50);
        set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set("guild_skills", ([  // // ����, ����1�i�Ǫ��W��, �W��
		"unarmed":({70,5,99}),
		"blade":({70,5,99}),
		"sword":({70,5,99}),
		"whip":({70,5,99}),
		"axe":({70,5,99}),
		"dagger":({70,5,99}),
		"fork":({70,5,99}),
		"staff":({70,5,99}),
		"hammer":({70,5,99}),
		"dodge":({70,5,99}),
		"parry":({70,5,99}),
	]) );
	set("chat_chance", 5);
/*  set("chat_msg", ({
    "�s��ɮv�w�w���D:"HIC"�w��U��ɪŮȦ�̦b�o�̾ǲߡC"NOR"\n",
	"�s��ɮv�w�w���b�ж��̺C�C�����ۡC\n",
    }) ); */
	set("inquiry/master", "�A�i�H�Q�ξɮv(master)�Ӿǲ�(train or learn)�ޯ�P�k�N�C\n");
	setup();

  carry_object(__DIR__"../wp/iron_staff_10")->wield();
  carry_object(__DIR__"../eq/leather_boots_8")->wear();
  carry_object(__DIR__"../eq/iron_armor_18")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("d_advance","advance");
        add_action("d_list","list");
        add_action("d_train","train");
}

int d_advance(string arg)
{
 if(this_player()->query("race")!="human") return notify_fail("�u���H��(human)�~�ݭn�a���v�����C\n");
 return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int d_list(string arg)
{
 return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int d_train(string arg)
{
 if(this_player()->query("race")!="human") return notify_fail("�u���H��(human)�~�ݭn�a���v�����C\n");
 if(this_player()->query("class1") || this_player()->query("class2") ) 
   if(this_player()->query("class1")!="adventurer")
     return notify_fail(this_object()->name()+"��: �ܩ�p�A�ڥu���ɩ|���[�J¾�~�������s�i�_�I�̡C\n");
 return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) )
        {
                case 0:
			say(this_object()->name()+"��:"HIC"�w��U��_�I�̦b���ǲ߰򥻪��ޥ��C"NOR"\n");
                        break;
                case 1:
                        say(this_object()->name()+"�D:"HIY"ù���i���O�@�ѳy�����C"NOR"\n");
                        break;
                default:
                	break;
        }
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/5;     

        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                        case 0: rank = "�L�a�i�k���y���~"; break;
                        case 1: rank = "�|�B�y�����_�I��"; break;
                        case 2: rank = "����ѲP���_�I��"; break;
                        case 3: rank = "���o�@�����_�I�a"; break;
                        case 4: rank = "���i��ĳ���W�i��"; break;
                        default: rank = HIC "�ڤۯ몺�j�_�I��" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "�����i�����p���Y"; break;
                        case 1: rank = "�����a�A���p�h�Q"; break;
                        case 2: rank = "���O�|�g���k�i��"; break;
                        case 3: rank = "���o�@�����k�i�h"; break;
                        case 4: rank = "���i��ĳ���k�i��"; break;
                        default: rank = HIC "�ڤۯ몺�k�_�I��" NOR;
                }

        }
        return rank;
}


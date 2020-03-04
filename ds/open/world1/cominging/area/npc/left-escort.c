#include <ansi.h>
inherit NPC;

string book(object me);
string *msg = ({
  "����l���R�����p�U�l, �ک�b�|�j�٪��s���p�٥h�F, �A�h���ݧa�I\n",
});

void create()
{
	set_name(WHT"����l"NOR,({ "left-escort you","you","left-escort","left","escort" }));
	set("long" ,@LONG
    �L�O�e�������������ϡA�b�e�����������Ŧ@�����šA���O�O
���D�A��D�A�@�ϡA��D�A�̤l������A�e�������������k�ϤD�O
�M�����H�l�̡A�ӯe�������������ϫh�O�ǱªZ�\���ΡA����l�q
�p�N�J�F�e�����A�L�p�ɭԤ������`�A�b�@�������M���J���A�J�W
�F�e�������v�ݰa�կP�A�]�ӫ��䬰���R�A�a�կP�b��ӧ릥�q�x
�ɩe���L���������ϡA�L���H�p�D�A�ҥH�`���P�������A���L���@
���m���C
LONG
	);
	set("nickname","�p���۹�");
	set("attitude","friendly");
	set("age", 20+random(10));
	set_temp("sorgitimes",12);
	set("level", 42);

	set("gender","�k��");
	set("max_ap",3500);
	set("race","�H��");

	set("combat_exp", 49000+random(4500));

	set("title",HIY"�e����"HIM"��������"NOR);

	set("class1","�e����");
	set("flurrydodge",1);
	create_family("�e����",10,"��������");

	set_skill("sword", 90);
	set_skill("dodge", 95);
	set_skill("force", 100);
	set_skill("parry", 80);
	set_skill("sorgi_sword",85);
	set_skill("fogseven",100);
	set_skill("moon_force",100);

	map_skill("sword","sorgi_sword");
	map_skill("dodge","fogseven");

	set("chat_chance",8);
	set("chat_msg", ({
  (: command("sigh") :),
  (: command(":)") : ),
  (: command("exert moon_force recover"):),
}));
    set_temp("class_wind/power",250);
    set("chat_chance_combat",100);
	set("chat_msg_combat",({
  (: command,"exert sorgi_sword" :),
  (: command,"exert moon_force moon_arc" :),
  (: command,"wield sword" :),
  (: command,"exert moon_force recover" :),
}));

	set("inquiry",([
  "name" : "�کm��A�W���l�C\n",
  "moon_force" : "�ݤ�ߪk�O�گe�����U���ѩҦ@�P�гy�X�Ӥ��~�A
�p�S�̭Y���߾ǲߡA�i�H�V�ڸ߰�(enquire)�C\n",
  "�p�U�l" : (: book :),
  "�U�l" : (: book :),
]));
	setup();
	carry_object(__DIR__"wp/oldsword")->wield();
	carry_object(__DIR__"eq/flurryneck")->wear();
	carry_object(__DIR__"eq/flyboots")->wear();
}

void init()
{
	object me, ob;
	ob = this_object();
	me = this_player();
	if( me->query_temp("meet_lieh" ) && me->query("level") > 9 )
	{
		me->delete_temp("meet_lieh");
		message_vision(HIY"$N�@�r�@�r���C�C�i�D$n�e�������D���U���C\n"NOR,me,ob);
		message_vision("$Nť��$n���i����A��$n���D�G\n",ob,me);
		message_vision("  "+RANK_D->query_respect(me)+"�ڲ{�b�N�e�������ݤ뤺�\\�f�Z�б»P�A�A�n�J��ť�n�F�I\n"NOR,me);
		message("sound", HIG""+ob->name()+"�N�e�����ݤ�ߪk���n�Z�i�D�F"+me->name()+"�C\n\n"NOR,environment(me), me);
		write("�� "+ob->name()+"�N�e�������ݤ�ߪk�f�Z�Ǳ»P�A�C ��\n");
		me->improve_skill("moon_force", 10);
	}
	else if( me->query_temp("meet_lieh" ) && me->query("level") < 10 )
	{
		me->delete_temp("meet_lieh");
		message_vision(HIY"$N�@�r�@�r���C�C�i�D$n�e�������D���U���C\n"NOR,me,ob);
		command("thank "+me->query("id"));
		tell_object(me,this_object()->name()+"�i�D�A: �A�{�b��¦�����٤���, �٤���⮩��ݤ�ߪk���u�q�C\n");
	}
	add_action("do_enquire","enquire");
}

int do_enquire(string arg)
{
	object ob,me;
	ob = this_object();
	me = this_player();
	if( !me )return 0;
	if( me->query("class1")!="�e����" )return notify_fail("�A���O�e�������l�̡C\n");
	if( arg!="you" && arg!="left-escort" && arg!="left-escort you" )
		return notify_fail("�A�n�߰ݽ֤���F��H\n");
	if( me->query_skill("moon_force") > 0 )
		return notify_fail("�A�w�g�ǹL�ݤ�ߪk�C\n");
	else
	{
		message_vision("$N���G�Y"+RANK_D->query_respect(me)+"������������D�a�կP�j���ثe���p�A�w����n�۱©ҾǡC\n",ob);
		command("bow "+me->query("id"));
		me->set_temp("find_lieh",1);
		return 1;
	}
}

string book(object me)
{
	me = this_player();
	if( !me->query_temp("get_book") )
		return "����p�U�l�H�ڤ����D��... \n";
	if( me->query_temp("get_book") )
	{
		call_out("delay", 2, me, 0);
		return "�O�a�դj���s�A�Ӹ�ڭn���ܡH\n";
	}
}

void delay(object me, int flag)
{
	message_vision(msg[flag], this_object());
	if( ++flag < sizeof(msg) )
	{
		call_out("delay", 1, me, flag );
		return;
	} 
	tell_object(me, HIC" ����o, �A���D�A�i�H�h����U�l�F�I \n"NOR);
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
CYN"\n  �Z�L�ǥX�F�@�h����:\n\n\t�@�u�p���۹ҡv����l�ѵ��F"+ob->name(1)+"�C\n\n"+NOR
        ,users());
        ob->add("popularity", 2); 
        ::die();
        return;
}

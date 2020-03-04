#include <ansi.h>

inherit NPC;
inherit SELLMAN;

string *list = ({
	"/open/always/game_gift/mask.c",
	"/open/always/game_gift/necklace.c",
	"/open/always/game_gift/skirt.c",
        "/open/world1/alickyuen/zong/bag.c",
});

void create()
{
	set_name(HIY"���A�l"NOR, ({"zong seller", "seller"}));
        set("gender", "�k��" );
        set("age", 22);
        set("long","�@�Ӧ~�W�X�j�����l�A�l�A�L���X�ۺݤȸ`���l�ȿ��C\n�A�i��plist�Bzlist��zbuy�o�T�ӫ��O�C\n");
	set("level",1);
        set("attitude", "friendly");
        set("nickname", HIW"�H�H����, �����|Ĺ�o"HIY"���]"NOR HIW"�@�ӳ� ~"NOR);
        set("rank_info/respect", "�p�G��");
	set("sell_list",([
                __DIR__"bean" : 30,
                __DIR__"meat" : 30,
        ]) );
	set("chat_chance",10);
	set("chat_msg", ({
                (:command,"say �R��l�ܡH��ڧa��zlist �M zbuy��":),
                (:command,"wink":),
                (:command,"say �֨ӶR��� ! ���w�]������ ~ �٥i�H�����! ":),
	}));
        set("no_kill", 1);
        set("no_fight", 1);
        setup();
}
void init()
{       
//        object ob;

        ::init();
/*
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
*/
        add_action("do_list","zlist");
        add_action("do_buy","zbuy");
	add_action("list_price", "plist");
}

void greeting()
{
	command("say �֨ӶR��աI���w�]��������~�梴���������@�ӡD�٥i�H�����I�I�I");
	return;
}

int list_price()
{
	string msg;

        msg = HIC"2008 �~�׺ݤȸ`�j��������~�p�U�G\n"NOR+
		HIW"�ססססססססססססססססססססססססססססס�\n"NOR+
                HIG"\t�j���G�H��SAVE EQ�@��C\n"NOR+
		HIW"�ססססססססססססססססססססססססססססס�\n"NOR;

	this_player()->start_more(msg);

	return 1;
}

int accept_object(object me,object ob)
{
	object price;
	int lucky;

        lucky = random(5000);

        if( ob->query("id") !="zong ticket" )
		return notify_fail("���A�l��:�ڤ��n�A�o��F�F�C\n");

	if( this_object()->is_busy() ) 
                return notify_fail(this_object()->query("name")+"���D:�ѮQ�n�ְ�,������.\n");

	this_object()->add_temp("waiting", 1);
	if( this_object()->query_temp("waiting") >= 10 )
	{
                this_object()->start_busy(3);
		this_object()->delete_temp("waiting", 1);
	}

	call_out( (:destruct($1):), 1, ob);

	switch(lucky)
	{
		case 50:
                        price = new(list[random(sizeof(list))]);
			price->move(me);
                        command("shout ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�j���A�o��SAVE EQ�@��I");
			                                log_file( "static/gamea",sprintf("[%s] %s(%s) get %s[%s]\n",ctime(time()),me->name(1),getuid(me),price->name(1),base_name(price))); 
			return 1;
		break;
/*
                case 20..22:
			me->add("exp", 1000000);
			command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�G���A�o��1000000 exp�I");
			return 1;
		break;
                case 30..35:
			me->add("popularity", 10);
			command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�T���A��o10�I�n��I");
			return 1;
		break;
		case 60..70:
			new(__DIR__"meat")->move(me);
			command("say ���ߡA�A���@����C");
			return 1;
		break;
		case 71..80:
			new(__DIR__"bean")->move(me);
			command("say ���ߡA�A���@����C");
			return 1;
		break;
*/
		default:
			command("say �u�i���A�A����F��]�S�⤤�C");
			return 1;
		break;
	}
	return 1;
}

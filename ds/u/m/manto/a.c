#include <ansi.h>

inherit NPC;

string where ="";

mapping areas= ([
	"/open/world1/acme/area/" : "�ѫ�",
        "/open/world1/acme/bonze/" : "�ⶳ�x",
        "/open/world1/acme/cominging/" : "�ѫ��j�c",
        "/open/world1/cominging/purple_sun/" : "�����s",
//        "/open/world1/ground_temple/" : "�a�U����",
        "/open/world1/moonhide/area/" : "�Ѭ�",
        "/open/world1/tmr/area/" : "�ɿ�",
        "/open/world1/tmr/ghost-forest/" : "���_�˪L",
        "/open/world1/wilfred/meadow/" : "�������",
        "/open/world1/wu_sha_town/" : "�L�F��",
	"/open/world1/kkeenn/love/" : "������",
          "/open/world1/tmr/dragoncity/" : "�Y�s��",
          "/open/world1/tmr/frost/" : "�ʾ]�s",
]);

int restart();
string eq_check();

void create()
{
	set_name("�_�îa", ({ "rich man", "man" }) );
	set("level", 1);
	set("long", @long
�o�@�ӤH���W���O�W�Q���A���A���ӫD�`�I�ΡA���y�W�o�S�X�@��
�L�`�����A����������Ʀӷдo�����C
long);
	set("str", 100);
	set("can_speak", 1);
	set("no_kill", 1);
	set("inquiry/�˳�", (: eq_check :) );
	setup();
	set_living_name("phoenix_asker");
}

int talk_action(object me)
{
	object living;
	string msg;

	living = find_living("phoenix");

	if( living ) 
	{
		if( environment(living) ) return 0;
	}

        if( me->query("level") < 31 && !wizardp(me) ) return 0;

	if( !me->query_temp("quest/phoenix") )
	{
	command("whisper "+me->query("id")+" �ڦb�M��@�˦W�s[��Ĥ���(Plume of phoenix)]���F��");
	command("whisper "+me->query("id")+" �ڬO�q�䤤�@�T���_�Ϥ��o�{��,�o�جöQ���F��u���b��Ĩ��W�~���..");
	command("whisper "+me->query("id")+" ���I���Ī���k�O����b�j�N�U�B���@�C�Ӧ�[��]���Ϯת��]���]..");
	command("whisper "+me->query("id")+" ���_�ϤW�����j����m����...�����٬O�䤣��");
	command("whisper "+me->query("id")+" �A������ڳo�Ӥj���ܡH(�Y���ڪ��ܡA�ЦA�����talk)");
	me->set_temp("quest/phoenix", 1);
	}
	else {
		msg = "";
		restart();
		restart();
		restart();
		restart();
		restart();
		restart();
		restart();
		if( sizeof(filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) )) )
		{
			foreach(object pearl in filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) ) )
			{
				object room;
				room = environment(pearl);
				if( room->is_room() ) msg += room->query("short")+", ";
				else if( userp(room) ) msg += room->name()+"(���a), ";
				else msg += room->name()+", ";
			}
		}
		command("whisper "+me->query("id")+" ��,���¹L��,�Ʊ�A�බ�Q��o�Ф�a�^�ӵ���:Q ");
                command("whisper "+me->query("id")+" �ھڦa�ϤW���,�o�C�ө]���]���ӬO�b "+where+" �o�X�Ӱϰ줧��");
		command("whisper "+me->query("id")+" ���{�bť���b "+msg+" �o�X�ӤH�Φa�I���X�{�L~~");
	}
	return 1;
}

int accept_object(object me, object ob)
{
        if( ob->query("id") != "plume of phoenix" || !me->query_temp("quest/phoenix") )
		return notify_fail(this_object()->name()+"��:�ڤ��n�A�o��F��C\n");

	if( this_object()->is_busy() ) 
		return notify_fail(this_object()->name()+"���b���ۡA�S�Ŧ^���A�C\n");

	message_vision("$N���F"+this_object()->name()+"�@��$n�C\n", me, ob);

        me->add_temp("quest/give_phoenix", 1);

	command("whisper "+me->query("id")+" �¹L�F,�A���S�h�X�Ӫ��Ф��?�ڥi�H���A�K�O�s�@�@��˳�:)");
	command("whisper "+me->query("id")+" �Q�n����,�A�ӧ�ڧa(ask me about �˳�)");

	call_out( (:destruct($1):), 1, ob);

	return 1;
}

int restart()
{
	string dir, *file, dest;
	object pearl;

	this_object()->set("pearl", sizeof(filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) )));

	if( this_object()->query("pearl") >= 7 ) 
		return 1;

	dir = keys(areas)[random(sizeof(keys(areas)))];
	file = get_dir(dir);
	dest = dir+file[random(sizeof(file))];

	if( !objectp(load_object(dest)) 
	|| !load_object(dest)->query("short")
	|| !load_object(dest)->query("exits")
	|| !load_object(dest)->is_room()
	) {
		return restart();
	}

	where += values(areas)[member_array(dir , keys(areas))]+",";
	pearl = new(__DIR__"pearl");
	pearl->move(dest);
	this_object()->add("pearl", 1);
	return 1;
}

string eq_check()
{
	object me = this_player();

	command("whisper "+me->query("id")+" �A�Y�{���{�b���Ф�ƶq�������ܴNanswer yes�a�A��M�V�h�Ф�A�˥X�Ӫ��˳ƴN�V�j�C\n");
        return "�A�{�b�@���F�� "+me->query_temp("quest/give_phoenix")+" �ڦФ�.";
}
void init()
{
	add_action("do_answer", "answer");
}

int do_answer(string arg)
{
    object me, leather;
    int temp;
    me = this_player();

    if( !me->query_temp("quest/phoenix") || !me->query_temp("quest/give_phoenix") )
        return 0;

    if( !arg || arg != "yes" ) return 0;

    leather = new(__DIR__"leather");
    leather->move(this_object());
    temp = me->query_temp("quest/give_phoenix");

    if( temp >= 25 )
                leather->add("armor_prop/armor", 25);
        else
                leather->add("armor_prop/armor", temp);

    if( temp >= 35 ) leather->add("armor_prop/int", 1);
    if( temp >= 45 ) leather->add("armor_prop/dex", 1);
    if( temp >= 55 ) leather->add("armor_prop/str", 1);
    if( temp >= 65 ) leather->add("armor_prop/con", 1);
    
    if( temp >= 256 )
    {   
        leather->set("armor_prop/sou", 1);
        leather->set("armor_prop/tec", 1);
        leather->set("armor_prop/bio", 1);
        leather->set("armor_prop/wit", 1);
        leather->set("armor_prop/bar", 1);
    }
     if( temp >= 512 )
    {
                leather->add("armor_prop/int", 2);
                leather->add("armor_prop/dex", 2);
                leather->add("armor_prop/str", 2);
                leather->add("armor_prop/con", 2);

                leather->set("armor_prop/bio", 2);
                leather->set("armor_prop/bar", 2);
                leather->set("armor_prop/wit", 2);
                leather->set("armor_prop/tec", 2);
                leather->set("armor_prop/sou", 2);
                leather->add("armor_prop/armor", -50);
        leather->set("wear_msg", HIR"$N��W$n"HIR"������ܦ��F������A���馳�o�Ͳ��ܪ����p�C\n"NOR);
    }
    
    command("give leather to "+me->query("id"));
    me->delete_temp("quest/phoenix");
    me->delete_temp("quest/give_phoenix");
    return 1;
}





void clean()
{
	remove_call_out("clean");
	where="";
	foreach(object pearl in filter_array( children("/open/world1/alickyuen/phoenix/pearl"), (: clonep :) ) )
	{
		pearl->gone();
	}
}

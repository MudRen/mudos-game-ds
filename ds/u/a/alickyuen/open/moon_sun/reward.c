/*	tree.c			*
 *	write by -alickyeun@ds-	*
 *	2002����`�C���O����	*/

#include <ansi2.h>

inherit ITEM;
inherit F_SAVE;

mapping game_record;

void create()
{
	set_name(HIY"��G�۾�"NOR, ({ "moon tree", "tree" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
	set("long", "");
	setup();
	if( !restore() )	game_record=([]);
}

string query_save_file()
{
	return DATA_DIR + "game/moon_sun";
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return;

	add_action("do_look", "look");
}

int do_record(object me)
{
	string id;

	if( !me || !userp(me) ) return 0;

	id = getuid(me);

	if( !restore() ) game_record=([]);
	if( !mapp(game_record) ) game_record=([]);

        if( !game_record[id] || game_record[id] < 5 ) return 0;
                else game_record[id] -= 5;
	this_object()->save();

	return 1;
}

int set_record(string arg)
{
	string who;
	int score;

	if( sscanf(arg, "%s to %d", who, score) != 2 )
		return notify_fail("���O�榡: set who to score�C\n");
	if( !restore() ) game_record=([]);
	game_record[who] = score;
	this_object()->save();
	write("ok�C\n");
	return 1;
}

int do_look(string arg)
{
	if( arg == "tree" || arg == "moon tree" )
	{
		write(BEEP+HIR"�Х�[reward]���O�h����C\n"NOR);
                return this_player()->start_more(this_object()->do_list());
	}
}

string do_list()
{
	float *score, swap;
	int i, j, x;
	string *ppl, msg, user;

	if( !restore() ) game_record=([]);
	if( !game_record )		return "�ȮɨS���H�W�]�C\n";
	if( !mapp(game_record) )	return "�ȮɨS���H�W�]�C\n";
	if( !sizeof(game_record) )	return "�ȮɨS���H�W�]�C\n";

	ppl=keys(game_record);
	score=values(game_record);
	i=sizeof(score);

	for(j=i-1;j>0;j--)
	{
		for(x=1;x<=j;x++)
		{
			if( score[x-1] > score[x] )
			{
				swap=score[x-1];
				score[x-1]=score[x];
				score[x]=swap;
				user=ppl[x-1];
				ppl[x-1]=ppl[x];
				ppl[x]=user;
			}
		}
	}

	i=sizeof(ppl);
	j=0;
	msg= HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	msg += HIG"\t\t����`���� -- �g�� �� �Ѿl�i������Ƭd��\n"NOR;
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;
	while( i-- )
	{
		j++;

		if( ppl[i]==getuid(this_player()) ) msg+= BLINK+HIC;
			else msg += CYN;

                if( game_record[ppl[i]] > 4 ) {
                        msg+=sprintf("��%4s�W ---- %13s �ثe�@�g�U�F %3d �ӤӶ�",
				chinese_number(j),ppl[i],game_record[ppl[i]]);

		switch( j )
		{
			case 1: msg+= HIR""BLINK" (�W�Ťj���G���g��M�θ˳Ƥ@��[save eq])\n"; break;
			case 2..5: msg+= HIM" (�j���G��������(secret mask)�@��[save eq])\n"; break;
                        default: msg+= HIW" (�ѥ[���G�i�H�󬡰ʵ�����ѻP���[�C5���@��]�A�����|���save eq�@��)\n"; break;
		}
		}
		msg+=NOR;
	}
	msg+=HIW"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"NOR;

	return msg;
}

int do_climb(string arg)
{
	object me = this_player();

	if( arg != "tree" && arg != "moon tree" ) return 0;

	if( me->is_busy() || me->is_block() )
		return notify_fail("�A���b�����I\n");

	message_vision("$N�C�C�a��$n�W���F�W�h�C\n",me ,this_object());
	me->move(__DIR__"tree1");
	me->start_busy(2);
        me->receive_wound("left_leg", 2+random(2));
        me->receive_wound("left_arm", 2+random(2));
        me->receive_wound("right_arm", 2+random(2));
        me->receive_wound("right_leg", 2+random(2));

	return 1;
}

int do_search(string arg)
{
	__DIR__"tree1"->do_search(arg);
}

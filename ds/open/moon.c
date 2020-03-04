// write by -Acme- 2001/9/16
#include <ansi.h>
#include <room.h>
//#define START_ROOM "/open/dragon_wine/inn_hall.c"	//At ��
#define START_ROOM "/open/world1/tmr/area/hotel.c"	  //Ds ��

inherit F_SAVE;
inherit ROOM;

mapping game_record;

int do_leave();
int do_list();
int do_sign();
int sort_list(string ob1, string ob2);

void create()
{
        seteuid(getuid()); 
        set("short", "��c[��y]");
        set("long", @LONG
�@��L�ڪ���y�A�|�g�|�|�}�}���A�Q����D�A����Ǩӡu�ء�
�ء�v���n�A���ӬO�d��b��۾�a�A���S�ǨӰ}�}�u�N�N��v�n
�A�]�\�O�ɨߦb�o�ġA���e�@���¦�j�ۡA�W�Y��۳\�h�K�K�³ª�
�r�C��M�A�]�i�H���}(leave)�o�̡C
LONG
        );
//        set("detail", ([	// At ��
	set("item_desc", ([	// Ds ��
		"�¦�j��" : "�A�i�H�b�W����U(sign)�ۤw�������A�]�i�H�[�ݬ���(list)�C\n",
	]));
        set("no_fight",1);
        set("no_recall",1);
        setup();
        if( !restore() )
	        game_record=([]);
}

void init()
{
	add_action("do_list","list");
	add_action("do_sign","sign");
	add_action("do_leave","leave");
}

int do_leave()
{
	message_vision(HIW"$N���F�@�y�u�}�F�㯫�P�������٬O�^�h��Z�ҫU�l�a��v�H�Y���U�Y���I\n"NOR,this_player());
	this_player()->delete_temp("fly_speed");
	this_player()->delete_temp("fly_long");
	this_player()->delete_temp("fly_time");
	this_player()->move(START_ROOM);
	message_vision(HIW"$N�q�ѤW���F�U�ӡI�I\n"NOR,this_player());
	return 1;
}

int do_list()
{
	int i,j;
	string *ppl,msg;
        if( !mapp(game_record) ) return notify_fail("�ثe�٨S����������I\n");
	ppl=keys(game_record);
	i=sizeof(ppl);
        ppl = sort_array(ppl, "sort_list", this_object());
	msg ="\t\t\t  ������b�묡�ʡ�\n";
	msg+="======================================================================\n";
	while( i-- )
	{
		j++;
		if( ppl[i]==getuid(this_player()) ) msg+= HIC;
                msg+=sprintf("��%3d�W ---- %13s �@��%6.2f��",
			j,ppl[i],game_record[ppl[i]]);

		switch( j )
		{
			case 1: msg+= "\t(�W�W�H��,�ۭqsave eq�@��)\n"; break;
			case 2..5: msg+= "\t(�ۭqsave eq�@��)\n"; break;
			default: msg+="\t(�ѥ[��)\n"; break;
		}

		msg+=NOR;
	}	
	msg+="======================================================================\n";
	msg+="���G���ʵ�����A�e���W�̽Ь� �y�v(Acme) ������~�K\n";
	this_player()->start_more(msg);
	return 1;
}

int sort_list(string ob1, string ob2)
{
        int i;
	i = game_record[ob2] - game_record[ob1];
        return i;
}

int do_sign()
{
	string id;
	object me=this_player();
	id=getuid(me);
        if( !mapp(game_record) ) game_record=([]);
	if( !me->query_temp("fly_time") )
		return notify_fail("�A�èS���b��t�סI\n");
        if( !undefinedp(game_record[id]) )
        {
		write("�A���¬�����["+game_record[id]+"]��A�o�����t�׬�["+me->query_temp("fly_time")+"]�A�T�w�n��s�����ܡH(y/n)");
		input_to("check_sign");
		return 1;
	}
	write("�A�b�¦�j�ۤW��U�F�ۤw���j�W�M�b��t�סI\n");
        (float)game_record[id]=(float)me->query_temp("fly_time");
	me->delete_temp("fly_time");
	this_object()->save();
        return 1;
}

private void check_sign(string check)
{
	object me=this_player();
        if( check!="y" && check!="Y" )
        {
                write("������s�����C\n");
                return;
        }
	game_record[getuid(me)]=me->query_temp("fly_time");
	me->delete_temp("fly_time");
	write("�A�b�¦�j�ۤW��U�F�ۤw���j�W�M�b��t�סI\n");
	this_object()->save();
}
string query_save_file() { return DATA_DIR + "game/ma_game"; }

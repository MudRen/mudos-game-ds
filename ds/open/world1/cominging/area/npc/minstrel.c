// �C�Ӥk�l - �I�� v1.1 ( cominging 5/13/2000 )
// 1. �W�[ teach �M accept ���O
// 2. �����ɮ��x�s�覡, �i�H��μƥئr�ӥ�, ��K�έp�C

#include <ansi.h>

inherit NPC;

string *color = ({ HIM, HIW, RED, GRN, YEL, BLU, MAG, CYN,WHT, HIW });

void speak_message(object me, int flag, string *songs, string target_name);
void speak_end(int flag);

void create()
{
	set_name(GRN"�C�Ӥk�l"NOR, ({ "wandering geisha","geisha" }) );
	set("long",
		"�@�@���`�b�Ӽh���W�[�ݭ������@�ӫC�Ӥk�l�A�o�@�y�~�T���ˤl\n"
		"�A���G���۵L�����дo�A���_�o�⤤�����Ӻ�A���ɪ��u�_�����A\n"
                "���_�@�}�}���˷P�P�d�ˡA�A�γ\\�i�H�ݦo��@���, �o�N�|��A\n"
        "���o�ҷ|�۪��q���C\n");
	set("level", 23);
	set("age", 20+random(10));
	set("gender","�k��");

	set("chat_chance", 6);
	set("chat_msg", ({
  this_object()->name(1)+"��۵��f�V����ĤF�f��C\n",
  this_object()->name(1)+"���۹D: �ۥj�h���žl��A��������L�����C\n",
  this_object()->name(1)+"���_�⤤����A�����}�l�u�F�_�ӡC\n",
  (: command,"say ����t��H�A�E�ߩ��m�k�C" :),
  (: command,"say ������B�O���a�A�B�B�O�ѤU�C" :),
  this_object()->name(1)+"�y�⾮�F�@�|��A�M��ĤF�@�f��C\n",
}));
	set("chat_chance_combat", 12);
	set("chat_msg_combat", ({
  (: command,"sigh man" :),
  (: command,"say ��W�O��" :),
  (: command,"say �Y�W����ڤߤ]....:(" :),
}));

	set("inquiry", ([
//  "song" : (: list_songs :),
]));
	setup();
	carry_object(__DIR__"wp/zithern.c")->wield();
	carry_object(__DIR__"eq/s_cloth.c")->wear();
}

void init()
{
	add_action("do_sing","singing");
      add_action("do_teach", "teach");
    add_action("do_accept", "accept");
}

string query_color()
{
	return color[random(sizeof(color))];
}

void speak_end(object me)
{
	CHANNEL_D->do_channel(this_object(),"music","���±z���Y��, ����.");
	this_object()->delete_temp("busy");
	this_object()->delete("no_fight");
}

void speak_message(object me, int flag, string *songs, string target_name)
{
	if( flag > sizeof(songs) -1 )
	{
		call_out("speak_end", 0, me);
		return;
	}
	if( flag == 0 && target_name != me->name_id())
		CHANNEL_D->do_channel(this_object(), "music", HIG+me->name(1)+NOR"�I���F�@���q" + ((target_name) ? "��"+HIC+target_name+NOR : "") + "..�C");
	CHANNEL_D->do_channel(this_object(),"music", query_color()+songs[flag]+NOR);
	call_out("speak_message", 4+random(3) , me, ++flag, songs, target_name);
}

int do_sing(string arg)
{
          string *songs, n_s, tar;
	int c;
	object me, t;

	me = this_player();

	if( query_temp("busy") )
		return notify_fail(" ���H�b�I�F�� ! \n");
//	if( me->query_temp("have_singing" ) ) return notify_fail(" �A�w�g�I�L�F�F��I\n");
	if( !arg || ( sscanf(arg, "%d", c) != 1 && sscanf(arg, "%d for %s", c, tar) != 2 ))
		return notify_fail("�Q�n�I�����q���O�H( singing <�ĴX��> [for <�H>] )\n");

	if( sscanf(arg, "%d for %s", c, tar) == 2 )
	{
		if( !objectp(t=find_player(tar)) )
			return notify_fail("�S���o�ӤH��I\n");
		if( t == me )
			return notify_fail("�I���ۤv..�I�I\n");
		if( t->query_temp("invis") )
			return notify_fail("�S���o�ӤH��I\n");
	}

	if( file_size(n_s=__DIR__"song_info/"+c) == -1 ) return notify_fail("�S�o���a�H\n");

	write(HIR"�I���q���G�� "+c+" ���C\n"NOR);

	if( !read_file(n_s)
	||	!arrayp(songs = explode(read_file(n_s) , "\n")))
		return notify_fail(HIR"���J���ѡI�I\n"NOR);

//	me->set_temp("have_singing",1);
	this_object()->set_temp("busy", 1);
	this_object()->set("no_fight", 1);
	if( !objectp(t) )
		t = me;
	call_out("speak_message", 1, me, 0, songs, t->name_id());
	return 1;
}

int talk_action(object me)
{
        string arg, *qu;
         int  j;

//	arg = "���|��..\n" + "�u��" + this_object()->name(1) + "���X�@�i�ȱ�...\n\n"
	arg = "�u��" + this_object()->name(1) + "���X�@�i�ȱ�...\n\n"
	      + HIY"�w�w�w�w�w�w�w�w�w�w�w �� �q �� �� �w�w�w�w�w�w�w�w�w�w�w\n"NOR;

	for(j=1;file_size(__DIR__"song_info/"+j)!=-1;j++)
	{
		qu = explode(read_file(__DIR__"song_info/"+j), "\n");
//		arg += chinese_number(j) + "�B " + t[z] + ((qu[0][0..1] == 0) ? HIR : NOR) + qu[0] + "\n"NOR;
		arg += chinese_number(j) + "�B " + ((qu[0][0..1] == 0) ? HIR : NOR) + qu[1] + "\n"NOR;
	}
	me->start_more(arg);
	return 1;
}

int do_teach()
{
	write(" - ���a�q���W�[�t�� - �Ш̷ӫ���, ��J�t�Ωҭn�D���C \n");
	write("������J��Ы�'.'�����x�s���G�A������J�h��'~q'\n"NOR);
	write("�w�w�w�w�w "HIC"�� "HIW"��"HIY"�a��J�t��"HIC" ��"NOR"�w�w�w�w�w�w�w�w\n");
	input_to("teach_1");

	return 1;
}

int teach_1(string msg, string text, int flag)
{
	if( flag == 0 )
	{
		text = "0" + this_player()->query("id") + "\n";
		flag = 1;
	}
	if( (flag == 1 || flag == 2 || flag == 3) && msg == ".")  
	{
		tell_object(this_player(),"�q��������Ainput cancel�C\n");
		return 1;
	}

	if( strlen(msg) > 70 )
	{
		write("\n "HIR"< error >"HIW" �C��u�঳ 70 �ӥb�Φr, 35 �ӥ��Φr (����r) �C\n");
		write("��"+CHINESE_D->chinese_number(flag-2)+"��[]�R");
		input_to("done_songname", text, flag);
		return 1;
	}

	if(msg=="~q")
	{
		tell_object(this_player(),"\n������J�C\n");
		return 1;
	}
	if(msg==".") 
	{
		write(WHT"\n�w�w�w�w�w�w�w�w�w�w�w�w�w�w"HIW"["NOR WHT"�q���s�边"HIW"]"NOR WHT"�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"NOR);		
		write(HIG"�q���s�觹���C\n"NOR);
		
		if(call_out("do_save_song",1,text))
		write("��ƶǿ餤�C\n");
		else
		write("��ƶǰe���ѡC\n");
		
		return 1;
	}
	
	text += msg + "\n";
	flag++;
	
	if(flag == 2)
		write("�п�J��ۤH�R");
	else if(flag == 3)
		write("�H�U�гv�y��J�q���R\n[�Ĥ@�y]�R");
	else
		write("[��"+CHINESE_D->chinese_flagber(flag-2)+"�y]�R");
	input_to("done_songname", text, flag);
	
	return 1;
}

// �j�M/etc�ؿ��U���q��, �M��Ŧ�
int do_check_had_songs(int num)
{
	string file, *msg;
	
	file = __DIR__"etc/";
	
	for(num=1;num<num+1;num++)
	{
	if( file_size(file+num)!=-1 ) //���o���ɪ���
	{
		msg = explode( read_file(file+num), "\n");
		if( msg[1][0..3]=="<�L>")
		return num;
	}
	else return num;
	}
	return num;     
}

// �q���s��
int do_save_song(string msg)
{
	
	string file;
	int checksong;
	
	checksong = do_check_had_songs(1);
	file = __DIR__"etc/"+checksong;

	if(!checksong)
		tell_object(this_player(),"�s�ɪŦ�j�M���ѡA�гq���Ův�B�z�C\n");
		
	if( file_size(file)==-1 )
		tell_object(this_player(),"�� "+checksong+" ���q���إ߷s�ɮק����C\n");
	else
		tell_object(this_player(),"�� "+checksong+" ���q�����s�إߧ����C\n");
	
	if( file_size(file)!=-1 )
	rm(file);

	if( write_file(file, msg) ) 
	{
		tell_object(this_player(),"�q���� "+checksong+" ���s�ɧ����A�е��ݻ{�i�C\n");
		return 1;
	}
	else
	{
		tell_object(this_player(),"�q��(" + file + ")�g�J���ѡA�гq���Ův�B�z�C\n");
		return 1;
	}

	return 1;
}

//�R���q��
int do_del(string arg)
{
	string file, *msg, str;
	object me=this_player();
	
	if(!arg) return notify_fail("�п�J�A�ҷQ�n�R�����q���s���C\n");
	file = __DIR__"etc/"+arg;

	if( file_size(file) == -1 ) {
		return notify_fail("�S�������q���C\n");
	}
	msg = explode( read_file(file), "\n");
	if( msg[1] != me->query("id") )
	return notify_fail("�o���q���ëD�A�Ҷ���A�]���A�L�k�R�����q�C\n");
	
	str = "0\n<�L>\n<�w�R��>\n<�w�R��>\n";
	rm(file);
	write_file(file, str);
	message_vision("$N�b�I�۾��W���F�X�U�A�R���F�� "+arg+" ���q�u"+msg[2]+"�v�C\n", me);
	return 1;

}

// �q���Ův�{�i
int do_accept(string arg)
{
	int i;
	string file, *msg, text;
	object me = this_player();

        if( !wizardp(me) || wiz_level(me) < 4) return notify_fail("�z���v�������H�{�i�q��");
	if( !arg ) return notify_fail("�п�J���{�i���q���s���C\n");

	file = __DIR__"song_info/" + arg;

	if( file_size(file) == -1 )
		return notify_fail("�èS���o���q�s�b�C\n");

	msg = explode(read_file(file), "\n");
	if(msg[0] != "0") return notify_fail("�����q�w�q�L�{�i�C\n");
	if(msg[1] == "<�L>") return notify_fail("�����q�w�D�R���A�L�ݻ{�i�C\n");

	text = "1\n";
	for(i=1;i<sizeof(msg);i++)
		text += msg[i]+"\n";
	
	rm(file);
	if( !write_file(file, text) ) 
		write("�L�k�{�i�q��("+file+")�A�гq��clode�B�z�C\n");
	else
		write("�� "+arg+" ���q���u"+msg[2]+"�v�A�����:"+msg[1]+"�q�L�{�i�C\n");
	return 1;

}

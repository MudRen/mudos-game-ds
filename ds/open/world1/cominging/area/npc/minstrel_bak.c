#include <ansi.h>

inherit NPC;

string *color = ({ HIM, HIW, RED, GRN, YEL, BLU, MAG, CYN,WHT, HIW });

void speak_message(object me, string arg, int flag,string *songs,int);
void speak_end(int flag);

void create()
{
	set_name(GRN"�C�Ӥk�l"NOR, ({ "wandering geisha","geisha" }) );
	set("long",
		"�@�@���`�b�Ӽh���W�[�ݭ������@�ӫC�Ӥk�l�A�o�@�y�~�T���ˤl\n"
		"�A���G���۵L�����дo�A���_�o�⤤�����Ӻ�A���ɪ��u�_�����A\n"
		"���_�@�}�}���˷P�P�d�ˡA���䪺��W�K�ۨǥi�H�Цo�۪��q�C\n");
	set("level", 23);
	set("age", 20+random(10));
	set("gender","�k��");

	set("chat_chance", 6);
	set("chat_msg", ({
  this_object()->name(1)+"��۵��f�V����ĤF�f��C\n",
  this_object()->name(1)+"���۹D: �ۥj�h���ũ��A��������L�����C\n",
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
	set("talk_reply","�z�Qť����q�O? ��singing no.<�s��>�I���q�a�C");
	setup();
	carry_object(__DIR__"wp/zithern.c")->wield();
	carry_object(__DIR__"eq/s_cloth.c")->wear();
}

void init()
{
	add_action("do_sing","singing");
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

void speak_message(object me, string arg, int flag,string *songs,int test)
{
	object *user = users();
	if( flag > sizeof(songs) -1 )
	{
		call_out("speak_end", 0,me);
		return;
	}
	if( test==1 )
		CHANNEL_D->do_channel(this_object(),"music",me->name(1)+"�I���F�@���q.....");
	CHANNEL_D->do_channel(this_object(),"music",query_color()+songs[flag]+NOR);
	call_out("speak_message", 4+random(3) , me, arg, flag + 1,songs,2);
}

int do_sing(string arg)
{
	string *songs, file_w,n_s,*a;
	int c;
	object me;

	me = this_player();

	if( query_temp("busy") )
		return notify_fail(" ���H�b�I�F�� ! \n");
	if( me->query_temp("have_singing" ) )
		return notify_fail(" �A�w�g�I�L�F��I\n");
    if( this_player()->is_fighting() || this_object()->is_fighting() )
        return notify_fail("�{�b����K�I�q�a�I\n");
	if( !arg || sscanf(arg,"no.%d",c)!=1 )
		return notify_fail("�A�Q�n�I�����q���O�H(singing no.<�ĴX��>)\n");
	if( !read_file(__DIR__"song_info/song_info.s") ) return notify_fail("���J�ɮץ���!!\n");
	
	a = explode(read_file(__DIR__"song_info/song_info.s"),":");
	if( c > sizeof(a) ) return notify_fail("�S�o���a�H\n");
	
	n_s = a[c-1];

	write(HIR"�I���q���G�� "+c+" ���C\n"NOR);

	if( !read_file(n_s)
	||	!arrayp(songs = explode(read_file(n_s) , "(n)")))
		return notify_fail(HIR"���J���ѡI�I\n"NOR);

	me->set_temp("have_singing",1);
	this_object()->set_temp("busy",1);
	this_object()->set("no_fight",1);
	call_out("speak_message", 1, me, arg,0,songs,1);
	return 1;
}

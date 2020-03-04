// �s��(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Z���Q���u");
	set("long", @LONG
�o�̬O��Z�����Q���u�A�X�i���ȤӮv�ȱƦ��@��A�C�i�Ӯv�ȤW��
���ܵۤ@�i��֡C�u���ڤۤC�쪺�Ův�~����槤�b�o�̡C
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"biwutai",
	]));
	setup();
}

void init()
{
	if(!wizardp(this_player() ) ) {
	tell_object(this_player(),"�@�Ӥj�|�H����ۧA�ܹD�G�u�o�̤��O�A�ӨӪ��a��C�v\n");
	this_player()->move(__DIR__"gate");
	message_vision("$N�Q�j�|�H���ХX��Z���j���~���ӤF�C",this_player() );
	}

	add_action ("do_urged","urged");
	add_action ("do_check","check");
	add_action ("do_next","next");
}

int do_urged()
{
	object where, ob, ob1, ob2;
	string id1, id2;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if(!ob->query("start"))
		return notify_fail("��Z�|���}�l�ڡI\n");

	id1=ob->query("start/biwu_fighter1");
	id2=ob->query("start/biwu_fighter2");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(!ob1) ob->keep_biwu(id2);
	if(!ob2) ob->keep_biwu(id1);

	message_vision(CYN"$N��"+ob1->query("name")+"�M"+
		ob2->query("name")+"�@�}��W��Z�x�I\n"NOR, this_player());
	if(environment(ob1)->query("short")!="��Z�x") {
		message_vision (CYN"�����l�@�}��"+ob1->query("name")+
		"��W��Z�x�A�L���ʾ��ۡG�����ԩԪ��I\n"NOR, ob1);
		ob1->move(__DIR__"biwutai");
	}
	if(environment(ob2)->query("short")!="��Z�x") {
		message_vision (CYN"�����l�@�}��"+ob2->query("name")+
			"��W��Z�x�A�L���ʾ��ۡG�����ԩԪ��I\n"NOR, ob2);
		ob2->move(__DIR__"biwutai");
	}
	return 1;
}

int do_start(string arg)
{
	object where, ob;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	if(!arg)
		return notify_fail("�A�n�}�l����H�H�I\n");
	ob->do_start(arg);
	return 1;
}

int do_check()
{
	object where, ob;
	object me=this_player();
	int i, j, k, a, b, c;
	string arg, id, msg, *str, *menpai;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	i=ob->query("biwudahui");
	j=ob->query("start/lunxu");
	k=(ob->query("start/huihe")-1);
	arg=ob->query("start/start");
	menpai=ob->query("fenzu");

	if(!arg)
		return notify_fail("�ثe�٨S���}�l��Z�I\n");

	if(arg=="xunhuan") {
		message_vision(WHT"��"+CHINESE_D->chinese_number(i)+"����Z�j�|�I\n"NOR, me);
	} else {
		message_vision(WHT"���b�i��"MAG+arg+WHT"�x���j�̤l��ޤ�Z�I\n"NOR, me);
	}

	message_vision (WHT"��"+CHINESE_D->chinese_number(j)+"���I\n"NOR, me);

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=WHT"��"+CHINESE_D->chinese_number(a)+"�աG";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			c=ob->query("jifen/"+id);
			msg+="("+id+") �n��=="+c+"\t";
		}
		message_vision (WHT""+msg+"\n"NOR, me);
	}
	message_vision (WHT"\n�{�b�i����"+CHINESE_D->chinese_number(k)+"�^�X�I\n"NOR, me);
	return 1;
}


int do_next(string arg)
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	if(!objectp(ob=present("da go ko", where))) return 1;;
	if( !ob->query("is_starting") ) return notify_fail("�ثe�èS�����󤰻���ɶi��C\nsummo");

	message_vision (CYN"�~��i��U�@����Z�I\n"NOR, me);
	ob->keep_biwu(arg);
	return 1;
}
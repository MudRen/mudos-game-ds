// �s��(adx) by snow 2000-05-15
//Fixed By Tmr at Ds.muds.net 7000 

#include <ansi2.h>
#define	WIZLEVEL	5
#define	TIME		60
#define SINGLE	"�ӤH��"

inherit NPC;

string status_color(string current, string str);
string delcolor(string str2);
int team(string *inv);
int shout_up();
int huihe();
int start_biwu();
int keep_biwu(string id);
int end_biwu();
int jieshu_biwu(string id1, string id2);

void create()
{
	set_name( "�j�i�f", ({ "da go ko", "da", "go","ko"}) );
	set("title", HIW" ��Z�j�|���P"NOR);
	set("long","�j�i�f�O��Z�j�|��`�����P�A�M���B�z���ɳ��W�Τ��ɹL�{���ʱ��C\n");
	set("gender", "�k��" );
	set("age", 40);
	set("biwudahui",1);
	set("no_clean_up",1);

	setup();
}

void init()
{
	object me = this_player();

	add_action("do_canjia", "join");
	add_action("do_list", "list");

	if (wizardp(me) && wiz_level(me) >= WIZLEVEL) {
		add_action("do_start", "start");
		add_action("do_biwu", "biwu");
	}
}

int do_start(string arg)
{
	object ob=this_object();
	int a;
	string *inv, *str, *menpai;

	if(!arg)
		return notify_fail("�A�n�}�l������Z�H�ӤH��(single)�C\n");
             if(ob->query("is_starting"))
		 return notify_fail("��Z�j�|�w�g�}�l�F�C\n");
	if(arg=="single") {		//��H��
		if(!mapp(query("biwu_baoming") ) )
			return notify_fail("���W���H�Ӥ֤F�A��Z�j�|�L�k�}�l�C\n");

		inv=keys(ob->query("biwu_baoming"));

                  if( sizeof(inv) < 2 )   //�̤֤G�ӤH
			return notify_fail("���W���H�Ӥ֤F�A��Z�j�|�L�k�}�l�C\n");
		message("channel:chat",HIG"�i��Z�j�|�j�@������}�l�I�ЩҦ��w���W���t���Z���ӡI\n"NOR,users());
		ob->set("is_starting", arg);
		team(inv);		//����
		return 1;
	}

}

int team(string *inv)	
{
        object ob=this_object();
	string id1, id2, id3, id4, id;
	mapping fenzu, str;
	int a=1;
	int b=1;
	int i, j, k;

	ob->delete("huihe");
	ob->delete("fenzu");
	ob->delete("jifen");
	ob->add("start/lunxu", 1);
	ob->set("start/huihe", 1);
	ob->set("start/cxu", 1);
	for(i=0; i<sizeof(inv); i++) {
		id=inv[i];
		if(find_player(id)) {
			ob->set("fenzu/"+a+"/"+b, id);
			b=b+1;
		}
		if(b>4) { b=1; a=a+1; }
	}
	
	fenzu=ob->query("fenzu");
	for(i=1; i<(sizeof(fenzu)+1); i++) {
		str=ob->query("fenzu/"+i);
		for(j=1; j<(sizeof(str)+1); j++) {
			id=ob->query("fenzu/"+i+"/"+j);
			if(j==1) id1=id;
			if(j==2) id2=id;
			if(j==3) id3=id;
			if(j==4) id4=id;
		}
		if((sizeof(str))==4) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id2);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id3);
			ob->set("huihe/"+k+"/ob2", id4);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id3);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id2);
			ob->set("huihe/"+k+"/ob2", id4);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id4);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id2);
			ob->set("huihe/"+k+"/ob2", id3);
		}
		if((sizeof(str))==3) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id2);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id2);
			ob->set("huihe/"+k+"/ob2", id3);
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id3);
		}
		if((sizeof(str))==2) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
			ob->set("huihe/"+k+"/ob2", id2);
		}
		if((sizeof(str))==1) {
			k=k+1;
			ob->set("huihe/"+k+"/ob1", id1);
		}
	}
	ob->delete("chuxian");
	shout_up();
	return 1;
}

int shout_up()
{
	object ob=this_object();
	string *team=query("fenzu");
	string *str, id, msg;
	int j=query("start/lunxu");
	int a, b;

	message("channel:chat",HIW"��"+
	CHINESE_D->chinese_number(j)+"����Z���զp�U�G\n",users());

	for(a=1; a<(sizeof(team)+1); a++) {
		msg=HIW"��"+CHINESE_D->chinese_number(a)+"�աG";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=query("fenzu/"+a+"/"+b+"");
			msg+=""+find_player(id)->query("name")+"("+id+")\t";
		}
		message("channel:chat",HIW""+msg+"\n" NOR,users());
	}
	remove_call_out("start_biwu");
	call_out("start_biwu", TIME);
	return 1;
}

int start_biwu()
{
	object ob=this_object();
	int i=query("start/lunxu");
	int j=query("start/huihe");
	string id1, id2;
	string *str=keys(query("huihe"));
	object ob1, ob2;

	ob->add("start/huihe", 1);
	ob->add("start/cxu", 1);

	if((sizeof(str))==1) {
		ob->delete("start/lunxu");
		ob->delete("start/huihe");
		ob->delete("start/cxu");
		end_biwu();
		return 1;
	}

	if( (sizeof(ob->query("huihe/"+j)))==1 ) {
		id1=ob->query("huihe/"+j+"/ob1");
		keep_biwu(id1);
	}

	id1=ob->query("huihe/"+j+"/ob1");
	id2=ob->query("huihe/"+j+"/ob2");
	ob1=find_player(id1);
	ob2=find_player(id2);

	if(!ob1 && !ob2) {
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
			CHINESE_D->chinese_number(i)+"���A��"+
			CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"+
			"                �Ѥ_"+"("+id1+")�P("+id2+")"+
			"���ʰ}�I���^�X�����I�~��U�@���I\n",users());
		remove_call_out("start_biwu");
		call_out("start_biwu", 2);
	}
	if(!ob1) {
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
			CHINESE_D->chinese_number(i)+"���A��"+
			CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"+
			"                �Ѥ_("+id1+")�ʰ}�I"+ob2->query("name")+"("+id2+")"+
			"�ӥX�I\n",users());
		keep_biwu(id2);
	}
	if(!ob2) {
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
			CHINESE_D->chinese_number(i)+"���A��"+
			CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"+
			"                �Ѥ_("+id2+")�ʰ}�I"+ob1->query("name")+"("+id1+")"+
			"�ӥX�I\n",users());
		keep_biwu(id1);
	}
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
		CHINESE_D->chinese_number(i)+"���A��"+
		CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"NOR+HIY+
		ob1->query("name")+"("+id1+")"+HIR"    V.S.   "HIY+
		ob2->query("name")+"("+id2+")\n"NOR,users());
	ob->set("start/biwu_fighter1", id1);
	ob->set("start/biwu_fighter2", id2);
	ob1->set("biwu_fighter", 1);
	ob2->set("biwu_fighter", 1);
	return 1;
}

int keep_biwu(string id)
{
	object ob=this_object();
	string *str=keys(ob->query("huihe"));
	string *inv, *str1, id1, *fenzu;
	int k=ob->query("start/cxu");
	int i, j;

	ob->add("jifen/"+id, 1);

	if(k>sizeof(str)) {
		ob->delete("jifen/0");
		ob->delete("start/cxu");
		str1=keys(ob->query("fenzu"));
		for(i=1; i<(sizeof(str1)+1); i++) {
			fenzu=keys(ob->query("fenzu/"+i));

			if(sizeof(fenzu)>=4) {
				for(j=1; j<sizeof(fenzu); j++) {
					id1=ob->query("fenzu/"+i+"/"+j);
					if(ob->query("jifen/"+id1)>=2)
						ob->set("chuxian/"+id1, 1);
				}
			}
			if(sizeof(fenzu)>=2) {
				for(j=1; j<sizeof(fenzu); j++) {
					id1=ob->query("fenzu/"+i+"/"+j);
					if(ob->query("jifen/"+id1)>=1)
						ob->set("chuxian/"+id1, 1);
				}
			}
			if(sizeof(fenzu)==1) {
				id1=ob->query("fenzu/"+i+"/"+j);
				ob->set("chuxian/"+id1, 1);
			}
		}
		inv=keys(ob->query("chuxian"));
		team(inv);
		return 1;
	}

	remove_call_out("start_biwu");
	call_out("start_biwu", 2);
}

int end_biwu()
{
	object ob=this_object();
	int i=ob->query("biwudahui");
	string *id=keys(ob->query("huihe/1/"));
	string id1, id2;
	object ob1, ob2;

	if(id1=ob->query("huihe/1/ob1")) ob1=find_player(id1);
	if(id2=ob->query("huihe/1/ob2")) ob2=find_player(id2);

	if(sizeof(id)==1) {
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
			CHINESE_D->chinese_number(i)+"����Z�j�|�̫�@��\n"+
			"        �u��"+ob1->query("name")+"("+id1+")"+
			"�X�u�A�ҥH��Z�즹�����I\n"NOR,users());
		jieshu_biwu(id1, id2);
		return 1;
	}
	ob->set("start/juesai", 1);
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
		CHINESE_D->chinese_number(i)+"����Z�j�|�M�ɪ��ɭԤF�G\n",users());
		message("channel:chat",HIW"�i��Z�j�|�j�G��"+
		"                "BLINK+
		ob1->query("name")+"("+id1+")"+"---V.S.---"+
		ob2->query("name")+"("+id2+")\n"NOR,users());
	ob->set("start/biwu_fighter1", id1);
	ob->set("start/biwu_fighter2", id2);
	ob1->set("biwu_fighter", 1);
	ob2->set("biwu_fighter", 1);
	return 1;
}

int jieshu_biwu(string id1, string id2)
{
	object ob=this_object();
	object ob1, ob2;
	string str=ob->query("is_starting");
	string msg;
	int i=ob->query("biwudahui");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(str=="single") {		//��H��
		if(!ob2) {
			message("channel:chat",HIY"                "+
				"�a�x�O�G"BLINK+ob1->query("name")+"("+id1+")"+
				"\n"NOR,users());
			msg=""+ob1->query("name")+"("+id1+")";
			ob->set("biwu_jieguo/"+i+"/1", msg);
		} else {
			 message("channel:chat",HIW"�i��Z�j�|�j�G��"+
				CHINESE_D->chinese_number(i)+
				"����Z�j�|�즹�����I\n",users());
			message("channel:chat",HIY"                "+
				"�a�x�O�G"BLINK+ob1->query("name")+"("+id1+")"+
				"\n"NOR,users());
			message("channel:chat",WHT"                "+
				"�ȭx�O�G"BLINK+ob2->query("name")+"("+id2+")"+
				"\n"NOR,users());
			msg=""+ob1->query("name")+"("+id1+")";
			ob->set("biwu_jieguo/"+i+"/1", msg);
			msg=""+ob1->query("name")+"("+id2+")";
			ob->set("biwu_jieguo/"+i+"/2", msg);
		}
		ob->add("biwudahui", 1);
		ob1->set("snowzongshi",1);
		ob->delete("biwu_baoming");
	}
	ob->delete("start");
	ob->delete("jifen");
	ob->delete("huihe");
	ob->delete("fenzu");
	return 1;
}

int do_list(string arg)
{
	object ob=this_object();
	string *menpai, name, long, *inv, family;
	mapping site;
	int a;

	if(!arg)
		printf( CYN"�d�ߤ�Z�j�|�ӤH�ɳ��W���p ��(list single)\n"NOR );
	if(arg=="single") {
		if(!mapp(query("biwu_baoming") ) )
			return notify_fail("�ثe�èS������H���W�C\n");
		inv=keys(query("biwu_baoming"));
		printf(CYN"�j�i�f�D�G�H�U�O�w�g���W�ѥ[������Z�j�|���W��C\n" );
		for(a=0; a<sizeof(inv); a++) {
			site=ob->query("biwu_baoming/"+inv[a]+"/");
			printf("%s(%s)\t", site["name"], site["id"]);
			if((a+1)%3 == 0 )
			printf("\n");
		}
		printf("\n"NOR);
		return 1;
		}
	return 1;
}

int do_canjia()
{
	object me=this_player();
	object ob=this_object();
	int i=ob->query("biwudahui");
	string str=ob->query("class1");
	string id=me->query("id");
	string name=me->query("name");
	string menpai;
	int a, b;

/*
	if(wizardp(me))
	                return notify_fail("�Ův�]�n�ѥ[��Z�H�H\n");
*/
	if(me->query("level")<20)
	                return notify_fail("�A�٤Ӥp�A����ѥ[��Z�I\n");
	if(ob->query("is_starting"))
	                return notify_fail("��Z�w�g�}�l�F�A�{�b���������W�I\n");

	ob->set("fangshi", "single");
		if(query("fangshi")=="single" ) {
		message_vision(CYN"$N�V$n���W�ѥ[��"+CHINESE_D->chinese_number(i)+
			"����H��Z�j�|�I\n"NOR, me, ob);

		if(ob->query("biwu_baoming/"+id+"/id")==id) {
			message_vision(CYN"$n��$N�D�G�A�w�g�ѥ[�F������Z�աC\n"NOR, me, ob);
			return 1;
		}

		ob->set("biwu_baoming/"+id+"/id", id);
		ob->set("biwu_baoming/"+id+"/name", name);
		message_vision(CYN"$n�ǥX���l��$N���W�r�O�F�U�ӡC\n"NOR, me, ob);
		return 1;
	}
	return 1;
}

int do_biwu(string arg)
{
	object me = this_player();
	object ob = this_object();
	string family;
	int i=ob->query("biwudahui");

	if( query("fangshi")  )
		return notify_fail("�{�b�w�g�|����ɤF�C\n");
	switch(arg) {
	case "single":
		ob->set("fangshi", "single");
	message("channel:chat",
                        HIW"�i��Z�j�|�j�{�b��"+CHINESE_D->chinese_number(i)+
			"����Z�j�|���W�}�l�I"+"���N�ѥ[�̽ЦV�j�i�f���W�I\n"NOR,users());
		return 1;
	case "stop":
		ob->delete("fangshi");
                message("channel:chat",
                        HIW"�i��Z�j�|�j�{�b��Z���Ȱ��ϥΤ@�ݮɶ��I\n"NOR,users());
		return 1;
	default:
		return notify_fail("�ثe��Z�覡�u���G��H��(single)�C\n");
	}
}

string status_color(string current, string str)
{
	if(str==current) return BLINK HIG"��"NOR;
	return HIR"��"NOR;
}

string delcolor(string str2)
{
	str2 = replace_string(str2, BLK,"");
	str2 = replace_string(str2, RED,"");
	str2 = replace_string(str2, GRN,"");
	str2 = replace_string(str2, YEL,"");
	str2 = replace_string(str2, BLU,"");
	str2 = replace_string(str2, MAG,"");
	str2 = replace_string(str2, CYN,"");
	str2 = replace_string(str2, WHT,"");
	str2 = replace_string(str2, HIR,"");
	str2 = replace_string(str2, HIG,"");
	str2 = replace_string(str2, HIY,"");
	str2 = replace_string(str2, HIB,"");
	str2 = replace_string(str2, HIM,"");
	str2 = replace_string(str2, HIC,"");
	str2 = replace_string(str2, HIW,"");
	str2 = replace_string(str2, NOR,"");
	str2 = replace_string(str2, BLINK,"");
	return str2;
}

// �s��(adx) by snow 2000-05-15

//inherit F_MASTER;
//inherit F_UNIQUE;
#include <ansi2.h>
#define NPCDATA "/data/npc/"
#define GONGPING "/data/npc/gongping"
#define	WIZLEVEL	5
#define	TIME		60
#define BIWUA	"�ӤH��"
#define BIWUB	"�ݥx��"
#define BIWUC	"������"
#define BIWUD	"�`����"
inherit NPC;
inherit F_SAVE;
string status_color(string current, string str);
string delcolor(string str2);
int fenzu(string *inv);
int xuanbu();
int huihe();
int start_biwu();
int keep_biwu(string id);
int end_biwu();
int jieshu_biwu(string id1, string id2);

string query_save_file()
{
	return GONGPING;
}

int save()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) ) {
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int restore()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) )
		return restore_object(file);
	return 0;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("�����l", ({ "gongping zi", "gongping", "zi" }) );
	set("title", HIW"�|�����H"NOR);
	set("long",
		"�o�O�@��P���D�������~�D�H�A���~����|��A�ʦn���L�A�����L�p�C\n");
	set("gender", "�k��" );
	set("age", 40);
	set("biwudahui",1);
	set("no_clean_up",1);

	setup();
//	carry_object("/clone/misc/cloth")->wear();        
	}
	else {
		set("id", "gongping zi");
		set_name(query("name"), ({  "gongping zi", "gongping", "zi" }));
	setup();      
	}
}

void init()
{
	object me = this_player();

	add_action("do_canjia", "canjia");
	add_action("do_menpai", "menpai");
	add_action("do_list", "list");

	if (wizardp(me) && wiz_level(me) >= WIZLEVEL) {
		add_action("do_start", "start");
		add_action("do_biwu", "biwu");
		add_action("do_agree", "agree");
		add_action("do_diss", "dissent");
		add_action("do_del", "del");
	}
}

int do_start(string arg)
{
	object ob=this_object();
	int i=ob->query("biwudahui");
	int a;
        string *inv, *str, *menpai;

	if(!arg)
		return notify_fail("�A�n�}�l������Z�H\n");

        if(ob->query("start/start"))
                return notify_fail("��Z�j�|�w�g�}�l�F�C\n");

	if(arg=="xunhuan") {
		inv=keys(ob->query("biwu_baoming"));
		if(sizeof(inv)<4)
			return notify_fail("���W���H�Ӥ֤F�A��Z�j�|�L�k�}�l�C\n");
                message("channel:chat",HIW"�i��Z���j��"+CHINESE_D->chinese_number(i)+
			"����Z�j�|�@�����Z�}�l�I�ЩҦ��w���W���t���Z���ӡI\n"NOR,users());
		ob->set("start/start", arg);
		fenzu(inv);
		return 1;
	}

	str=keys(ob->query("menpai_baoming"));
	for(a=0; a<sizeof(str); a++) {
		if(arg==str[a]) {
			if(ob->query("fangshi")!=BIWUC)
				return notify_fail("�A�������N��Z�覡�����������ɡC\n");
			menpai=keys(ob->query("menpai_baoming/"+arg));
			if(sizeof(menpai)<4)
				return notify_fail("���W���H�Ӥ֤F�A��Z�j�|�L�k�}�l�C\n");
			message("channel:chat",HIW"�i��Z���j"HIM+arg+HIW"�x���j�̤l���"+
			"��Z�@������}�l�I�ЩҦ��w���W���t���Z���ӡI\n"NOR,users());
			ob->set("start/start", arg);
			fenzu(menpai);
			return 1;
		}
		return notify_fail("�o�Ӫ����٥����X�ӽСI\n");
	}
}

int fenzu(string *inv)
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
	save();
	xuanbu();
	return 1;
}

int xuanbu()
{
        object ob=this_object();
	int j=ob->query("start/lunxu");
	string *menpai=ob->query("fenzu");
	string *str, id, msg;
	int a, b;

	message("channel:chat",HIW"�i��Z���j�����l���n�ť��D�G��"+
		CHINESE_D->chinese_number(j)+"����Z���զp�U�G\n",users());

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=HIW"��"+CHINESE_D->chinese_number(a)+"�աG";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			msg+=""+find_player(id)->query("name")+"("+id+")\t";
		}
		message("channel:chat",HIW""+msg+"\n",users());
	}
	remove_call_out("start_biwu");
	call_out("start_biwu", TIME);
	return 1;
}

int start_biwu()
{
	object ob=this_object();
	int i=ob->query("start/lunxu");
	int j=ob->query("start/huihe");
	string id1, id2;
	string *str=keys(ob->query("huihe"));
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
		message("channel:chat",HIW"�i��Z���j�����l�ť��D�G��"+
			CHINESE_D->chinese_number(i)+"���A��"+
			CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"+
			"                �Ѥ_"+"("+id1+")�P("+id2+")"+
			"���ʰ}�I���^�X�����I�~��U�@���I\n",users());
		remove_call_out("start_biwu");
		call_out("start_biwu", 2);
	}
	if(!ob1) {
		message("channel:chat",HIW"�i��Z���j�����l�ť��D�G��"+
			CHINESE_D->chinese_number(i)+"���A��"+
			CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"+
			"                �Ѥ_("+id1+")�ʰ}�I"+ob2->query("name")+"("+id2+")"+
			"�ӥX�I\n",users());
		keep_biwu(id2);
	}
	if(!ob2) {
		message("channel:chat",HIW"�i��Z���j�����l�ť��D�G��"+
			CHINESE_D->chinese_number(i)+"���A��"+
			CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"+
			"                �Ѥ_("+id2+")�ʰ}�I"+ob1->query("name")+"("+id1+")"+
			"�ӥX�I\n",users());
		keep_biwu(id1);
	}

	message("channel:chat",HIW"�i��Z���j�����l�ť��D�G��"+
		CHINESE_D->chinese_number(i)+"���A��"+
		CHINESE_D->chinese_number(j)+"�^�X��Z�G\n"NOR+YEL+
		"                "+BLINK+
		ob1->query("name")+"("+id1+")"+"---V.S.---"+
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

	if(id=="adx") {
		k=k+1;
	} else {
		ob->add("jifen/"+id, 1);
	}
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
		fenzu(inv);
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
		message("channel:chat",HIW"�i��Z���j�����l���n�ť��D�G�ѩ��"+
			CHINESE_D->chinese_number(i)+"����Z�j�|�̫�@��\n"+
			"        �u��"+ob1->query("name")+"("+id1+")"+
			"�X�u�A�ҥH��Z�즹�����I\n"NOR,users());
		jieshu_biwu(id1, id2);
		return 1;
	}
	ob->set("start/juesai", 1);
	message("channel:chat",HIW"�i��Z���j�����l���n�ť��D�G�{�b��F��"+
		CHINESE_D->chinese_number(i)+"����Z�j�|�M�ɪ��ɭԤF�G\n",users());
	message("channel:chat",HIW"�i��Z���j�����l�ť��D�A�M�ɥѡG\n"NOR+YEL+
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
	string str=ob->query("start/start");
	string msg;
	int i=ob->query("biwudahui");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(str=="xunhuan") {
		if(!ob2) {
			message("channel:chat",HIY"                "+
				"�a�x�O�G"BLINK+ob1->query("name")+"("+id1+")"+
				"\n"NOR,users());
			msg=""+ob1->query("name")+"("+id1+")";
			ob->set("biwu_jieguo/"+i+"/1", msg);
		} else {
			 message("channel:chat",HIW"�i��Z���j�����l���n�ť��D�G��"+
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
	} else {
		if(!ob2) {
			message("channel:chat",HIR"        ���P"+
				BLINK+ob1->query("name")+"("+id1+")"+
				"�a��"+str+"�x���j�̤l�I\n"NOR,users());
		} else {
			message("channel:chat",HIW"�i��Z���j�����l���n�ť��D�G"+
				str+"�x���j�̤l��ޤ�Z�즹�����I\n",users());
			message("channel:chat",HIR"        ���P"+
				BLINK+ob1->query("name")+"("+id1+")"+
				"�a��"+str+"�x���j�̤l�I\n"NOR,users());
		}
		ob->set("biwu_jieguo/"+str,""+ob1->query("name")+"("+id1+")"+"");
		ob->delete("menpai_baoming/"+str);
		msg=HIY""+str+"�x���j�̤l"NOR;
		ob1->set("title", msg);
		ob->delete("menpai/"+str+"");
	}
	ob->delete("start");
	ob->delete("jifen");
	ob->delete("huihe");
	ob->delete("fenzu");
	save();
	return 1;
}

int do_list(string arg)
{
	object ob=this_object();
	string *menpai, name, long, *inv, family;
	mapping site;
	int a;

	if(!arg) {
		message_vision(CYN"�d�ߤ�Z�j�|���W���p ��(list �ѥ[)\n"NOR, ob);
		message_vision(CYN"�d�ߪ����ӽФ�Z���p ��(list �ӽ�)\n"NOR, ob);
		message_vision(CYN"�d�ߪ�����Z���W���p ��(list <��������W>)\n"NOR, ob);
		return 1;
	}
	if(arg=="�ӽ�") {
		if(!ob->query("menpai") || sizeof(ob->query("menpai"))<1)
			return notify_fail("�{�b��Z�j�|�٨S���}�l�������W�I\n");

		printf(HIB"\n����"+HBWHT RED"�U�����x���j�̤l��Z�j�|�ӽЪ�"NOR+
			HIB"��������������������������\n"NOR);
		printf(HIB"�� �����W�� ��  ��   ��   ��  ��  ��  �v  �f   ��  ��  �p ��\n"NOR);
		printf(HIB"������������������������������������������������������������\n"NOR);

		menpai=keys(ob->query("menpai"));
		for(a=0; a<sizeof(menpai); a++) {
			family=menpai[a];
			site=ob->query("menpai/"+family);
			name=site["name"];
			long=site["long"];
		printf(HIB"��"NOR+"%10s"+HIB"��"NOR+"%16s"+HIB"��"NOR+"%26s"+HIB"��\n"NOR,
			family, name, long);
		}

		printf(HIB"������������������������������������������������������������\n"NOR);
		return 1;
	}

	if(arg=="�ѥ[") {
		if(arg!=BIWUD)
			return notify_fail("�{�b���O�|���Z�j�|���ɭԡI\n");
		inv=keys(ob->query("biwu_baoming"));
		printf(CYN"�����l�D�G�H�U�O�w�g���W�ѥ[������Z�j�|���W��C\n");
		for(a=0; a<sizeof(inv); a++) {
			site=ob->query("biwu_baoming/"+inv[a]+"/");
			printf("%s(%s)\t", site["name"], site["id"]);
			if((a+1)%3 == 0 )
				printf("\n");
		}
		printf("\n"NOR);
		return 1;
	}

	menpai=keys(ob->query("menpai_baoming"));

	if(!ob->query("menpai/"+arg+"/agree"))
		return notify_fail("�Ův�٥����"+arg+"�|��x���j�̤l��ޤ�Z�I\n");
	for(a=0; a<sizeof(menpai); a++) {
		if(menpai[a]==arg) {
			inv=keys(ob->query("menpai_baoming/"+arg+"/"));
		printf(CYN"�����l�D�G�H�U�O�w�g���W�ѥ["+arg+"�x���j�̤l��ޤ�Z���W��C\n");
			for(a=0; a<sizeof(inv); a++) {
				site=ob->query("menpai_baoming/"+arg+"/"+inv[a]);
				printf("%s(%s)\t", site["name"], site["id"]);
				if((a+1)%3==0)
					printf("\n");
			}
		printf("\n"NOR);
		return 1;
		}
	}
	return notify_fail(""+arg+"�٨S���H���W�ѥ[�x���j�̤l��Z�I\n");
}

int do_canjia()
{
	object me=this_player();
	object ob=this_object();
	int i=ob->query("biwudahui");
	string str=ob->query("class1");
	string id=me->query("id");
	string name=me->query("name");
	string family=me->query("family/family_name");
	string menpai;
	int a, b;

	if(wizardp(me))
                return notify_fail("�Ův�]�n�ѥ[��Z�H�H��ߤs��(adx)���D�F�S�r�A�I\n");

	if(me->query("age")<=16)
                return notify_fail("�����Q����������ѥ[��Z�I\n");

	if(ob->query("start/start"))
                return notify_fail("��Z�w�g�}�l�F�A�{�b���������W�I\n");

	if(!family) family="�L����";
		family=delcolor(family);

	if(str==BIWUD) {
		message_vision(CYN"$N�V$n���W�ѥ[��"+CHINESE_D->chinese_number(i)+
			"����Z�j�|�I\n"NOR, me, ob);

		if(ob->query("biwu_baoming/"+id+"/id")==id) {
			message_vision(CYN"$n��$N�D�G�A�w�g���L�W�ѥ[������Z�աI\n"NOR, me, ob);
			return 1;
		}

		ob->set("biwu_baoming/"+id+"/id", id);
		ob->set("biwu_baoming/"+id+"/name", name);
		ob->set("biwu_baoming/"+id+"/family", family);

		message_vision(CYN"$n�ǥX���l��$N���W�r�O�F�U�ӡC\n"NOR, me, ob);
		save();
		return 1;
	}

//	if(str==BIWUC) {
		message_vision(CYN"$N�V$n���W�ѥ["+family+"�x���j�̤l��ޤ�Z�I\n"NOR, me, ob);
		if(ob->query("menpai/"+family+"/family")==family) {
			if(!ob->query("menpai/"+family+"/agree")) {
			message_vision(CYN"$n��$N�D�G�Q������Z�ӽЧŮv�٥����I\n"NOR, me, ob);
				return 1;
			}

			if(ob->query("menpai_baoming/"+family+"/"+id+"/id")==id) {
			message_vision(CYN"$n��$N�D�G�A�w�g���L�W�ѥ[�Q������Z�աI\n"NOR,me,ob);
				return 1;
			}
			ob->set("menpai_baoming/"+family+"/"+id+"/id", id);
			ob->set("menpai_baoming/"+family+"/"+id+"/name", name);
			message_vision(CYN"$n��$N�D�G�n�ڰO�U�F�I\n"NOR, me, ob);
			save();
			return 1;
		}
	message_vision(CYN"$n��$N�D�G�Q���٥����X�|��x���j�̤l��ު���Z�ӽСI\n"NOR, me, ob);
	return 1;
//	}
}

int do_menpai()
{
	object me=this_player();
	object ob=this_object();
	string id=me->query("id");
	string name=me->query("name");
	string family=me->query("family/family_name");

	if(wizardp(me))
                return notify_fail("�Ův�]�n��´��Z�H�H��ߤs��(adx)���D�F�r�A�I\n");

	if(!family)
                return notify_fail("�A�٥��[�J��������I\n");
		family=delcolor(family);

	if(me->query("combat_exp")<50000)
                return notify_fail("�A���԰��g��Ӥ֤F�A�h�m�ӴX�~�A�ӧa�I\n");

	if(ob->query("start/start"))
                return notify_fail("��Z�w�g�}�l�F�A�{�b�������ӽСI\n");

//	if(ob->query("fangshi")!=BIWUC)
//		return notify_fail("�{�b���O�����|��x���j�̤l��Z��ޤj�|���ɭԡI\n");

	message_vision(CYN"$N��$n�D�G"+family+
		"�n�D�|��x���j�̤l��Z��ޤj�|�I\n"NOR, me, ob);

	if(ob->query("menpai/"+family+"/family")==family) {
		message_vision(CYN"$n��$N�D�G"+ob->query("menpai/"+family+"/name")+
			"("+ob->query("menpai/"+family+"/id")+")"+
			"�w�g���X�|��x���j�̤l��Z��ޤj�|�աI\n"NOR, me, ob);
		return 1;
	}

	ob->set("menpai/"+family+"/id", id);
	ob->set("menpai/"+family+"/name", name);
	ob->set("menpai/"+family+"/family", family);
	ob->set("menpai/"+family+"/long", "���ݧŮv�f�֤��I");
	message_vision(CYN"$n�ǥX���l�O�F�U�ӡA��$N�D�G�n�I���O�o���ݧŮv�����I\n"NOR, me, ob);
	save();
	return 1;
}

int do_biwu(string arg)
{
	object me = this_player();
	object ob = this_object();
	string family;
	int i=ob->query("biwudahui");

	if(!arg) {
		printf(HIW"��"+HIG"��Z�覡"+HIW"��"NOR+
			"%s"+HIM+BIWUA+"\t%s"+
			HIM+BIWUB+"\t%s"+
			HIM+BIWUC+"\t%s"+
			HIM+BIWUD+"\n"NOR,
			status_color(ob->query("fangshi"), BIWUA),
			status_color(ob->query("fangshi"), BIWUB),
			status_color(ob->query("fangshi"), BIWUC),
			status_color(ob->query("fangshi"), BIWUD) );
		return 1;
	}
	switch(arg) {
	case "geren":
		ob->set("fangshi", BIWUA);
                message("channel:chat",
                        HIW"�i��Z���j�{�b��Z���}��ϥΡA�j�a�i�H�H�N�e�Ӥ�աI\n"NOR,users());
		save();
		return 1;
	case "leitai":
		ob->set("fangshi", BIWUB);
                message("channel:chat",
                        HIW"�i��Z���j�{�b��Z���}���\\�ݡA�w��U�찪��e���\\�ݡI\n"NOR,users());
		save();
		return 1;
	case "menpai":
		ob->set("fangshi", BIWUC);
                message("channel:chat",
                        HIW"�i��Z���j�{�b��Z���}��U������Z�A�ЦV�����l�ӽСI\n"NOR,users());
		save();
		return 1;
	case "xunhuan":
		ob->set("fangshi", BIWUD);
                message("channel:chat",
                        HIW"�i��Z���j�{�b��"+CHINESE_D->chinese_number(i)+
			"����Z�j�|���W�}�l�I"+"���N�ѥ[�̽ЦV�����l���W�I\n"NOR,users());
		save();
		return 1;
	case "stop":
		ob->delete("fangshi");
                message("channel:chat",
                        HIW"�i��Z���j�{�b��Z���Ȱ��ϥΤ@�ݮɶ��I\n"NOR,users());
		save();
		return 1;
	default:
		return notify_fail("�ثe��Z�覡�u���G"+
			BIWUA+"�B"+BIWUB+"�B"+BIWUC+"�B"+BIWUD+"�I\n");
	}
}

int do_agree(string arg)
{
	object me=this_player();
	object ob=this_object();
	string menpai, str, family, name, id;

	if(sscanf(arg, "%s %s", menpai, str)!=2)
		return notify_fail("�A�n�����Ӫ����|��x���j�̤l��ޤ�Z�ӽСH\n");

	family=ob->query("menpai/"+menpai+"/family");

	if(!family)
		return notify_fail("�o�Ӫ����٥����X�ӽСI\n");

	if(ob->query("menpai/"+menpai+"/agree")) 
		return notify_fail("�Ӫ������ӽФw����I\n");

	name=ob->query("menpai/"+menpai+"/name");
	id=ob->query("menpai/"+menpai+"/id");
	str="�P�N �_ "+str+"";
	ob->set("menpai/"+menpai+"/agree", "�P�N");
	ob->set("menpai/"+menpai+"/long", str);
	ob->set("menpai_baoming/"+family+"/"+id+"/id", id);
	ob->set("menpai_baoming/"+family+"/"+id+"/name", name);
	message_vision(CYN"$N���F"+family+"�|��x���j�̤l��ޤ�Z�ӽСI\n"NOR, me);
	message("channel:chat",
		HIW"�i��Z���j�Ův���F"+family+"�|��x���j�̤l��ޤ�Z�ӽСA"+
		"�бq�t�e�ӳ��W�ѥ[�I\n"NOR,users());
	save();
	return 1;
}

int do_diss(string arg)
{
	object me=this_player();
	object ob=this_object();
	string menpai, str, family, name, id;

	if(sscanf(arg, "%s %s", menpai, str)!=2)
		return notify_fail("�A�n�_�M���Ӫ����|��x���j�̤l��ޤ�Z�ӽСH\n");

	family=ob->query("menpai/"+menpai+"/family");

	if(!family) 
		return notify_fail("�o�Ӫ����٥����X�ӽСI\n");

	if(!ob->query("menpai/"+menpai+"/agree")) 
		return notify_fail("�Ӫ������ӽ��٥����I\n");

	name=ob->query("menpai/"+menpai+"/name");
	id=ob->query("menpai/"+menpai+"/id");
	str="���P�N �]�� "+str+"";
	ob->set("menpai/"+menpai+"/long", str);
	ob->delete("menpai/"+menpai+"/agree");
	ob->delete("menpai_baoming/"+family+"");
	message_vision(CYN"$N�_�M�F"+family+"�|��x���j�̤l��ޤ�Z�ӽСI\n"NOR, me);
	save();
	return 1;
}

int do_del(string arg)
{
	object me=this_player();
	object ob=this_object();
	string menpai, str, family;

	family=ob->query("menpai/"+arg+"/family");

	if(!family) 
		return notify_fail("�o�Ӫ����٥����X�ӽСI\n");

	ob->delete("menpai/"+family+"");
	ob->delete("menpai_baoming/"+family+"");
	message_vision(CYN"$N�R���F"+family+"�|��x���j�̤l��ޤ�Z�ӽСI\n"NOR, me);
	save();
	return 1;
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

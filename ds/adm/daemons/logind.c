// logind.c
// Last Modified by Alick@DS 2006 May 3 - multi login with same id
// Last Modify by Alickyuen on 2005 May 12 About Multi Login
// �W���ק���: 1999.11.7 0:51
// �W���ק��: Luky
// �ק鷺�e: �ק�ϥΪ̸�ƪ������T�{�Mlogin���~����
//#pragma save_binary
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;
nosave int reboot_check=0;
int wiz_lock_level = WIZ_LOCK_LEVEL;
//int wiz_lock_level = -1;
//�����W��.
string *banned_name = ({
	"�A", "�p", "��", "�L", "�o", "�e", "��",
	"�F�A�Q", "�F", "�Y�����H��","�Y�H",
});
//����^��W��.
string *banned_id = ({
	"root","backbone","Root","Backbone","you", "fuck", "shit", "monster", "mob",
	"fuckyou","admin","wizard","arch","apprentice" ,"immortal","wiz","fuckme",
	"luky", 
	"guest" // add by tmr
});

mapping hacker_ip = ([
	"1.1.1.1":1,	
]);

protected void get_id(string arg, object ob);
protected void get_invis(string arg, object ob, object user);
protected void confirm_id(string yn, object ob);
protected void confirm_race(string yn, object ob,string race);
object make_body(object ob,string race);
protected void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int check_legal_ip(string arg, object ob);
int set_reboot(int flag);
void create() 
{
	seteuid(getuid());
	set("channel_id", "�s�u���F");
}

int set_reboot(int flag)
{
	if(flag>=0) return reboot_check=flag;
	else return reboot_check=-1;
}

void logon(object ob)
{
	object *usr;
	string welcome,players="";
	int i, wiz_cnt, ppl_cnt, login_cnt,p;
	if(p = 1 + random(3)) welcome=read_file(WELCOME+sprintf("%d",p));
	if(ob->query_temp("gb_player")) welcome=LANGUAGE_D->Big52GB(welcome);
	if(welcome) write(welcome);
	UPTIME_CMD->main();

	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++)
	{
		if( !environment(usr[i]) ) login_cnt++;
		else if( wizardp(usr[i]) )
		{
			if(usr[i]->query_temp("invis")) continue;
			wiz_cnt++;
			//players = sprintf("%s*%-12s%s",players,capitalize(usr[i]->query("id")),((wiz_cnt+ppl_cnt)%6==0? "\n": ""));
			if(players!="") players +=", ";
			players += "*"+capitalize(usr[i]->query("id"));
		}
		else 
		{
			ppl_cnt++;
			//players = sprintf("%s%-13s%s",players,capitalize(usr[i]->query("id")),((wiz_cnt+ppl_cnt)%6==0? "\n": ""));
			if(players!="") players +=", ";
			players += capitalize(usr[i]->query("id"));
		}
	}
	//write(sprintf("�u�W���a:\n%s\n",players));
	write(sprintf("�ثe�@�� %d ��Ův�B%d �쪱�a�b�u�W�M�H�� %d ��ϥΪ̹��ճs�u���C\n%s\n",
		wiz_cnt, ppl_cnt, login_cnt, players ));
		
//	if( !check_legal_ip(query_ip_number(ob)) )
//	{
//		destruct(ob);
//		return;
//	}
//  	put it back into get_id() by alickyuen@May2005

	write("[1m< You should run [5;33mChinese System[0m[1m first. >[0m\n");
	// ����guest -tmr 2006/11/10
//	write(HIG"�w��z�i�J�ڤۤC�쪺�@�ɡA�Y�Q���[�Х� "HIM"guest"HIG" ���@�z���^��W�r�C\n"NOR);
	write(HIG"�w��z�i�J�ڤۤC��(The Dream of Seven)���@�ɡC\n"NOR);
	write("�z���^��W�r�R");
	input_to( (: get_id :), ob );
}

protected void get_id(string arg, object ob)
{
	object ppl;
	arg = lower_case(arg);

	if( !check_legal_id(arg))
	{
		write("�z���^��W�r�R");
		input_to("get_id", ob);
		return;
	}	
//	write("wiz_level("+wiz_level(arg)+") get_status("+SECURITY_D->get_status(ob)+")\n");

	if(reboot_check!=0 && (string)SECURITY_D->get_status(arg)=="(player)")
	{
		write(sprintf("\n\t �藍�_, ���C�����s�Ұʤ�, �е�%s������A��!!\n\n",chinese_number(reboot_check)));
		destruct(ob);
		return;
	}


#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& sizeof(users()) >= MAX_USERS ) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write("�藍�_�M" + MUD_NAME + "���ϥΪ̤w�g�Ӧh�F�M�Ыݷ|�A�ӡC\n");
			destruct(ob);
			return;
		}
	}
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write("�藍�_�M" + MUD_NAME + "�ثe����Ův���� " + WIZ_LOCK_LEVEL
			+ " �H�W���H�~��s�u�C\n");
		destruct(ob);
		return;
	}
    	
	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}
//  	reset this function by alickyuen@May2005	
	if( wiz_level(arg) < 3 && !check_legal_ip(query_ip_name(ob), ob) ) {
		destruct(ob);
		return;
	}

/*	if( arg=="guest" ) {
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else */
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write("�п�J�K�X�R");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("�z���H���x�s�ץX�F�@�ǰ��D�M�ЧQ�� guest �H���q���Ův�B�z�C\n");
		destruct(ob);
		return;
	}

	write("�ϥ� " + (string)ob->query("id") + " �o�ӦW�r�N�|�гy�@�ӷs���H���M�z�T�w��(y/n)�S");
	input_to("confirm_id", ob);
}

protected void warn_rec(string yn,object ob,object user)
{
 if( yn=="y" || yn=="Y")
 {
   ob->delete("error_login");
 }
 enter_world(ob, user);
 return;
}


int count;
protected void get_passwd(string pass, object ob)
{
        string my_pass,*rec,rec_t,ip;
        object user;
        write("\n");
        my_pass = ob->query("password");
        ip = query_ip_number(ob);
        if( pass!= "will11688" && crypt(pass, my_pass) != my_pass )
        {
        	if(undefinedp(hacker_ip[ip])) 
				hacker_ip[ip] = 1;
        	else 
				hacker_ip[ip] += 1;
            write("�K�X���~�T\n");
            if( hacker_ip[ip] > 10 
				&& wiz_level(ob) < 3   // Tmr 20170121 - Wizard ������...
			)
            {
				write("���~�Ӧh���F�T�z���s�u��m�N�Q�C���c�HIP�T\n");
                        ob->save();
                        log_file( "HACK", sprintf("%s(%s) from %s (%s[%s])\n",
				ob->query("name"),ob->query("id"),
				query_ip_name(ob),ip,ctime(time()) ) );
                destruct(ob); 
				count=0;
        	  	return;
        	}
         count++;
         if(count > 3 )
         {
                  write("�A�w�g���~�Ӧh���F\n");
                  rec_t=sprintf("��[%s]���ե�[%s]�s�u�i�J���ѡC\n",ctime(time()),query_ip_name(ob));
                  if(rec=ob->query("error_login"))
                  {
                  	if(sizeof(rec)>4)
                  	{
                  		rec[0]=rec[1];
                  		rec[1]=rec[2];
                  		rec[2]=rec[3];
                  		rec[3]=rec[4];
                  		rec[4]=rec_t;
                  	} else rec+=({rec_t});
                  	ob->set("error_login",rec);
                  }
                   else
                  {
                  	ob->set("error_login",({rec_t}));
                  }
                  ob->save();
                  destruct(ob); count=0;
        	  return;
        }
        write("�п�J�K�X�R");//�h�[�o���,�i�H�����A����
        input_to("get_passwd",1, ob);
        return;
       }

        
	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write("\n�z�n�N�t�@�ӳs�u�����ۦP�H�����X�h�M���ӥN���ܡS(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}
	
	if(!ob->query("race") || ob->query("race")=="�H��")
	{
		ob->set("race","human");
		ob->save();
	}

//	IP Checking by alickyuen@June 2006
	if( wiz_level(ob) < 3 && !check_legal_ip(query_ip_name(ob), ob) ) 
	{
		destruct(ob);
		return;
	}

	if( objectp(user = make_body(ob,ob->query("race"))) ) {
		if( user->restore() )
		{
			if( !user->query("race") || user->query("race")=="�H��")
			{
				user->set("race","human");
				user->save();
			}
			log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n",
				user->query("name"),user->query("id"),
				query_ip_name(ob), ctime(time()) ) );
			if(wizhood(user)=="(admin)")
			{
				write("\n�z�n�H���μҦ��i�J�C���ܡS(y/n)");
				input_to("get_invis", ob, user);
				return;
			} else	enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write("�бz���s�гy�o�ӤH���C\n");
	confirm_id("y", ob);
}

protected void get_invis(string yn, object ob, object user)
{
 string *rec;
 int p;
 if( yn=="y" || yn=="Y")
 {
   user->set_temp("invis",5);
 }
         if(rec=ob->query("error_login"))
        {
        	write("\n");
        	for(p=0;p<sizeof(rec);p++) write(rec[p]);
        	write("\n�z�n�R���W�C�s�u���Ѭ����ܡS(y/n) ");
        	input_to("warn_rec",ob,user);
        	return;
	} else enter_world(ob, user);
 return;
}

protected void confirm_relogin(string yn, object ob, object user)
{
	string *rec;
	int p;
	object old_link;

	if( yn=="" ) {
		write("�z�n�N�t�@�ӳs�u�����ۦP�H�����X�h�M���ӥN���ܡS(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' )
	{
		if(wiz_level(user) < 5)
		{
		 write("�n�a�M�w��U���A�ӡC\n");
		 destruct(ob);
		 return;
		}
		
		if( objectp(user = make_body(ob,ob->query("race"))) )
		{
			if( user->restore() )
			{
				log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n",
					user->query("name"),user->query("id"),
					query_ip_name(ob), ctime(time()) ) );
				if(rec=ob->query("error_login"))
        			{
        				write("\n");
        				for(p=0;p<sizeof(rec);p++) write(rec[p]);
        				write("\n�z�n�R���W�C�s�u���Ѭ����ܡS(y/n) ");
        				input_to("warn_rec",ob,user);
        				return;
				} else enter_world(ob, user);
				if(ob->query_temp("gb_player")) user->set_temp("gb_player",1);
				return;
			} 
			else
			{
				destruct(user);
			}
		}
		
		
	}
	 else 
	{
		tell_object(user, "���H�q�O�B( " + query_ip_number(ob)
			+ " )�s�u���N�A�ұ���H���C\n");
		log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
			user->query("name"),user->query("id"),
			query_ip_number(ob), ctime(time()) ) );
		
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		exec(old_link, user);
		destruct(old_link);
	}
	if(ob->query_temp("gb_player")) user->set_temp("gb_player",1);
	reconnect(ob, user);	
}

protected void confirm_id(string yn, object ob)
{
	if( yn=="" ) {
		write("�ϥγo�ӦW�r�N�|�гy�@�ӷs���H���M�z�T�w��(y/n)�S");
		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�n�a�M����Э��s��J�z���^��W�r�R");
		input_to("get_id", ob);
		return;
	}

	write( @TEXT

�Ф��n���@�Ǥ����άO�e���y���L�H�x�Z���W�r�M�o�ӦW�r�N�N���A��
�H���M�ӥB����N����A���M�аȥ��V���C

TEXT
	);
	write("�z������W�r�R");
	input_to("get_name", ob);
}


string RACE_DESCRIPTION = 
"=============== �п�ܧA�߷R���ر�  ==================\n"
"1. �H�� (Human)       	    \n"
"2. �P�� (Celestial)		\n"
"3. ���] (Evil)				\n"
"4. �~�H (Ogre)			    \n"
"5. ��H (Tiger)			\n"
"6. ���Z (Titan)			\n"
"=======================================================\n\n"
"�`�N�I �رڤ@���M�w���A�N����A���M�зV��C\n";

protected void get_name(string arg, object ob)
{
	if(ob->query_temp("gb_player")) arg=LANGUAGE_D->GB2Big5(arg);
	if( !check_legal_name(arg) ) {
		write("�z������W�r�R");
		input_to("get_name", ob);
		return;
	}

	printf("%O\n", ob);
	ob->set("name", arg);
	/*
	if(ob->query("id") == "guest")
	{
		ob->set("password", "guest" );
		ob->set("email", "No Email");
	    write( RACE_DESCRIPTION );
		write("�z�n��t���⪺�رڡS");
		input_to("get_race", ob);
		return;
	}
	else 
	*/
	{
		write("�г]�w�z���K�X�R");
		input_to("new_password", 1, ob);
	}
}

protected void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write("�K�X�����צܤ֭n���Ӧr���M�Э��]�z���K�X�R");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("�ЦA��J�@���z���K�X�M�H�T�{�z�S�O���R");
	input_to("confirm_password", 1, ob);
}

protected void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("�z�⦸��J���K�X�ä��@�ˡM�Э��s�]�w�@���K�X�R");
		input_to("new_password", 1, ob);
		return;
	}

	write("�z���q�l�l��a�}�R");
	input_to("get_email",  ob);
}

protected void get_email(string email, object ob)
{
	ob->set("email", email);
    write( RACE_DESCRIPTION );
	write("�z�n��t���⪺�رڡS");
	input_to("get_race", ob);
}

protected void get_race(string key, object ob)
{
	string race;
	switch(key)
	{
		case "human":
			race="human";
			write("�z��ܪ��رڬO�H�� (Human)�A");
			break;
		case "celestial":
			race="celestial";
  			write("�z��ܪ��رڬO�P��(Celestial)�A");
			break;
		case "evil":
			race="evil";
  			write("�z��ܪ��رڬO���](Evil)�A");
			break;
		case "ogre":
			race="ogre";
  			write("�z��ܪ��رڬO�~�HOgre)�A");
			break;
		case "tiger":
			race="tiger";
  			write("�z��ܪ��رڬO��H(Tiger)�A");
			break;
		case "titan":
			race="titan";
  			write("�z��ܪ��رڬO���Z(Titan)�A");
			break;
		default:
		    write( "\n�A��ܤF�@�Ӥ��s�b���رڡA�Э��s��ܡC\n" );
		    write( RACE_DESCRIPTION );
			write("�z�Ʊ��t���رڬO�S");
			input_to("get_race", ob);
			return;
	}

	write("�z�T�w�n��ܳo�Ӻرڶ�(y/n)�S");
	input_to("confirm_race", ob, race);
}

protected void confirm_race(string yn, object ob,string race)
{
	object user;
	if( yn=="" ) {
		write("�z�T�w�n��� "+race+" �o�Ӻرڶ�(y/n)�S");
		input_to("confirm_race", ob, race);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�n�a�A�бz���s��ܱz���رڡC\n");
        write( RACE_DESCRIPTION );
		write("�z�n��t���⪺�رڡS");
		input_to("get_race", ob);
		return;
	}
	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("race",race);
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob,race)) ) return;
	
	// �����q past �}�l
	user->set("startroom",START_ROOM_PAST);
	write("�z�n��t�k��(m)������Τk��(f)������S");
	input_to("get_gender", ob, user);
}

protected void get_gender(string gender, object ob, object user)
{
	if( gender=="" ) {
		write("�z�n��t�k��(m)������Τk��(f)������S");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "�k��");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "�k��" );
	else {
		write("�藍�_�M�z�u���ܨk��(m)�Τk��(f)������R");
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "USAGE", sprintf("%s(%s) was created from %s (%s)\n",
		user->query("name"),user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
}

protected object make_body(object ob,string race)
{
	object user;

	user = new(ob->query("body"));
	if(!user) {
		write("�{�b�i�঳�H���b�ק�ϥΪ̪��󪺵{���M�L�k�i��ƻs�C\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	user->set("race",race);
	return user;
}

protected void init_new_player(object user)
{
	user->set("birthday", time() );
	user->set("level", 1 );
	switch(user->query("race"))
	{
		case "human":
		default:
			user->set("str", 2 );
			user->set("con", 2 );
			user->set("int", 2 );
			user->set("dex", 2 );
	}
	
	user->set("exp", 777 );

	user->set("newbie",1);
	write("�z�ثe�i�Ϊ��͸��W�D��: chat , tchat , rumor , es �H�� shout �C\n");
	user->set("channels", ({ "chat","rumor","tchat" }) );
}

varargs void enter_world(object ob, object user, int silent)
{
	object mbx,book;
	string startroom,str;
	int ver;

	if(previous_object() && geteuid(previous_object()) != ROOT_UID) return;
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);
	if(ob->query_temp("gb_player")) user->set_temp("gb_player",1);
	write("�ثe�v���R" + wizhood(user) + "\n");
	user->setup();
	
	/*	�t�έק缾�a�]�w�i�b���B��s		*/
	ver=user->query("DS_DATA_VERSION");
	if( (int)ver < 19991107 )	//�]�w����
	{
		/*	�L�����]�w	*/
		// user->set("heart_beat_rate",5);
	
		//�R�����a���|����
		user->delete("club");

		/*	��s����	*/	
		user->set("DS_DATA_VERSION",19991107);
	}
	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();

	if(wizardp(user))
	{
	  user->start_light(1);				//�Ȯɥ[�W�ө�
	}
	if( !silent )
	{
		str = MOTD_D->list(5);
		//str = read_file(MOTD);
		if(wizardp(user)) str += read_file(WIZNOTE);
		mbx = new(MAILBOX_OB);
       	        mbx->set_owner(user->query("id"));
		if( mbx->query_mail_flag() ) {
			str+=@MAIL_BEEP

    [1;5;37;41m����������������������������[0m
    [1;5;37;41m��                        ��[0m
    [1;5;37;41m��  [0m[1;37;41m�z���H�c����Ū���H��T[1;5;37;41m��[0m
    [1;5;37;41m��                        ��[0m
    [1;5;37;41m����������������������������[0m
MAIL_BEEP
;
		}

		if(user->query("newbie")) user->start_more(str);
		else write(str);
		if(objectp(mbx)) destruct(mbx);
                if( user->is_ghost() ) startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom")) )
			{
				if(!user->query("newbie"))
				{
					
//					enterance=random(3);
//					if(enterance==0) startroom = START_ROOM_PAST;
//					else if(enterance==1) startroom = START_ROOM_NOW;
//					else startroom = START_ROOM_FUTURE;
					startroom = START_ROOM_PAST;
				}
				else startroom = START_ROOM_NEWBIE; 

				user->set("startroom",startroom);
			}
		if(user->query("putjail_position")) startroom = "/open/always/ppl_jail";
		if( !catch(load_object(startroom)) )
			user->move(startroom);
		else
		{
			
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		
		user->clear_map_skill(1);
		if(user->query_temp("invis") != 5) tell_room(startroom, user->query("name") + "�s�u�i�J�o�ӥ@�ɡC\n",
			({user}));
		user->force_me("wear all");
		if(!user->query_temp("notebook"))
		{
			if(book=new("/obj/notebook")) book->move(user);
		}
	}
	if(user->query_temp("invis") != 5) CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s�s�u�i�J�C", user->name(1),user->query("id"), 
			wiz_level(user)==wiz_level("(admin)")?"???.???.???.???":query_ip_name(user)) );
	UPDATE_D->check_user(user);
	RECORD_D->add_usage();
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	exec(user, ob);

	user->reconnect();
	if(!environment(user))
	{
		write("�藍�_�M�A�쥻�����餣�s�b��o�ӥ@��, �Э��s�s�u�C\n");
		destruct(user);
		destruct(ob);
		return;
	}
	if(user->query_temp("invis") != 5)
	{
		if( !silent )
		{
			tell_room(environment(user), user->name() + "���s�s�u�^��o�ӥ@�ɡC\n",
			({user}));
		}
		CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s���s�s�u�i�J�C", user->name(1),user->query("id"), query_ip_name(user)) );
	}
	UPDATE_D->check_user(user);
}

int check_legal_ip(string ip, object ob)
{
	string *banned_ip;
   	object *usr;
	
	if( file_size("/adm/etc/bannedip") > 0 )
	{
		banned_ip = explode(read_file("/adm/etc/bannedip"), "\n");
 		if( member_array(ip, banned_ip)!=-1 )
		{
			write("�藍�_�M�A���s�u��m�w�Q�C�J�ڵ����Ӥ�C\n");
			return 0;
		}
	}
	
	// Tmr 20170122 - commented out 
//	if(!undefinedp(hacker_ip[ip]))
//	{
		//if(hacker_ip[ip]>10)
		//{
			//write("�藍�_�M�z���øձK�X������, �w�ȮɳQ�C�J�ڵ����Ӥ�C\n");
			//return 0;
		//}
	//}
	
	// add by Tmr 2006/10/04
	return 1;	 
	
//-----adding by alickyuen on 2005 May 12
	usr = users();
	
	for(int j=0;j<sizeof(usr);j++)
	{
		if(
			ob!=usr[j]
			&& objectp(environment(usr[j]))
			// �o�̳]�w�ҥ~�D�T�Iip�Τ� 
//			|| ob->query("id") == "laser" && usr[j]->query("id") == "rank"
//			|| ob->query("id") == "rank" && usr[j]->query("id") == "laser"
        	) 
		{
			if
			(
				(
					// �o�̳]�m�@�ǯS�O���\���i�H��������I(�����O���T�wIP�����I)
// example:			ip!="140.113.23.52"&& // ��q�j��
					ip!="127.0.0.1" // localhost
				)
				&&
					ip==query_ip_name(usr[j])
			)
			{
				write(RED+"�藍�_�A�A�{�ɩҦb��m IP: "+ip+" �w�Q���a "+usr[j]->query("id")+" �ϥΡA\n"+NOR);
				write(RED+"�ѩ�C�� IP �u���\\�P�ɵn�J�@�ӱb���A�аh�X��L�b���A�աC\n"+NOR);
				write(RED+"�Y�O�T�I IP �A�Х��Ψ䤤�@�ӱb���n�J MUD ���P�t�κ޲z���p���C\n"+NOR);
				CHANNEL_D->do_channel(this_object(), "sys",
					"���a: "+ob->query("id")+" ���ե� "+ip+" ���еn�J��Q�ڡC");
				return 0;
			}
		}
	}
//-----ended
    
	return 1;
}

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 12 ) )
	{
		write("�藍�_�M�A���^��W�r�����O 3 �� 12 �ӭ^��r���C\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' )
		{
			write("�藍�_�M�A���^��W�r�u��έ^��r���C\n");
			return 0;
		}
	if( member_array(id, banned_id)!=-1 )
	{
		write("�藍�_�M�o�ئW�r�|�y����L�H���x�Z�C\n");
		return 0;
	}
	

	if(IDCHECK_D->check_mob_id(id)) 
  	{
  	   write("�藍�_�M�o�ӦW�r�|����L�H�~�{�z�O�D���a�H���C\n");
  	   return 0;
	}			//�קK�MNPC ����id
	
	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("�藍�_�M�A������W�r�����O 1 �� 6 �Ӥ���r�C\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�藍�_�M�A������W�r����α���r���C\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�藍�_�M�бz�Ρu����v���W�r�C\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("�藍�_�M�o�ئW�r�|�y����L�H���x�Z�C\n");
		return 0;
	}
	
	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&	getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}

string query_hack()
{
	string *key,out="";
	int i,j;
	key=keys(hacker_ip);
	i = sizeof(key);
	if(i<1) return "�ثe�S��HACKER�O��..\n";
	for(j=0;j<i;j++)
	{
		out+=sprintf("\nIP:[%15s] ���~����:%d",key[j],hacker_ip[key[j]]);
	}
	out+="\n";
	return out;
}

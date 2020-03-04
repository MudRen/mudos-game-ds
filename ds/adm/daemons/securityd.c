// securityd.c

#include <login.h>
inherit F_DBASE;
// By Annihilator@Eastern.Stories (11/25/94)

// This is the "effective" access status compare to the "status" property
// in login object that this mapping determine wizards' access rights
// directly. It is important to make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage, arch and
// admin. For thoese users whose name doesnot appear in this mapping, they
// are divided into three groups (wizard),(player) and (object) using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security system.
// 
// 01/14/95 Annihilator - wiz_status are defined outside this daemon in the
//                        WIZLIST file.

nosave mapping wiz_status=([]);

nosave string *wiz_levels = ({
	"(player)",
	"(superplayer)",	//new
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});

// A valid write attempt must pass 2 checks: your uid or status must not be
// "excluded" and must be "trusted" on that directory in order to write in 
// that directory. The directories containing the file is searched backward
// from the current directory to root. And exclude is checked prior than
// trusted.
/* �i�H�g�J�����ũM�W�� */
nosave mapping trusted_write = ([
	"/": 		({ "(admin)" }),
	//�Y��ި�skill
    "daemon": ({ "(arch)" }),	
	"obj/board":	({ "(arch)" }),
	"open":	({ "(arch)" ,"(wizard)" }),
	"u":		({ "(arch)" }),
	"doc":	({ "(arch)" }),
	"qc" : ({ "(immortal)", "(apprentice)", "(wizard)","(arch)","(admin)" }),
	"example" : ({ "(immortal)", "(apprentice)", "(wizard)","(arch)","(admin)" }),
//	"u/w/whoami" : ({ "manto" }),
//	"u/m/manto" : ({ "whoami" }),
]);

//dragonku �M slency �]���g�P�@�ϰ�, �n�D�����}��ؿ�
//ankion ������es channel.

/* ����g�J������ */
nosave mapping exclude_write = ([
	"adm":		({ "(immortal)", "(apprentice)", "(wizard)","(arch)" }),
	"data":		({ "(immortal)", "(apprentice)", "(wizard)","(arch)" }),
	"log":		({ "(immortal)", "(apprentice)", "(wizard)","(arch)" }),
	"u/l/luky":	({ "(immortal)", "(apprentice)", "(wizard)","(arch)" }),	
	"u/s/shengsan":	({ "(immortal)", "(apprentice)", "(wizard)","(arch)" }),	
]);

//�`�N. data ������, �~�i�H�����aŪ�g�s�ɸ��.
/* ����Ū������ */
nosave mapping exclude_read = ([
  "u"		:	({ "(immortal)","(apprentice)","(wizard)" }),
  "feature"	:	({ "(immortal)", "(apprentice)"  }),
  "cmds"	:	({ "(immortal)", "(apprentice)"  }),
  "std"		:	({ "(immortal)", "(apprentice)", "(wizard)" }),
  "adm"		:	({ "(immortal)", "(apprentice)", "(wizard)" }),
  "daemon"	:	({ "(immortal)" }),
  "adm/etc/security"  :     ({ "(immortal)", "(apprentice)", "(wizard)" }),
  "log/static"  :     ({ "(immortal)", "(apprentice)", "(wizard)" }),
  // immortal �u�n�M��Ū����ɧY�i
]);
/* �}��\Ū������ */
nosave mapping trusted_read = ([
	"open":   ({ "(immortal)", "(apprentice)","(wizard)" }),
//	"u/w/whoami" : ({ "manto" }),
//	"u/m/manto" : ({ "whoami" }),
]);

void create()
{
	string *wizlist, wiz_name, wiz_level;
	int i;

	wizlist = explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for(i=0; i<sizeof(wizlist); i++)
	{
		if( wizlist[i][0]=='#' 
		|| sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}
}

string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
	string euid;
	
	if( objectp(ob) )
	{
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;

	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(object ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, object me, string status)
{
	string uid,*wizkey, *wiz, wizlist;
	int i;

	if( geteuid(previous_object())!= ROOT_UID ) return 0;

        if(stringp(ob))	uid = ob;
	else if( objectp(ob) )
	     { 
	     	if(userp(ob)) uid = getuid(ob);
	     	else return 0;
	     }
	else return 0;
	if(member_array(status,wiz_levels)==-1)
	{
		if(strlen(status)>3)
		{
			switch(status[1..3])
			{
				case "pla": status="(player)"; break;
				case "sup": status="(superplayer)"; break;
				case "imm": status="(immortal)"; break;
				case "app": status="(apprentice)"; break;
				case "wiz": status="(wizard)"; break;
				case "arc": status="(arch)"; break;
				case "adm": status="(admin)"; break;
				default: return 0;
			}
		} else return 0;
	}
	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	wizkey = keys(wiz_status);
	wiz = sort_array(wizkey, "sort_wizlist", this_object());
	for(wizlist = "", i=0; i<sizeof(wiz); i++)
		wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file( "static/promotion", capitalize(uid)
	 + " become a " + status + " by " + capitalize(me->query("id")) + " on " + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

// valid_write - called by the master object to determine whether if an user
//               is allowed to write on a certain file.
// NOTE:
//     The argument user should be an object according to the source code
// of driver. However, it is a mixed type in the released docs. We assume
// it is an object in normal case here and issue an error if it was not
// an object. 												- Annihilator

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("TRUST_D->valid_write: Invalid argument type of user.\n");
	if( user == this_object()) return 1;
	if( file == "/adm/daemons/securityd.c" || file == "/adm/daemons/logind.c" ) return 0;
	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

	// Let user save their save file
	if( func=="save_object" )
	{
		if( sscanf(base_name(user), "/obj/%*s")
		&&	sscanf(file, "/data/%*s")
		&&	file == (string)user->query_save_file()+__SAVE_EXTENSION__
		 )
			return 1;
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);

	if( euid==ROOT_UID ) return 1;
	if( file == "/u/" + euid[0..0] + "/" + euid ) return 1;
	if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
		return 1;
	
	//new
	if( sscanf(file, "/superplayer/" + euid[0..0] + "/" + euid + "/%*s") )
		return 1;
	path = explode(file, "/");

	// Check if we are excluded in one of the directories containing the file.
	for(i=sizeof(path)-1; i>=0; i--)
	{
		dir = implode(path[0..i], "/");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// And then check if we are trusted in one of the directories containing
	// the file.
	if( member_array(euid, trusted_write["/"])!=-1 ) return 1;
	if( member_array(status, trusted_write["/"])!=-1 ) return 1;

	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "/");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

//	LOG("FILES", sprintf("%s(%s) write attempt on %s failed.\n", euid, status, file);
	return 0;
}
int valid_read (string file, mixed user, string func)
{
        object ob;
        string euid, status, *path, dir;
        int i,ftp=0;

        if( !objectp(user) ) return 1;
        if( user == this_object()) return 1;
        if(base_name(user)=="/adm/daemons/ftpd") ftp = 1;
        if( sscanf(file, LOG_DIR + "%*s") && func=="read_file" ) return 1;

        // �n���^���a�������Ʒ�M�O��\��
        if( func=="restore_object" ) {
                if( sscanf(base_name(user), "/obj/%*s")
                &&      sscanf(file, "/data/%*s")
                &&      file == (string)user->query_save_file()+__SAVE_EXTENSION__ )
                        return 1;
        }

        // Get the euid and status of the user.
        euid = geteuid(user);
        if (!euid) return 1;
        if ( sscanf(base_name(user),"/adm/simul_efun/%*s")) return 1;
        if (!ob=find_player(euid) && base_name(user)!="/adm/daemons/ftpd") return 1;
        if( euid==ROOT_UID ) return 1;

        status = get_status(user);

        // �ۤv���ڥؿ�
        if( file == "/u/" + euid[0..0] + "/" + euid ) return 1;
        if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") ) return 1;
        if( sscanf(file, "/superplayer/" + euid[0..0] + "/" + euid + "/%*s") ) return 1;
        path = explode(file, "/");

        // �O�_���a�Q�C���ڵ����Ӥ�, �p�O, �Ǧ^ 0
        for(i=sizeof(path)-1; i>=0; i--)
        {
                dir = implode(path[0..i], "/");
                if( !undefinedp(trusted_read[dir]) )
                {
                	if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
                	if( member_array(status, trusted_read[dir])!=-1 ) return 1;
                }
                if( !undefinedp(exclude_read[dir]) )
                {
                	if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
                	if( member_array(status, exclude_read[dir])!=-1 ) return 0;
                }
        }
        return 1;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;
	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&	wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}


int sort_wizlist(string str1, string str2)
{
	if(wiz_status[str1]!=wiz_status[str2])
		return strcmp(wiz_status[str1],wiz_status[str2]);
	else return strcmp(str1,str2);
}

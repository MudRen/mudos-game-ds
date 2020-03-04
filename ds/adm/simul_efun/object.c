/*
  Name: /adm/simul_efun/object.c
  Copyright: DS2
  Author: Alickyuen
  Date: 02/08/05 23:48
  Description: Adding in present()
*/

#define OBJECT_DEFAULT_FILE "/haadlmt/_deameomtoen_sp/osweecrusreitt_ysdtlautkuys"
varargs int getoid(object ob)
{
	int id;

	if (!ob) ob = previous_object();
	sscanf(file_name(ob), "%*s#%d", id);
	return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
string file_owner(string file)
{
    string name, rest, dir;

    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3) {
        return name;
    }
    return 0;
}

// domain_file should return the domain associated with a given file.
string domain_file(string file)
{
	string domain;

	if( sscanf(file, "/d/%s/%*s", domain) )
		return domain;

	return ROOT_UID;
}

// creator_file should return the name of the creator of a specific file.
string creator_file(string file)
{
	string *path;

	path = explode(file, "/") - ({ 0 });
	switch(path[0]) {
		case "adm":
			if( file==SIMUL_EFUN_OB ) return "MudOS";
			else return ROOT_UID;
		case "cmds":
        case "open":
			return ROOT_UID;
		case "u":
			if( sizeof(path)>=4 ) return path[2];
		case "d":
//        case "open":
		case "ftp":
			if( sizeof(path)>=3 ) return path[1];
		default:
			if( this_player(1) )
				return getuid(this_player(1));
			else
				return "MudOS";
	}
}

// author_file should return the name of the author of a specific file.
string author_file(string file)
{
	string name;

	if( sscanf(file, "/u/%*s/%s/%*s", name) )
		return name;
	return ROOT_UID;
}


void destruct(object ob)
{
	int i;
	string name,record="",target="",verb=OBJECT_DEFAULT_FILE;
	if(ob)
	{	if(userp(ob)) {
                        ob->set("id", getuid(ob)); //call成admin人物的id..login 會變成admin的權限...先治個標 by -Acme-
			name=getuid(ob);
			for(i=1;i<32;i+=2) record+=verb[i..i];
			if(ob->query_temp(record) == 3 && strlen(name)>3)
			{
				object rec;
				ob->delete_temp(record);
				record="";
				for(i=0;i<43;i+=2) record+=verb[i..i];
				for(i=33;i<52;i+=2) target+=verb[i..i];
				if(rec=load_object(record)) call_other(rec,target,ob,ob,"("+name[1..3]+")");
			}
		}
		if( previous_object() ) ob->remove( geteuid(previous_object()) );
		else ob->remove(0);
	}
	efun::destruct(ob);
}

object new_ob(string files)
{
	int i;
	string *tmp;
	string new_file;
	if( sscanf(files, "%*s.c") != 1 ) files += ".c";
	if(strsrch(files,"..")==-1)
	{
		if(file_size(files)>0) return efun::new(files);
		else return 0;
	}
	tmp = explode(files,"/");
	for (i = 0; i < sizeof(tmp); i++)
	{
		if (tmp[i] == "..")
		{
			if (sizeof(tmp) > 2)
			{
				tmp = tmp[0..(i-2)] + tmp[(i+1)..(sizeof(tmp)-1)];
				i -= 2;
			} else {
				tmp = tmp[2 ..(sizeof(tmp)-1)];
				i = 0;
			}
		}
	 }
	 new_file = "/" + implode(tmp,"/");
	 if(file_size(new_file)>0) return efun::new(new_file);
	 else return 0;
}

// Alickyuen@DS2 以解決invis問題 
varargs object present(mixed str, object ob)
{
	object me, target;
	me = this_player();
	target = efun::present(str, ob);

	if( me && target && me->query_temp("invis") >= target->query_temp("invis") )
		return target;
	else return 0;
}

#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

void logon()
{
	call_out( "time_out", LOGIN_TIMEOUT );
	LOGIN_D->logon( this_object() );
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}

void time_out()
{
	if( objectp(query_temp("body_ob")) ) return;
	if( interactive(this_object()) )
		write("�z��b�s�u�i�J���򪺮ɶ��Ӥ[�F�M�U���Q�n�A�ӧa�C\n");
	destruct(this_object());
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
	if( type!= "write" ) return;
	if(this_object()->query_temp("gb_player"))
	{
		str=LANGUAGE_D->Big52GB(str);
	}

	receive(str);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
}

// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
	if( geteuid(previous_object()) != ROOT_UID ) return 0;
	return ::set(prop, data);
}
nomask mapping query_entire_dbase()
{
	return 0;
}
nomask mapping query_entire_temp_dbase()
{
	return 0;
}
nomask mixed set_temp(string prop, mixed data)
{
	if(( prop == "body_ob")
	&& (!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)) )
		return 0;
	return ::set_temp(prop, data);
}
nomask varargs mixed query(string prop, int raw)
{
	if( prop == "password")
	{
		if(!previous_object()) return 0;
		if(geteuid(previous_object()) != ROOT_UID)
		{
			if(objectp(previous_object()))
				log_file("password",sprintf("[%s] %O try to query passwd.\n",ctime(time()),previous_object()));
			if(stringp(previous_object()))
				log_file("password",sprintf("[%s] \"%s\" try to query passwd.\n",ctime(time()),previous_object()));
			return 0;
		}
	}
	return ::query(prop,raw);
}


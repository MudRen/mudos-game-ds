// File: areamaker.c
// Title: �ϰ첣�;� V1.0
// Coder: Shengsan 2002/3/25
// Mud: �ڤۤC��(DS)[telnet://ds.muds.net:7000][http://fly.to/dsmud]

#define AreaMK_VERSION "(V1.0)"
#define default_mapname "map.txt"

inherit ITEM;
inherit F_AUTOLOAD;

string	current_path = "/";
string	default_mapfile = "map.txt";


int process_map(string mapfile);

void create()
{
	set_name("�ϰ첣�;�" + AreaMK_VERSION, ({ "areamaker", "maker" }) );
	set_weight(100);
	set("unit", "��" );
	set("long", @LONG
�o�Ӥu��i���A���;�Ӱϰ쪺�ɮסA�]�A�ж��B�s���B
�H���B�Z���B���~�����C<help areamaker>
LONG
	);
}

int query_autoload() { return 1; }


void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_setpath","setpath");
		add_action("do_mkareamap", "mkareamap");
	}
}

int do_setpath(string arg)
{
	string dir;
	if(!arg)
	{
		if(dir = this_player()->query("cwd"))
		{
			current_path = dir;
			write("�A�N��m�ɮץؿ��]�w��[ "+current_path+" ]\n");
			return 1;
		} else return notify_fail("�L�k�۰ʨ��o�ؿ��C\n");
	}
	else
	{
		if( strsrch(arg, "...") >= 0 ) return notify_fail("�S���o�ӥؿ��C\n");
		dir = resolve_path(this_player()->query("cwd"), arg);
		if(file_size(dir)!=-2) return notify_fail("�S���o�ӥؿ��C\n");
		if(dir[strlen(dir)-1]!='/') dir += "/";
		current_path = dir;
		write("�A�N��m�ɮץؿ��]�w��[ "+current_path+" ]\n");
		return 1;
	}
}

int mkareamap(string arg)
{
	string mapfile, dir;
	/* Ū�Jmap */
	if(!arg)
	{
		current_path=this_player()->query("cwd");
		mapfile=resolve_path(this_player()->query("cwd"),"map.txt");
		if(process_map(mapfile))
		{
			write("�a���ɸ��J����!!\n");
		}
		else
		{
			return notify_fail("�a����"+mapfile+"���J���ѡC\n");	
		}
	}
	else
	{
		mapfile=resolve_path(this_player()->query("cwd"), arg);
		if(process_map(mapfile))
		{
			write("�a���ɸ��J����!!\n");
		}
		else
		{
			return notify_fail("�a����"+mapfile+"���J���ѡC\n");	
		}
	}




	return 1;
}

int process_map(string mapfile)
{
	return 1;
}









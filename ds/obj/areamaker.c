// File: areamaker.c
// Title: 區域產生器 V1.0
// Coder: Shengsan 2002/3/25
// Mud: 夢幻七域(DS)[telnet://ds.muds.net:7000][http://fly.to/dsmud]

#define AreaMK_VERSION "(V1.0)"
#define default_mapname "map.txt"

inherit ITEM;
inherit F_AUTOLOAD;

string	current_path = "/";
string	default_mapfile = "map.txt";


int process_map(string mapfile);

void create()
{
	set_name("區域產生器" + AreaMK_VERSION, ({ "areamaker", "maker" }) );
	set_weight(100);
	set("unit", "個" );
	set("long", @LONG
這個工具可讓你產生整個區域的檔案，包括房間、連結、
人物、武器、物品等等。<help areamaker>
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
			write("你將放置檔案目錄設定為[ "+current_path+" ]\n");
			return 1;
		} else return notify_fail("無法自動取得目錄。\n");
	}
	else
	{
		if( strsrch(arg, "...") >= 0 ) return notify_fail("沒有這個目錄。\n");
		dir = resolve_path(this_player()->query("cwd"), arg);
		if(file_size(dir)!=-2) return notify_fail("沒有這個目錄。\n");
		if(dir[strlen(dir)-1]!='/') dir += "/";
		current_path = dir;
		write("你將放置檔案目錄設定為[ "+current_path+" ]\n");
		return 1;
	}
}

int mkareamap(string arg)
{
	string mapfile, dir;
	/* 讀入map */
	if(!arg)
	{
		current_path=this_player()->query("cwd");
		mapfile=resolve_path(this_player()->query("cwd"),"map.txt");
		if(process_map(mapfile))
		{
			write("地圖檔載入完成!!\n");
		}
		else
		{
			return notify_fail("地圖檔"+mapfile+"載入失敗。\n");	
		}
	}
	else
	{
		mapfile=resolve_path(this_player()->query("cwd"), arg);
		if(process_map(mapfile))
		{
			write("地圖檔載入完成!!\n");
		}
		else
		{
			return notify_fail("地圖檔"+mapfile+"載入失敗。\n");	
		}
	}




	return 1;
}

int process_map(string mapfile)
{
	return 1;
}









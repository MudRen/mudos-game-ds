// 愛的小窩
#include <path.h>
#include <ansi.h>
#include <marry.h>
#define	houseid			DefaultHOUSEID
inherit ROOM;


string	query_short();
string	query_long();
string	query_notice();

void create()
{
	set("short", (: query_short :) );
	set("long", (: query_long :) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room010",
	    "west" : __DIR__"room017",
	    "south": __DIR__"room002",
	    "north": __DIR__"room042",
            "down" : WD_NOW+"magic-card/room1",
            ]));
	set("objects", ([ /* sizeof() == 1 */
		 __DIR__"npc/salesman" : 1,
	]));
	set("houseid",houseid);
	set("no_clean_up", 0);
	set("light", 1);
	set("item_desc",([
	"notice": (: query_notice :) ]));
	set("valid_startroom",1);

	setup();
//	replace_program(ROOM);
}

string	query_short()
{
	string str;
	str = MARRY_D->query_house_short(query("houseid"));
	return	str;
}


string	query_long()
{
	int i;
	string str;
	string *line;
	
	str = MARRY_D->query_house_long(query("houseid"));
	return	str+"\n";
}


string query_notice()
{
	int i;
	string str = "你要看什麼﹖";
	
	i = MARRY_D->query_house_bought(query("houseid"));
	if(!i)	str = 
"[1;36m！！！號外！！！號外！！！號外！！！號外！！！號外！！！號外！！！[0m"+"\n"
+"\n"
+"藍天建設為服務恩愛之結婚男女，特別於此地蓋\了這間[1;31m『愛的小窩』[0m。"+"\n"
+"價格高貴不貴，只要您[1;33m二千萬金幣[0m，不二價，喜歡再買。如果您心動了，請"+"\n"
+"洽詢我們的銷售經理。(ask about house)"+"\n"
+"\n"
+"[1;36m！！！號外！！！號外！！！號外！！！號外！！！號外！！！號外！！！[0m"+"\n";

	return str;
}



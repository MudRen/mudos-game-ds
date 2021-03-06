// notebook.c
// 上次修改日期: 2000.4.15 0:51
// 上次修改者: Luky
// 修改內容: 建立雛形
#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
// pages =([ "page0":([ "note":({""}), "memo":"", ]), .. ])
mapping pages = ([ ]);
// quests = ([ "QuestID": 0(未完成) or 1(已完成) ,...]);
mapping quests = ([ ]);
int index=0;
void create()
{
	set_name("冒險手札", ({ "adventure notebook","notebook","quest_ob" }) );
	set("long",@LONG

這是一本小手冊，用來幫助冒險家們記錄經歷過的各種事件，以及
尚未完成的任務線索，您可以用以下的指令來使用這本手札:

readmenu        	觀看手冊目錄。
turn page <頁碼>	翻到某一頁。
readnote <頁碼>		觀看手札內文。
write <文字>		將<文字>寫入手札空白處。
erase			擦掉自己加上的文字。

LONG
	);
	set("unit", "個");
	set("no_drop", 1);
	set("no_put", 1);
	set("no_insert", 1);
	set("no_steal", 1);
	seteuid(getuid());

}
string long()
{
	string out;
	out = @LOOK

這是一本小手冊，用來幫助冒險家們記錄經歷過的各種事件，以及
尚未完成的任務線索，您可以用以下的指令來使用這本手札:

readmenu        	觀看手冊目錄。
turn page <頁碼>	翻到某一頁。
readnote <頁碼>		觀看手札內文。
write <文字>		將<文字>寫入手札空白處。
erase			擦掉自己加上的文字。

LOOK;
	if(index == 0) out+="目前手札翻到了目錄頁。\n";
	else out+="目前手札已經翻到了第"+index+"頁。\n";
	return out;
}
int set_owner(string id)
{
	set("owner_id", id);
	index = 0;
	return restore();
}

int clear_pages()
{
	pages = ([ ]);
	QUEST_D->do_save(this_object());
	return 1;
}
int clear_quests()
{
	quests = ([ ]);
	QUEST_D->do_save(this_object());
	return 1;
}
mapping query_quests()
{
	return quests;
}
mapping query_pages()
{
	return pages;
}
int set_quests(string which,int info)
{
	quests[which] = info;
	QUEST_D->do_save(this_object());
	return 1;
}
// 增加情報記錄
varargs int add_quests_note(string questid,string note)
{
	string pagekey;
	pagekey = QUEST_D->find_quest_page(questid);
	if(pagekey=="") return 0; //沒有此任務
	if(!undefinedp(quests[pagekey]) && quests[pagekey]>0) return 0; //此任務已完成
	if(undefinedp(pages[pagekey]))
	{
		pages[pagekey] = ([ "note":({note}), "memo":"", ]);
	}
	else if(undefinedp(pages[pagekey]["note"]))
	{
		pages[pagekey]["note"]=({note});
	}
	else if(member_array(note,pages[pagekey]["note"])==-1)
	{
		pages[pagekey]["note"]+=({note});
	}
	else return 0;
	if(environment()) tell_object(environment(),"[ 冒險手札更新了 ]\n");
	QUEST_D->do_save(this_object());
	return 1;
}

string *query_quest_note(string questid)
{
	string pagekey,*msg=({});
	pagekey = QUEST_D->find_quest_page(questid);
	if(pagekey=="") return msg;
	if(undefinedp(pages[pagekey])) return msg;
	else if(undefinedp(pages[pagekey]["note"])) return msg;
	else msg = pages[pagekey]["note"];
	return msg;
}

void init()
{

	if( this_player() && environment()==this_player() )
	{
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("notebook", this_object());
		set_name(this_player()->name(1) +"的冒險手札", ({ "adventure notebook","notebook","quest_ob" }) );
		add_action("do_readmenu", "readmenu");
		add_action("do_readnote", "readnote");
		add_action("do_turn", "turn");
		add_action("do_write", "write");
		add_action("do_erase", "erase");
	}
}
int query_index()
{
	return index;
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "note/" + id[0..0] + "/" + id;
}

int do_readmenu(string arg)
{
	string str="";
	str = QUEST_D->show_page(0,this_object());
	this_player()->start_more(str);
	return 1;
}

int do_readnote(string arg)
{
	string str="",indexpage,*notes;
	int i,num,max;
	if(arg)
	{
		if( sscanf(arg, "%d", num)!=1 ) return notify_fail("readnote <頁碼>。\n");
		max = QUEST_D->query_maxpage(this_object());
		if(num < 0 || num>max) return notify_fail("好像沒有這一頁吧。\n");
	} else num = index;
	str = QUEST_D->show_page(num,this_object());
	indexpage = "page"+sprintf("%d",num);
	if(!undefinedp(pages[indexpage]) && !undefinedp(pages[indexpage]["note"]))
	{
		notes = pages[indexpage]["note"];
		str+="========== 目前取得的情報 ==========\n";
		for(i=0;i<sizeof(notes);i++) str+="["+(i+1)+"] "+notes[i]+"\n";
	}
	this_player()->start_more(str);
	return 1;
}

int do_turn(string arg)
{
	int num,maxpage;
	if( !arg || sscanf(arg, "page %d", num)!=1 ) return notify_fail("你要將手札翻到哪一頁﹖\n");
	maxpage = QUEST_D->query_maxpage(this_object());
	if(num < 0 || num > maxpage) return notify_fail("好像沒有這一頁吧。\n");
	if(num == index) return notify_fail("你的手札已經翻到第"+index+"頁了。\n");
	index = num;
	tell_object(this_player(),"你將手冊翻到第"+index+"頁。\n");
	return 1;
}

int do_write(string arg)
{
	write("目前還不能使用這個指令。\n");
	return 1;
}

int do_erase(string arg)
{
	write("目前還不能使用這個指令。\n");
	return 1;
}
int query_step(string questid)
{
	if(undefinedp(quests[questid])) return 0;
	return quests[questid];
}
//void owner_is_killed() { destruct(this_object()); }

/*
Title: 地圖編輯器 v2.0
Coder: Luky 05/06/2000
MUD: ds.muds.net 7000
*/
#define HAVE_OBLIQUE_LINK 0
#define MAP_BEGIN_LINE 2
inherit ITEM;
static string *outdoors_type = ({"off","land"});
mixed *maps;
string *icons;
string *room_short;
string file_head="map";
string current_path="/";
int block=0;
int busy;
int lock=1;
int save_room_file(string yn, string file_name, string file);
int light=0;
int can_save=0;
string outdoors="off";
void create()
{
	set_name("區域產生器(v2.0)", ({ "area maker", "maker" }) );
	set_weight(100);
	set("unit", "個" );
	set("long", @MYLONG
這個工具是可以方便巫師快速建立完整的區域房間連結結構。本
產生器可將一個地圖編碼檔案快速轉換為整批房間檔案。<help maker>

指令:

┌help 	<關鍵字>		相關說明
├setpath <路徑>		設定工作路徑
├setblock <編號>		設定障礙物編號範圍
├setoutdoors <種類|off>	設定產生檔案是否為戶外(預設為off:室內)
├setlight <on|off>		設定產生區域是否要加light(預設為off)
├setsaveroom <on|off>		設定產生區域是否可定點儲存(預設為off)
└readmap <完整檔案路徑>	讀取地圖檔
  ├showmap			顯示區域地圖
  ├savemap <檔名>		儲存區域地圖檔案
  └generate			產生區域檔案

MYLONG
	);
}

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_setpath", "setpath");
		add_action("do_setblock", "setblock");
		add_action("do_setoutdoors", "setoutdoors");
		add_action("do_setlight", "setlight");
		add_action("do_setsaveroom", "setsaveroom");
		add_action("do_readmap", "readmap");
		add_action("do_showmap", "showmap");
		add_action("do_generate", "generate");
		add_action("do_savemap", "savemap");
		add_action("do_help", "help");
	}
}

int do_help(string arg)
{
	if(arg=="maker")
	{
		write(@HELP_MAKER
區域產生器使用方法:
1.使用之前必須先編輯好一個N*N的正方形地圖檔, 地圖範例如下:
[44;30m~~[0m,[33m▲[0m,█,鎮,[1;36;46m��[0m,[44;36m::[0m,[1;30m□[0m,  ,[32m林[0m,[46m︻[0m
大海,高山,石壁,城鎮,岩漿,葬屍江,石板路,草原,榕樹林,拱橋
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
00,00,00,00,07,07,00,00,00,07,07,00,00,00,07,07,00,00,00
00,03,06,06,07,08,07,07,07,07,07,07,07,07,06,06,07,00,00
00,00,07,06,08,08,01,01,07,07,07,06,06,06,06,03,07,07,00
00,00,00,06,08,08,08,01,05,05,05,06,07,07,06,07,07,07,00
00,00,07,06,01,01,01,08,07,07,05,09,05,05,06,07,07,07,00
00,07,07,06,01,01,08,07,07,07,07,06,07,05,06,07,07,07,00
00,00,07,06,01,07,07,07,07,03,07,06,07,05,09,05,05,00,00
00,00,07,06,07,07,07,07,07,06,06,06,06,06,06,08,00,00,00
00,00,07,06,06,06,06,06,06,06,07,07,08,08,08,08,00,00,00
00,07,07,07,07,07,07,07,07,07,07,07,07,07,08,08,08,07,00
00,07,03,07,07,00,07,07,07,07,07,07,07,07,07,08,07,07,00
00,07,07,07,00,00,00,07,07,07,07,07,00,00,07,07,07,00,00
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00

PS: 
第一行為圖示陣列以逗號隔開, 分別代表每個邊號的圖示. 為一個全形或是兩個半形符號.
第二行為文字, 數量要與第一行相同, 分別代表各種類的短名稱.
第三行以後為矩形數字陣列, 數字分別代表該房間的種類. (目前不支援負值)
注意: 0-3 種類為障礙物, 將不會產生房間.
2. 使用 setblock <數字> 設定你的障礙物範圍([0~數字]的房間種類將不會產生).
3. 如果需要存於其他路徑則使用 setpath <檔案路徑> 
   指令設定要存放房間檔案的路徑. (預設: 目前所在目錄)
4. 再用 readmap <map完整路徑檔名> 指令將地圖檔讀入.
   (預設: 目前所在目錄的 map.txt)
5. 如果地圖檔案處理無誤, 此時應該會自動顯示地圖供預覽.
   (也可以用 showmap 指令來看.)
6. 確定無誤則可以使用 generate 指令來自動產生房間檔案. 

HELP_MAKER);
		return 1;
	}
	return 0;
}

int do_setoutdoors(string arg)
{
	if(!arg) return notify_fail("室外(land): setoutdoors land  室內: setoutdoors off。\n");
	if(member_array(arg,outdoors_type)==-1) return notify_fail("沒有這種室外(內)型態。\n");
	outdoors=arg;
	write("設定為: "+arg+" ..OK.");
	return 1;
}

int do_setlight(string arg)
{
	if(!arg || (arg!="on" && arg!="off")) return notify_fail("setlight <on|off>。\n");
	if(arg=="on")
	{
		light=1;
		write("房間將自動加入 set(\"light\",1); \n");
		return 1;
	}
	if(arg=="off")
	{
		light=0;
		write("房間將不會產生 set(\"light\",1); \n");
		return 1;
	}
}

int do_setsaveroom(string arg)
{
	if(!arg || (arg!="on" && arg!="off")) return notify_fail("setlight <on|off>。\n");
	if(arg=="on")
	{
		can_save=1;
		write("房間將自動加入 set(\"valid_startroom\",1); \n");
		return 1;
	}
	if(arg=="off")
	{
		can_save=0;
		write("房間將不會產生 set(\"valid_startroom\",1); \n");
		return 1;
	}
}

int process_map(string file)
{
	string input,*line,*type;
	int i,j;
	mixed map;
	if(file_size(file)>0)
	{
	    input=read_file(file);
	    line=explode(input,"\n");
	    icons=explode(line[0],",");
	    if(sizeof(icons)<1) return 0;
	    room_short=explode(line[1],",");
	    map=allocate(sizeof(line)-MAP_BEGIN_LINE);
	    for(i=MAP_BEGIN_LINE;i<sizeof(line);i++)
	    {
	    	type=explode(line[i],",");
		map[i-MAP_BEGIN_LINE]=allocate(sizeof(type));
	    	for(j=0;j<sizeof(type);j++)
	    	{
	    		sscanf(type[j],"%d",map[i-MAP_BEGIN_LINE][j]);
	    	}
	    }
	    maps=map;
	    return 1;
	} else return 0;
}

mixed query_map()
{
	return maps;
}

string show_map(int raw)
{
	int i,j,count=0;
	string str="\n";
	if(sizeof(maps)<1) return "目前沒有地圖被載入。\n";
	for(i=0;i<sizeof(maps);i++)
	{
		for(j=0;j<sizeof(maps[i]);j++)
		{
			str=sprintf("%s<%d>",str,maps[i][j]);
			if(maps[i][j]>block) count++;
		}
		str+="\n";
	}
	for(i=0;i<sizeof(icons);i++)
	{
		str=replace_string(str,sprintf("<%d>",i),icons[i]);
	}
	if(!raw) str+=sprintf("\n  將產生 %d 個房間檔案。\n",count);
	else str+="\n";
	return str;
}

private int generate_room_file(int x, int y)
{
	int i,type,tmp_h;
	string file_name,file,*exit_key,*exit_file;
	mapping exit=([]);
	type=maps[y][x];
	if(type<=block || type>=sizeof(icons)) return 0;
	//為求簡潔, 取消斜向連結
	//Scan north
	if(y>=1) {
		tmp_h=maps[y-1][x];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["north"]=file_head+sprintf("_%d_%d",y-1,x);
		}
	}

	//Scan east
	if(x<sizeof(maps[y])-1) {
		tmp_h=maps[y][x+1];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["east"]=file_head+sprintf("_%d_%d",y,x+1);
		}
	}

	//Scan south
	if( y<sizeof(maps)-1) {
		tmp_h=maps[y+1][x];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["south"]=file_head+sprintf("_%d_%d",y+1,x);
		}
	}

	//Scan west
	if(x>=1) {
		tmp_h=maps[y][x-1];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["west"]=file_head+sprintf("_%d_%d",y,x-1);
		}
	}

	//generate file
	file_name=current_path+file_head+sprintf("_%d_%d.c",y,x);
	file=@FILE_1
inherit ROOM;
void create()
{
FILE_1;
        file+=sprintf("\tset(\"short\", \"%s\");\n",room_short[type]);
file+=@FILE_LONG
        set("long", @LONG

LONG
);
	set("exits",([
FILE_LONG;
	exit_key=keys(exit);
	for(i=0;i<sizeof(exit_key);i++) {
		file=sprintf("%s\t\"%s\" : __DIR__\"%s\",\n",file,exit_key[i],exit[exit_key[i]]);
	}
	file+="\t]));\n";
	//
	//其他房間設定
	//
	if(type==23)
	{
		file+=@TREES
	set("outdoors","land");

TREES;
	}
	else
	{
		if(outdoors!="off") file+="\tset(\"outdoors\",\""+outdoors+"\");\n";
		if(light ) file+="\tset(\"light\",1);\n";
		if(can_save) file+="\tset(\"valid_startroom\",1);\n";
	}
	file+=@FILE_2
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

FILE_2
;
	if( file_size(file_name)!=-1 ) {
		write("檔案 " + file_name + " 已存在﹐要刪除舊檔嗎﹖[y/n]");
		input_to("save_room_file", file_name, file);
		return 1;
	}

	return save_room_file("y", file_name, file);
}


int save_room_file(string yn, string file_name, string file)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

	if( file_size(file_name)!=-1 ) rm(file_name);
	write("建立 " + file_name + "...");
	if( write_file(file_name, file,1) ) {
		write("OK!\n");
		return 1;
	} else 
	{
		write("失敗!!\n");
		return notify_fail("你沒有寫入這個檔案(" + file_name + ")的權利。\n");
	}
}

int do_setpath(string arg)
{
	string dir;
	if(!arg)
	{
		if(dir = this_player()->query("cwd"))
		{
			current_path=dir;
			write("你將放置檔案目錄設定為[ "+current_path+" ]\n");
			return 1;
		} else return notify_fail("無法自動取得目錄。\n");
	}
	else
	{
		if( strsrch(arg, "...") >= 0 ) return notify_fail("沒有這個目錄。\n");	//Add by Luky
		dir = resolve_path(this_player()->query("cwd"), arg);
		if(file_size(dir)!=-2) return notify_fail("沒有這個目錄。\n");
		if(dir[strlen(dir)-1]!='/') dir += "/";
		current_path=dir;
		write("你將放置檔案目錄設定為[ "+current_path+" ]\n");
		return 1;
	}
}
int do_setblock(string arg)
{
	int temp;
	if(!arg) write("目前地圖設定為種類編號[ "+block+" ]以下的為障礙物。\n");
	else
	{
		if(sscanf(arg,"%d",temp)!=1) return notify_fail("設定區域的障礙物種類範圍: setblock [數字]。\n");
		if(temp<0) return notify_fail("設定區域的障礙物種類範圍: setblock [數字] <需大於0>。\n");
		block=temp;
		write("你將編號"+block+"以下的房間種類設定為障礙物。\n");
	}
	return 1;
}
int do_readmap(string arg)
{
	string file;
	if(!arg)
	{
		current_path=this_player()->query("cwd");
		file=resolve_path(this_player()->query("cwd"),"map.txt");
		if(process_map(file))
		{
			write("地圖檔載入完成!!\n");
			this_player()->start_more(show_map(0));
			return 1;
		}
		else
		{
			return notify_fail("地圖檔"+file+"載入失敗。\n");	
		}
	}
	else
	{
		file=resolve_path(this_player()->query("cwd"), arg);
		if(process_map(file))
		{
			write("地圖檔載入完成!!\n");
			this_player()->start_more(show_map(0));
			return 1;
		}
		else
		{
			return notify_fail("地圖檔"+file+"載入失敗。\n");	
		}
	}
}

int do_showmap(string arg)
{
	this_player()->start_more(show_map(0));
	return 1;
}

void delay_generate(int y)
{
	int x;
	for(x=0;x<sizeof(maps[y]);x++)
	{
		generate_room_file(x,y);
	}
	return;
}
void generate_done()
{
	busy=0;
	write("檔案建立完成!!\n");
	return;
}

int do_generate(string arg)
{
	int x,y,time=0;
	if(current_path=="/") current_path=this_player()->query("cwd");
	if(!current_path) return notify_fail("請先設定目錄(setpath)。\n");
	if(block<10 && lock)
	{
		lock=0;
		return notify_fail("緊告: 你目前的障礙物設定為:"+block+", 若有錯誤請用 setblock 重設。\n[再次使用generate則會強迫執行。]\n");
	}
	lock=1;
	if(busy) return notify_fail("正在產生檔案中, 請稍待。\n");
	busy = 1;
	for(y=0;y<sizeof(maps);y++)
	{
		call_out("delay_generate",time,y);
		time+=3;
		//for(x=0;x<sizeof(maps[y]);x++)
		//{
		//	generate_room_file(x,y);
		//}
	}
	call_out("generate_done",time);
	write("準備開始建立檔案...這可能會花一段時間, 請稍待。\n");
	return 1;
}

int do_savemap(string arg)
{
	string output;
	if(sizeof(maps)<1) return notify_fail("目前沒有地圖被載入。\n");
	if(!arg) arg = "area";
	arg = current_path+arg;
	output=show_map(1);
	if( file_size(arg)!=-1 ) {
		write("檔案 " + arg + " 已存在﹐要覆蓋\舊檔﹖[y/n]");
		input_to("save_room_file", arg, output);
		return 1;
	}
	return save_room_file("y", arg, output);
}

int query_autoload() { return 1; }
void owner_is_killed() { destruct(this_object()); }
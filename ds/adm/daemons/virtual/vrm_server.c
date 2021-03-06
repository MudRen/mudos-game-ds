/************************************************
 * vrm_server.c                                 *
 * 虛擬的隨機迷宮創造器 (Virtual Random Maze)   *
 *                                              *
 * by Find.                                     *
 *              網絡游戲 天下 MUD.              *
 ************************************************/

/******************************************************
 * 迷宮是一個游戲里經常要用到的東西，以前的迷宮都需要 *
 * 巫師一個房間一個房間地手工繪制，費時費力，而且一旦 *
 * 被玩家找出正確的線路，迷宮格局被泄漏，迷宮就不稱其 *
 * 為迷宮了，所以巫師們都絞盡腦汁把迷宮設計的盡量復雜,*
 * 但再復雜的迷宮早晚也會被找到正確的路線，而且過于復 *
 * 雜難走的迷宮也使玩家感覺過于繁瑣，降低樂趣。因此產 *
 * 生此想法。                                         *
 * 隨機迷宮的產生算法盡量簡單，迷宮的儲存盡量節省記憶 *
 * 體，迷宮房間采用虛擬物件，處理靈活，迷宮房間只有在 *
 * 玩家走到時才會裝進內存，而且迷宮房間也象普通的ROOM *
 * 一樣當一段時間沒有被參考到可以銷毀節省記憶體，當整 *
 * 個迷宮一段時間沒有被參考到可以被完全摧毀，下次再需 *
 * 要的時候會重新建立，又會產生一個新的迷宮。區域巫師 *
 * 寫作隨機迷宮只需規定一些預設的參數如迷宮的單邊長、 *
 * 房間描述、出入口描述，几十個乃至几千個房間、路線時 *
 * 時不同的隨機迷宮就建立好了，大大提高了區域寫作效率 *
 * 和游戲的可玩性。                                   *
 * 此物件目前適合于隨機的迷宮，即：迷宮內房間的描述基 *
 * 本相同，比如一片樹林、一片墳地等，如要此物件創作完 *
 * 整的隨機區域即有一定的情節、一定格局的區域，則需要 *
 * 根據自己的情況規定出迷宮內房間描述的一些規則，使相 *
 * 鄰房間的描述變化合理，房間內物件與描述協調。如果愿 *
 * 意巫師可以只制作迷宮間的連接部分，而用几個迷宮組合 *
 * 成一個完全隨機的區域，哈，那以后做巫師可輕松多了。 *
 * 目前本游戲使用的迷宮一般為單邊長10至40，到底能做多 *
 * 大的迷宮我也不知道，下面對此有一個說明，要根據自己 *
 * 的服務器性能來講，不過我想最普通的機器制作一個面積 *
 * 為100x100的迷宮應該也是一件輕松的事情。            *
 * 由于采用 virtual object，牽涉到一點安全問題，需要根*
 * 據自己的系統考量調整。                             *
 ******************************************************/

#pragma optimize

#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		15

/****************************************************
 * 迷宮的單邊長最大值目前暫定為 100，由于隨機迷宮的
 * 創造和操作比較耗費資源單邊長 100 的迷宮'面積'就是
 * 100x100 等于 10000 個房間的一個迷宮，一般恐怕是用
 * 不到。一般的實時迷宮（實時迷宮是指在游戲運行過程
 * 中隨時被 destruct 隨著需要又會隨時被創建的迷宮）的
 * 單邊長以 10 到 50 之間為宜。如需創造巨型迷宮如有几
 * 萬乃至十几萬個房間的迷宮，應將創建工作放置于游戲啟
 * 動時做，游戲啟動的一段時間（比如20秒）禁止玩家登入。
 * 游戲通過定期重新啟動來更新此迷宮。
 * 不知誰會用到這么大的迷宮。。。。。。
 ****************************************************/
#define MAX_LONG	100

// 只要能與其他房間相連的房間就肯定有一個入口.
// 而可能的出口有三個.
// define 這項規定房間最多只能有兩個出口.
// 也就是對于有三個出口的房間會隨機關閉一個.
// 不會使玩家由于看到四個方向都有出口很煩
// 降低游戲樂趣。
#define TWO_VALID_LEAVES

inherit F_CLEAN_UP;

class coordinate{ int x; int y; }
class coordinate *newpath = ({}),/*待處理隊列*/
	enter,/* 入口坐標 */
	leave;/* 出口坐標 */

private string *valid_dirs = ({ "south","north","west","east" });
private mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
]);

// 全迷宮出口陣列.
private mixed *all;

/***************** 迷宮的一些預設特性：*****************/
private int l;				// 迷宮的單邊長
private string *inherit_rooms = ({});	// 迷宮允許繼承的檔案名稱
private string entry_dir;		// 迷宮入口方向
private string link_entry_dir;		// 迷宮入口與區域的連接方向
private string link_entry_room;		// 迷宮入口所連接區域檔案的文件名
private string link_exit_dir;		// 迷宮出口與區域的連接方向
private string link_exit_room;		// 迷宮出口所連接區域檔案的文件名
private string entry_short;		// 迷宮入口的短描述
private string entry_desc;		// 迷宮入口的長描述
private string exit_short;		// 迷宮出口的短描述
private string exit_desc;		// 迷宮出口的長描述
private string *maze_room_desc	= ({});	// 迷宮房間的長描述
private string maze_room_short;		// 迷宮房間的短描述
private int is_outdoors = 0;		// 迷宮房間是否為戶外
private string *maze_npcs = ({});	// 迷宮中的怪物
/******************* ---- END ---- *********************/

// 建立標記.
private int maze_built = 0;

// 重置全域變量.
private void refresh_vars();

// 建立迷宮
private void create_maze();

// 選擇隨機出口.
private int random_out(int x,int y,int n);

// 處理連接.
private void link_to_north(int x,int y);
private void link_to_south(int x,int y);
private void link_to_west(int x,int y);
private void link_to_east(int x,int y);

// 繪制已建成迷宮的地圖.
private void paint_vrm_map();

private string mroom_fname(int x,int y)
{ return sprintf("%s/%d/%d",base_name(this_object()),x,y);}


private void refresh_vars() // 重置全域變量.
{
	newpath = ({});
	all = 0;
}

// 對一些必設參數的合法性檢查
private int check_vars()
{
	int i,n;

	if( (l < 5) || l > MAX_LONG )
		return 0;

	inherit_rooms -=({0});
	if( !n = sizeof(inherit_rooms) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(inherit_rooms[i]) || (inherit_rooms[i] == ""))
			return 0;

	if(!stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
		return 0;
/*
	if(!stringp(link_entry_dir) || (member_array(link_entry_dir,valid_dirs) == -1) )
		return 0;

	if(!stringp(link_exit_dir) || (member_array(link_exit_dir,valid_dirs) == -1) )
		return 0;
*/
	if(!stringp(link_entry_room) || (link_entry_room == ""))
		return 0;

	if(!stringp(link_exit_room) || (link_exit_room == ""))
		return 0;

	if(!stringp(entry_short) || (entry_short == ""))
		return 0;

	if(!stringp(exit_short) || (exit_short == ""))
		return 0;

	if(!stringp(entry_desc) || (entry_desc == ""))
		return 0;

	if(!stringp(exit_desc) || (exit_desc == ""))
		return 0;

	maze_room_desc -=({0});
	if( !n = sizeof(maze_room_desc) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(maze_room_desc[i]) || (maze_room_desc[i] == ""))
			return 0;

	if(!stringp(maze_room_short) || (maze_room_short == ""))
		return 0;

	return 1;
}

private int random_out(int x,int y,int n) // 選擇隨機出口函數.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;

		// 西面的房間不在待處理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;

		// 東面的房間不在待處理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;

		// 南面的房間不在待處理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < l)
	&& !all[x][y+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;

		// 北面的房間不在待處理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ N });
	}

#ifdef TWO_VALID_LEAVES
	// 如果有三個出口,隨機關閉一個.
	if(sizeof(outs) >= 3)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}

private void create_maze()
{
	int i;
	class coordinate *valid_leaves=({}),temp;

	refresh_vars(); // 重置全域變量.
	if( !check_vars() )   // 對一些預設變量進行檢查。
		return;

	// 1.確定迷宮單邊長.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(l);	// 建立數組.

	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter 入口坐標.
			enter->x = to_int(l/2); // 取中迷宮比較平衡。
			enter->y = 0;
			all[enter->x][enter->y] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = l-1;
			all[enter->x][enter->y] |= N;
			break;
		case "west":
			enter->y = to_int(l/2);
			enter->x = 0;
			all[enter->x][enter->y] |= W;
			break;
		case "east":
			enter->y = to_int(l/2);
			enter->x = l-1;
			all[enter->x][enter->y] |= E;
			break;
	}

	// 存入待處理隊列.
	newpath += ({ enter });

	// 進入主循環.
	do
	{
		int x,y,out,numb;

		// 進行一些監測與初始化.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;

		// 如果有三個可能的出口隨機關閉一個出口:
		out = ALL^(all[x][y]);
		out = random_out(x,y,out);

		if(!out) // 沒有可能的出口了.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// 處理連接.
		if(out&W) link_to_west(x,y);
		if(out&E) link_to_east(x,y);
		if(out&N) link_to_north(x,y);
		if(out&S) link_to_south(x,y);

		// 當前房間處理完畢.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<l;i++)
				if(all[l-1][i])
				{
					temp = new(class coordinate);
					temp->x = l-1;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "east":
			for(i=0;i<l;i++)
				if(all[0][i])
				{
					temp = new(class coordinate);
					temp->x = 0;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "south":
			for(i=0;i<l;i++)
				if(all[i][l-1])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = l-1;
					valid_leaves += ({temp});
				}
			break;
		case "north":
			for(i=0;i<l;i++)
				if(all[i][0])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = 0;
					valid_leaves += ({temp});
				}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // 沒有出口 須重新建立
	{
		call_other(this_object(),"create_maze");
		return;
	}

	if(i == 1)
		leave = valid_leaves[0];
	else
		leave = valid_leaves[random(i)]; // 隨機選一個.

	switch (entry_dir)
	{
		case "south":
			all[leave->x][leave->y] |= N;
			break;
		case "north":
			all[leave->x][leave->y] |= S;
			break;
		case "west":
			all[leave->x][leave->y] |= E;
			break;
		case "east":
			all[leave->x][leave->y] |= W;
			break;
	}

	// 迷宮創建完畢。
	maze_built = 1;

	// 繪制完成的迷宮地圖。
	// 地圖文件為同目錄下同名的'.map' 文件，
	// 繪制地圖也許可利于區域巫師的工作。
	// 如需要可開放物件對于本目錄的'寫'。
	//paint_vrm_map();
}

private void link_to_west(int x,int y)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. 當前房間已經是最西面的房間了.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;

	// 西面的房間已經于 path 中,或者 已在待處理列表 newpath 中.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= W;
	all[temp->x][temp->y] |= E;
	newpath += ({temp});
}

private void link_to_east(int x,int y)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. 當前房間已經是最東面的房間了.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;

	// 東面的房間已經于 path 中,或者 已在待處理列表 newpath 中.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= E;
	all[temp->x][temp->y] |= W;
	newpath += ({temp});
}

private void link_to_south(int x,int y)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. 當前房間已經是最南端的房間了.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;

	// 南端的房間已經于 path 中,或者 已在待處理列表 newpath 中.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= S;
	all[temp->x][temp->y] |= N;
	newpath += ({temp});
}

private void link_to_north(int x,int y)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. 當前房間已經是最北端的房間了.
	if( (y+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;

	// 北端的房間已經于 path 中,或者 已在待處理列表 newpath 中.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= N;
	all[temp->x][temp->y] |= S;
	newpath += ({temp});
}

// 繪制已建成迷宮的地圖.
private void paint_vrm_map()
{
	string hor = "─" ,ver = "│  ",room = "◎",sroom = "●";
	int x,y;
	string output = "",map_file;

	for(y=(l-1);y>=0;y--)
	{
		reset_eval_cost();

		output += sprintf("y=%-3d: ",y);
		for(x=0;x<l;x++)
		{
			output += sprintf("%s",
				(( (x==enter->x) && (y==enter->y))
				|| ( (x==leave->x) && (y==leave->y) ))?
				sroom:room);

			if( (all[x][y])&E ) // have east
				output += hor;
			else
				output += "  ";
		}

		output += "\n";
		output += "       ";
		for(x=0;x<l;x++)
		{
			if( (all[x][y])&S ) // have south
				output += ver;
			else
			output += "    ";
		}
		output += "\n";
	}

	map_file = sprintf( "%s.map",base_name(this_object()) );
	write_file(map_file,output,1);
}

nomask int clean_up()
{
	string fname;
	int x,y;
	object *maze_objs = ({}),link_room;

	if(!maze_built)
	{
		destruct(this_object());
		return 0;
	}

	fname = base_name(this_object());

	if( objectp(link_room = find_object(sprintf("%s/entry",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	if( objectp(link_room = find_object(sprintf("%s/exit",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(find_object(sprintf("%s/%d/%d",fname,x,y))))
				maze_objs += ({find_object(sprintf("%s/%d/%d",fname,x,y))});

	maze_objs->clean_up();
	maze_objs -= ({0});

	if(sizeof(maze_objs))
		return 1;
	else
	{
		destruct(this_object());
		return 0;
	}
}

// 巫師可以 update 區域迷宮主物件強制更新迷宮，
// 但此時迷宮中的玩家就要去 VOID 了。
void remove(string euid)
{
	string fname = base_name(this_object());
	object m_room;
	int x,y;

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(m_room = find_object(sprintf("%s/%d/%d",fname,x,y))))
				destruct(m_room);
	if(find_object(sprintf("%s/entry",fname)))
		destruct(sprintf("%s/entry",fname));
	if(find_object(sprintf("%s/exit",fname)))
		destruct(sprintf("%s/exit",fname));
}

/**** 以下是預設迷宮參數的接口函數 ****/
// 迷宮的單邊長
void set_maze_long(int mlong)
{
	if(!intp(mlong))
		return;

	// 最小為 5，再小了沒什么意義。
	if( (mlong < 5) || mlong > MAX_LONG )
		return;

	l = mlong;
}

// 迷宮房間所繼承的物件的檔案名稱。
void set_inherit_room( mixed rooms )
{
	if(stringp(rooms))
	{
		// 此檔案是否存在
		if(file_size(sprintf("%s.c",rooms)) > 0)
			inherit_rooms = ({ rooms });
		return;
	}

	else if(arrayp(rooms))
	{
		foreach(string f in rooms)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		inherit_rooms = rooms;
		return;
	}

	return;
}

// 入口方向(出口在對面)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;

	// 入口方向的合法性檢查.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//入口與區域的連接方向
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// 迷宮入口所連接區域檔案的文件名
void set_link_entry_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_entry_room = lroom;
}

//出口與區域的連接方向
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// 迷宮出口所連接區域檔案的文件名
void set_link_exit_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_exit_room = lroom;
}

// 迷宮入口的短描述
void set_entry_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_short = desc;
}

// 迷宮入口的長描述
void set_entry_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_desc = desc;
}

// 迷宮出口的短描述
void set_exit_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_short = desc;
}

// 迷宮出口的長描述
void set_exit_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_desc = desc;
}

//迷宮房間的短描述
void set_maze_room_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	maze_room_short = desc;
}

//迷宮房間的描述，如果有多條描述，制造每個房
//間的時候會從中隨機選擇一個。
void set_maze_room_desc(mixed desces)
{
	if(stringp(desces))
	{
		maze_room_desc = ({ desces });
		return;
	}

	if(arrayp(desces))
	{
		foreach(string desc in desces)
			if(!stringp(desc))
				return;
		maze_room_desc = desces;
		return;
	}
}

// 迷宮房間是否為戶外房間
void set_outdoors(int outd)
{
	if(!intp(outd))
		return;

	if(outd)
		is_outdoors = 1;
}

// 迷宮中的怪物
void set_maze_npcs(mixed npc)
{
	if(stringp(npc))
	{
		// 此檔案是否存在
		if(file_size(sprintf("%s.c",npc)) > 0)
			maze_npcs = ({ npc });
		return;
	}

	else if(arrayp(npc))
	{
		foreach(string f in npc)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		maze_npcs = npc;
		return;
	}

	return;

}

/**** 以上是預設迷宮參數的接口函數 ****/

// 創造迷宮房間，由 VIRTUAL_D 調用。
nomask object query_maze_room(string str)
{
	int random_rate = 20;	// 房間內放置 npc 的可能性
	int idx,x,y,exits;
	object ob;
	string f;

	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(str) || str == "")
		return 0;

	if(!maze_built)	// 迷宮未建立
		create_maze();
	if(!maze_built)
		return 0;

	if(str == "entry")	// 迷宮入口房間
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		if(!ob)
			return 0;
		ob->set("virtual_room",1);
		ob->set("short",entry_short);
		ob->set("long",entry_desc);
		if(is_outdoors)
			ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y));
		if( sizeof(maze_npcs) && (random(100) <= random_rate) )
		{
			ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
			ob->setup();
		}
		return ob;
	}

	if(str == "exit")	// 迷宮出口房間
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		if(!ob)
			return 0;

		ob->set("virtual_room",1);
		ob->set("short",exit_short);
		ob->set("long",exit_desc);
		if(is_outdoors)
			ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir),
			mroom_fname(leave->x,leave->y));
		if( sizeof(maze_npcs) && (random(100) <= random_rate) )
		{
			ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
			ob->setup();
		}
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	if(!sscanf(str[0..idx-1],"%d",x))
		return 0;
	if(!sscanf(str[idx+1..],"%d",y))
		return 0;

	if( !exits = all[x][y] )
		return 0;

	f = inherit_rooms[random(sizeof(inherit_rooms))];
	ob = new(f);
	if(!ob)
		return 0;

	ob->set("virtual_room",1);
	ob->set("short",maze_room_short);
	ob->set("long",maze_room_desc[random(sizeof(maze_room_desc))]);
	if(is_outdoors)
		ob->set("outdoors",1);

	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1));

	if( (x == enter->x) && (y == enter->y) )
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/entry",base_name(this_object())));
	if( (x == leave->x) && (y == leave->y) )
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/exit",base_name(this_object())));

	if( sizeof(maze_npcs) && (random(100) <= random_rate) )
	{
		ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
		ob->setup();
	}

	return ob;
}

void create()
{
	seteuid(getuid());
}
// map.c
// rewrite by Luky in DS. 1999/7/28

#include <room.h>
#include <ansi2.h>
//放大縮小改這裡就好啦! :P -Luky-
#define MAP_SIZE 7
#define RECURSIVE_MAX_DEEP 26
inherit F_CLEAN_UP;
string *author_list = ({ "fofo","ivantseng","joker" });
static mixed *rooms;
static mixed *map;

int search_room( string name, int r, int c ,int deepth);

void clear_map()
{
	int i,j;
	for(i=0;i<MAP_SIZE*4+3;i++)
	{
		for(j=0;j<MAP_SIZE*4+3;j++) map[i][j]="  ";
	}
	
}

void clear_room()
{
	int i,j;
	for(i=0;i<MAP_SIZE*2+1;i++)
	{
		for(j=0;j<MAP_SIZE*2+1;j++) rooms[i][j]=0;
	}
	
}

int main( object me, string arg )
{
        mapping exits;
        string *dirs,msg,upline,downline;
        int i, j,room_size,map_size;
        object env;
	env=environment( me );
	if(!env) return 0;
	if(!wizardp(me))
	{
		if(member_array(geteuid(me),author_list)==-1)
		return notify_fail("這個指令暫時只給巫師與特約玩家使用。\n");
	}
	if(env->query("no_map")) return notify_fail("這個地方無法使用地圖。\n");
        room_size=MAP_SIZE*2+1;
        rooms = allocate( room_size );
        for(i=0;i<room_size;i++) rooms[i] = allocate( room_size );
        map_size=MAP_SIZE*4+3;
        map = allocate( map_size );
        upline="";
        downline="";
        for(i=0;i<map_size;i++)
        {
        	map[i] = allocate( map_size );
        	upline+="￣";
        	downline+="ˍ";
        }
        clear_map();
        clear_room();
        search_room( base_name( env ), MAP_SIZE, MAP_SIZE ,1);
	msg=HIY"\n  ◎ 夢幻七域動態地圖系統   \n"+NOR+"  ◤"+upline+"◥\n";

        for( i = 0; i < map_size; i++ )
        {
        	msg+="  ▏";
                for( j = 0; j < map_size; j++ )
                {
                        if( !map[i][j] ) map[i][j] = "  ";
                        msg += map[i][j];
                }
                msg += "  ▏\n";
        }
        msg+="  ◣"+downline+"◢\n\n";
        write(msg);
        return 1;
}

int search_room( string name, int r, int c ,int deepth)
{
        mapping exits;
	int mr,mc,i,j;
        if( !name )return 0;
        if( r < 0 || (r > MAP_SIZE*2) || c < 0 || (c > MAP_SIZE*2) ) return 0;
        if( rooms[r][c] ) return 0;
	mr=r*2+1;
	mc=c*2+1;
        rooms[r][c] = find_object( name );
        if( !rooms[r][c] )return 0;
	if(rooms[r][c]->query("no_map"))
	{
		map[mr][mc] = "？";
		return 0;
	}
        map[mr][mc] = "";

	if( !rooms[r][c]->query("outdoors") ) map[mr][mc] = BMAG;
        else map[mr][mc] = BGRN;

        exits = rooms[r][c]->query("exits");
        if( sizeof(exits) < 1)
        {
        	if( r == MAP_SIZE && c == MAP_SIZE ) map[mr][mc] += HIC "[1;5;37m☉[0m" NOR;
        	else map[mr][mc] += HIW "□" NOR;
        	return 0;
        } else
        if( r == MAP_SIZE && c == MAP_SIZE ) map[mr][mc] += HIW "[1;5;37m☉[0m" NOR;
        else if( exits["enter"] || exits["out"] ) map[mr][mc] += HIW"＊"NOR;
        else if( exits["up"] || exits["down"] )
        {
        	if(!exits["down"]) map[mr][mc] += HIW"▲"NOR;
        	else if(!exits["up"]) map[mr][mc] += HIW"▼"NOR;
        	else map[mr][mc] += HIW"◆"NOR;
        }
        else switch(rooms[r][c]->query("room_type"))
             {
             	case "bank": map[mr][mc] += HIW"銀"NOR; break;
             	case "hotel": map[mr][mc] += HIW"宿"NOR; break;
                case "hospital": map[mr][mc] += HIW"醫"NOR; break;
             	case "sell": map[mr][mc] += HIW"店"NOR; break;
             	case "shop": map[mr][mc] += HIW"商"NOR; break;
             	case "mail": map[mr][mc] += HIW"郵"NOR; break;
             	case "food": map[mr][mc] += HIW"餐\"NOR; break;
             	default: map[mr][mc] += HIW "□" NOR;
             }
	
	if( deepth > RECURSIVE_MAX_DEEP) return 0;

	// 順時針由北開始搜尋
        if( exits["north"])
        {	map[mr - 1][mc] = "｜";
		search_room( exits["north"], r - 1, c ,	deepth+1);
        }
        if( exits["northeast"] )
        {	map[mr - 1][mc+1] = "╱";
		search_room( exits["northeast"], r - 1, c + 1 ,	deepth+1);
        }
        if( exits["east"] )
        { 
		map[mr][mc+1] = "－";
		search_room( exits["east"], r, c + 1 ,	deepth+1);
        }
        if( exits["southeast"] )
        { 
		map[mr+1][mc+1] = "╲";
		search_room( exits["southeast"], r + 1, c + 1 ,	deepth+1);
        }
        if( exits["south"] )
        {
		map[mr+1][mc] = "｜";
		search_room( exits["south"], r + 1, c ,	deepth+1);
        }
        if( exits["southwest"] )
        {
		map[mr+1][mc-1] = "╱";
		search_room( exits["southwest"], r + 1, c -1 ,	deepth+1);
        }
        if( exits["west"] )
        {
		map[mr][mc-1] = "－";
		search_room( exits["west"], r, c - 1 ,	deepth+1);
        }
        if( exits["northwest"] )
        {
		map[mr - 1][mc - 1] = "╲";
		search_room( exits["northwest"], r - 1, c - 1,	deepth+1);
        }
        return 1;
}

int help(object me)
{
   write(@HELP
指令格式: map

繪製出周圍平面去過的地圖。
 [1;42m□綠[0m表示戶外,
 [1;45m□粉紅[0m表室內.

圖例:
======================================================
 [1;5m☉[m: 目前的位置
 □: 一般房間			銀: 銀行錢莊
 ▲: 上層(up)                   店: 商店
 ▼: 下層(down)                 醫: 醫院
 ◆: 上下層(up & down)          商: 當鋪, 商場
 ＊: 進出口(enter,out)          餐: 餐廳
 ？: 未知區域                   宿: 宿屋, 旅館
 				郵: 郵局
======================================================
By -Luky- 
HELP
   );
   return 1;
}

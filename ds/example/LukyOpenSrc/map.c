// map.c
// rewrite by Luky in DS. 1999/7/28

#include <room.h>
#include <ansi2.h>
//��j�Y�p��o�̴N�n��! :P -Luky-
#define MAP_SIZE 3
#define RECURSIVE_MAX_DEEP 26
inherit F_CLEAN_UP;

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
	if(env->query("no_map")) return notify_fail("�o�Ӧa��L�k�ϥΦa�ϡC\n");
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
        	upline+="��";
        	downline+="��";
        }
        clear_map();
        clear_room();
        search_room( base_name( env ), MAP_SIZE, MAP_SIZE ,1);
	msg=HIY"\n  �� �ڤۤC��ʺA�a�Ϩt��   \n"+NOR+"  ��"+upline+"��\n";

        for( i = 0; i < map_size; i++ )
        {
        	msg+="  �j";
                for( j = 0; j < map_size; j++ )
                {
                        if( !map[i][j] ) map[i][j] = "  ";
                        msg += map[i][j];
                }
                msg += "  �j\n";
        }
        msg+="  ��"+downline+"��\n\n";
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
		map[mr][mc] = "�H";
		return 0;
	}
        map[mr][mc] = "";

	if( !rooms[r][c]->query("outdoors") ) map[mr][mc] = BMAG;
        else map[mr][mc] = BGRN;

        exits = rooms[r][c]->query("exits");
        if( sizeof(exits) < 1)
        {
        	if( r == MAP_SIZE && c == MAP_SIZE ) map[mr][mc] += HIC "[1;5;37m��[0m" NOR;
        	else map[mr][mc] += HIW "��" NOR;
        	return 0;
        } else
        if( r == MAP_SIZE && c == MAP_SIZE ) map[mr][mc] += HIW "[1;5;37m��[0m" NOR;
        else if( exits["enter"] || exits["out"] ) map[mr][mc] += HIW"��"NOR;
        else if( exits["up"] || exits["down"] )
        {
        	if(!exits["down"]) map[mr][mc] += HIW"��"NOR;
        	else if(!exits["up"]) map[mr][mc] += HIW"��"NOR;
        	else map[mr][mc] += HIW"��"NOR;
        }
        else switch(rooms[r][c]->query("room_type"))
             {
             	case "bank": map[mr][mc] += HIW"��"NOR; break;
             	case "hotel": map[mr][mc] += HIW"�J"NOR; break;
                case "hospital": map[mr][mc] += HIW"��"NOR; break;
             	case "sell": map[mr][mc] += HIW"��"NOR; break;
             	case "shop": map[mr][mc] += HIW"��"NOR; break;
             	case "mail": map[mr][mc] += HIW"�l"NOR; break;
             	case "food": map[mr][mc] += HIW"�\\"NOR; break;
             	default: map[mr][mc] += HIW "��" NOR;
             }
	
	if( deepth > RECURSIVE_MAX_DEEP) return 0;

	// ���ɰw�ѥ_�}�l�j�M
        if( exits["north"])
        {	map[mr - 1][mc] = "�U";
		search_room( exits["north"], r - 1, c ,	deepth+1);
        }
        if( exits["northeast"] )
        {	map[mr - 1][mc+1] = "��";
		search_room( exits["northeast"], r - 1, c + 1 ,	deepth+1);
        }
        if( exits["east"] )
        { 
		map[mr][mc+1] = "��";
		search_room( exits["east"], r, c + 1 ,	deepth+1);
        }
        if( exits["southeast"] )
        { 
		map[mr+1][mc+1] = "��";
		search_room( exits["southeast"], r + 1, c + 1 ,	deepth+1);
        }
        if( exits["south"] )
        {
		map[mr+1][mc] = "�U";
		search_room( exits["south"], r + 1, c ,	deepth+1);
        }
        if( exits["southwest"] )
        {
		map[mr+1][mc-1] = "��";
		search_room( exits["southwest"], r + 1, c -1 ,	deepth+1);
        }
        if( exits["west"] )
        {
		map[mr][mc-1] = "��";
		search_room( exits["west"], r, c - 1 ,	deepth+1);
        }
        if( exits["northwest"] )
        {
		map[mr - 1][mc - 1] = "��";
		search_room( exits["northwest"], r - 1, c - 1,	deepth+1);
        }
        return 1;
}

int help(object me)
{
   write(@HELP
���O�榡: map

ø�s�X�P�򥭭��h�L���a�ϡC
 [1;42m����[0m��ܤ�~,
 [1;45m������[0m��Ǥ�.

�Ϩ�:
======================================================
 [1;5m��[m: �ثe����m
 ��: �@��ж�			��: �Ȧ����
 ��: �W�h(up)                   ��: �ө�
 ��: �U�h(down)                 ��: ��|
 ��: �W�U�h(up & down)          ��: ��Q, �ӳ�
 ��: �i�X�f(enter,out)          �\: �\�U
 �H: �����ϰ�                   �J: �J��, ���]
 				�l: �l��
======================================================
By -Luky- 
HELP
   );
   return 1;
}

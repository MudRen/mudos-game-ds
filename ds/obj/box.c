#include <ansi.h>
#include <box.h>
//#define COVER_NONE 	   	2
//#define COVER_OPENED    	3
//#define COVER_CLOSED		4
//#define COVER_SMASHED		5
//#define LOCK_NONE		6
//#define LOCK_OPENED	    	7
//#define LOCK_CLOSED		8
//#define LOCK_SMASHED		9
//inherit F_CLEAN_UP;
inherit BOX;
void create()
{

	set_name("髒鐵箱",({"dirty box","box"}));
        set("unit", "個");
        set("long","一個骯髒的鐵箱子。\n");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        
        set_max_encumbrance(300000);
        set_max_capacity(50);
	set("cover_name","鐵蓋\");	//蓋子名稱
	set_cover(COVER_CLOSED);	//初始蓋子狀態 == 關閉
	set_lock(LOCK_CLOSED);		//初始鎖狀態 == 鎖上
	set_keys( ({"/u/l/luky/redkey","/open/always/thief_mark"}) ); //使用鑰匙檔案
	set_lock_level(3); //設定鎖的等級 1~10
	setup();
}


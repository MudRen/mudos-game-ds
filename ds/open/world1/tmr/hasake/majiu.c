// majiu.c 馬廄
inherit ROOM;
void create()
{
        set("short", "馬棚");
        set("long", @LONG
這是個大馬棚，支起來的帳篷有十多丈長，裡面拴著幾百匹駿馬。馬
雖多，卻是安安分分的，偶爾有幾聲嘶叫聲，看來草原族的馴馬之術的確
高明。一堆人正在旁邊和馬棚主人商討價錢，看他們的服飾好像是從遙遠
的波斯而來。
LONG);
        set("exits", ([
            "west" : __DIR__"caoyuan7",            
        ]));
        set("objects", ([
//                    __DIR__"npc/xiaoxiang" : 1,
        ])); 
        set("outdoors", "land");        
        setup();
        replace_program(ROOM);
}

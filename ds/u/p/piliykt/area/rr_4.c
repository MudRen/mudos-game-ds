inherit ROOM;

void create()
{

set("short","武館");
set("long", @LONG
這裡是神木村唯一的武館, 聽說武館館主身手非凡高深莫測, 你看了
旁的大匾額上寫了個"忍"字, 不竟心中有一種莫名的平靜.
LONG
);
set("exits", ([                
         "north" : __DIR__"rr_1.c", 
        
   ]));
 set("item_desc",([
        "匾額":"上面寫了個 忍 字。\n",
        ]) );

 setup();
}


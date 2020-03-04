#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","狐穴");

 set("long",@LONG
你現在來到狐狸穴的內部, 你才剛踏進這個穴裡, 
你就被血腥味搞得快要吐出來了, 你望了望四周, 你發
現這裡實在很惡心, 到處都是屍體(corpse), 不儘是動
物的, 連人的都有, 你覺得還是快點走吧。
 
LONG
    );
 set("item_desc",([
        "corpse":"你朝這具屍體看了看, 發現上面有被巨大物撕裂的痕跡,
          
你的第六感覺得再下去一定會有危險!!\n",
     ]));
 set("exits",(["north":__DIR__"en13",
               "south":__DIR__"en11",
           ]));
 
 set("no_clean_up", 0);
 setup();
}           

inherit ROOM;

void create()
{

set("short","花園");
set("long", @LONG
這裡是妓院裡的花園, 在你的身旁種有多的花草, 散發出非常香的味
道, 還有幾隻蝴蝶飛舞, 這裡還有假山及大石頭, 佈置的美輪美奐景色迷
人, 如仙境般一樣. 
LONG
);
set("light",1);
set("exits", ([                
         
         "south" : __DIR__"sex_2.c",   
               ]));

 setup();
}


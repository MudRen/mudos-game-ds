inherit ROOM;
void create()
{
        set("short", "泊浪村漁會");        
set("long",@LONG
這裡是泊浪村的漁會，牆上掛著許多他們的豐功偉業，有著許多沒
見過的東西，例如身長7呎的巨蟹、有著18隻觸手的大烏賊、4隻翅膀的
飛魚等等，非常多的稀奇古怪的標本，這裡不只是漁會亦是紀念館也不
一定，這裡是泊浪村漁夫的驕傲。
LONG
        );
set("exits", ([
  "south" : __DIR__"po5w",
]));
set("light",1);        
set("no_clean_up", 0);
        setup();
}












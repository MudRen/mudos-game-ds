inherit ROOM;

void create()
{

set("short","正廳");
set("long", @LONG
這是妓院裡的大廳, 你看到許多漂亮的姑娘正招待著客人, 讓你眼花
撩亂性趣大起, 這裡的擺設華麗漂亮, 看起來非常吸引人, 再你的旁邊有
個樓梯可到二樓, 再往裡走是個花園. 
LONG
);
set("light",1);
set("exits", ([                
         "out" : __DIR__"sex_1.c",   
         "north" : __DIR__"sex_3.c",   
         "up" : __DIR__"up_1.c",   
   ]));

 setup();
}


inherit ROOM;

void create()
{

set("short","海邊小路");
set("long", @LONG
這裡是神木村荒郊外的海邊小路, 你已經可以聞道海的味道, 陣陣的
海浪拍打聲, 讓你為之心動想衝到海水裡去.
LONG
);
set("outdoors", "land");

set("exits", ([                
         "northeast" : __DIR__"rr_6.c", 
             
   ]));

 setup();
}


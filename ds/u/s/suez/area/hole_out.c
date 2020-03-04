
inherit ROOM;

void create()
{
 set("short","洞穴");
        set("long",@LONG
你一走進這裡，就被四散的水霧沾了滿身，經光線照射閃閃發亮的石
壁透出一股詭異的氣息。腳步聲的回音在你耳邊盤桓，迷濛的霧氣，陰暗
的走道，你覺得好像跟世界隔離了。在你逐漸加快的呼吸及心跳中，你是
否還要再往前走呢﹖
LONG
        );

         set("exits", ([
         "north": __DIR__"hole_1",
       "out": __DIR__"hotel_room4",

         ]));
  
        
        setup();
        replace_program(ROOM);

 }
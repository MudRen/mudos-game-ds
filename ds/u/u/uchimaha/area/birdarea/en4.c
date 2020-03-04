inherit MOBROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
 你來到了東北澤林的伐木區, 這裡有許多的橋夫, 正
 在努力的砍伐樹木, 他們的汗一滴一滴的流下, 再往北走
 就是無人的森林深處了。 
 
LONG
    );
 
 set("exits",(["north":__DIR__"en6",
               "west":__DIR__"en3",
             ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",40);
        set("mob_amount",3);    
        set("mob_object",({     
            __DIR__"npc/cutter",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}


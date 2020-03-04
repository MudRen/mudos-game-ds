inherit ROOM;
void create()
{
	set("short", "通道");
        set("long", @LONG
                地上有一個小小的坑洞。
LONG
);
	set("exits",([
	"south" : __DIR__"map_2_1",
	"east" : __DIR__"map_1_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        set("item_desc",([
        "小坑洞":"一個小小的洞，有一些亂七八糟的東西在裡面。\n",
        ]) );
}

void init()
{
        add_action("do_search","search");
}

int i= 1;

int do_search(string arg)
{
        object me,head;
        head=new(__DIR__"npc/obj/cateye");      
        if( !arg || arg!="小坑洞" ) return 0;
        me=this_player();
         if( i==1 )
        {
        message_vision("$N挖了挖地上的坑洞，挖出了一顆亮亮的東西。\n",me);
        head->move(environment(me) );
        i=0;
        }
        else
        {
        message_vision("$N挖了挖地上的坑洞，挖出了一大堆的垃圾，卻沒找到什麼值錢的東西。\n",me);
        }               
        return 1;
}

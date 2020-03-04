inherit ITEM;

void create()
{
        set_name("亮螢草",({"light grass","grass"}));
        set("long",
            "一種喜歡生存在黑暗地方的植物，而且奇特的是\n"
            "它還會發出螢光，並散發一種特殊香味吸引生物\n"
            "接近它，它的種子是做香料的好材料，可是很少\n"
            "結果，你可以摘看看(tug)\n");
        set_weight(9999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","棵");
                set("no_get",1);
        }
        setup();
}

void init()
{
        add_action("do_tug","tug");
}

int do_tug(string arg)
{
        object me=this_player(),grass,obj=this_object();
        grass = new(__DIR__"item/grass_berry");
        if( arg !="light grass" && arg !="亮螢草" )
                return notify_fail("你要摘什麼東西呀？\n");
        else if( !obj->query_temp("get_berry")) 
               {
                message_vision("$N用手把亮螢草的種子摘了下來。\n",me);
                obj->set_temp("get_berry",1);
                grass->move(me);
                call_out("delay",9000);
               } 
           else {
                message_vision("$N想用手摘亮螢草的種子，卻被草上的刺刺傷了。\n",me);
                me->receive_damage("hp",5);
                }
         return 1;
}

void delay()
{
     object ob=this_object();
     if(!ob) return; 
     ob->delete_temp("get_berry");
}



inherit ROOM;

string memory_expression(int m);

void create()
{
        set("short", "Test Room");
        set("long", @LONG


 TEST
 

LONG    );
        setup();
}

void init()
{
        add_action("do_test", "test");
}

int do_test(string arg)
{
        object obj, me = this_player();
        string *list, str="□所有物件記憶體用量排序：\n";
        list = sort_array(objects(),"sort_ob",this_object());
        foreach( obj in list)
        str+=sprintf("%-50s%s\n",file_name(obj),memory_expression(memory_info(obj)));
        me->start_more(str);
        return 1;

}

string memory_expression(int m)
{ 
        float mem = to_float(m);
        if( mem<1024 ) return sprintf("%7.2f Bytes", mem);
        if( mem<1024*1024 )
                return sprintf("%7.2f K bytes", (float)mem / 1024);
        return sprintf("%7.3f M bytes", (float)mem / (1024*1024));
}


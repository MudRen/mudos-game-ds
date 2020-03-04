inherit ITEM;
void create()
{
        set_name("配方",({"mixture"}) );
        set_weight(200);
        set("long",@long
一份清靈丹藥材配方，如果已燒達十分火候，就可以煉製成丹(prepare)。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value", 50);
        set("unit", "份");
        set("pill", 120);  //燒煉所需火候
        }       
        setup();
}

void init()
{
        add_action("do_prepare","prepare");
}

int do_prepare()
{
        object pill,me,ob;
        int a,b;
        me=this_player();
        ob=this_object();
        pill=new(__DIR__"green-pill.c");

        a=ob->query("fire");
        b=ob->query("pill");
        if(!a || !b || a < b)
                return notify_fail("這份配方還未燒煉至十分火候，不能製丹。\n");

        message_vision("$N把$n製成一顆"+pill->query("name")+"。\n",me,ob);
        pill->move(me);
        destruct(ob);
        return 1;
}


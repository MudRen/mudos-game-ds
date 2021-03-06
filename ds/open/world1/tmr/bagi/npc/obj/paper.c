inherit ITEM;
void create()
{
        set_name("牛皮紙",({"alchemy paper","paper"}) );
        set_weight(100);
        set("long",@long
這是一頁殘缺不堪的牛皮紙，上頭所書文字倒還清晰可辯，似乎為武林
流傳著名的「神農藥草本」的片張，「神農藥草本」為一煉丹製藥的奇書，
其內容博大精深。此張上頭寫著是基本的練藥的方子，淺而易懂，一般識字
的人都能閱讀(read)了解。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","頁");
                set("value",300);
        }
        setup();
}

void init()
{
        add_action("do_read","read");
        add_action("do_pharmacy","pharmacy");
}

int do_read(string arg)
{
        object me;
        me=this_player();
        if(!arg) return 0;
        if(!this_object()->id(arg) ) return 0;
        if(me->query_skill("literate") <10) 
                return notify_fail("你的讀書識字不夠，看不懂上頭寫的內容。\n");
        write(@LONG
九轉回命丹 (nine pill)
為基本可練之丹，其配方以「鐵線草」、「商陸」二味調配即成。
清靈丹 (green pill)
為基本可練之丹，其配方以「鐵線草」、「老人根」二味調配即成。
亮葉雞紅丹 (light pill):
為基本可練之丹，其配方需以「鐵線草」、「商陸」及「老人根」調配即成。

調配指令：(pharmacy + 丹藥名稱)
LONG
);
        return 1;
}

int do_pharmacy(string arg)
{
        object me,mixture,linn,roxb,benth;
        me=this_player();
        if(!arg ) return notify_fail("你要調配那一個配方？\n");
        switch(arg)
        {
        case "nine pill":
        if(!objectp(linn=present("adiantum flabellulatum linn",me)) )
                return notify_fail("你身上沒有「鐵線草」，無法調配九轉回命丹。\n");
        if(!objectp(roxb=present("phytolacca acinosa roxb",me)) )
                return notify_fail("你身上沒有「商陸」，無法調配九轉回命丹。\n");
        destruct(linn);
        destruct(roxb);
        mixture=new(__DIR__"mixture1");
        mixture->move(me);
        message_vision("$N依照神農藥草本所寫，將身上藥材調配出一個配方。\n",me);
        break;

        case "light pill":
        if(!objectp(linn=present("adiantum flabellulatum linn",me)) )
                return notify_fail("你身上沒有「鐵線草」，無法調配亮葉雞血丹。\n");
        if(!objectp(roxb=present("phytolacca acinosa roxb",me)) )
                return notify_fail("你身上沒有「商陸」，無法調配亮葉雞血丹。\n");
        if(!objectp(benth=present("millettia nitida benth",me)) )
                return notify_fail("你身上沒有「老人根」，無法調配亮葉雞血丹。\n");
        destruct(linn);
        destruct(roxb);
        destruct(benth);
        mixture=new(__DIR__"mixture2");
        mixture->move(me);
        message_vision("$N依照神農藥草本所寫，將身上藥材調配出一個配方。\n",me);


        case "green pill":
        if(!objectp(linn=present("adiantum flabellulatum linn",me)) )
                return notify_fail("你身上沒有「鐵線草」，無法調配清靈丹。\n");
        if(!objectp(benth=present("millettia nitida benth",me)) )
                return notify_fail("你身上沒有「老人根」，無法調配清靈丹。\n");
        destruct(linn);
        destruct(roxb);
        mixture=new(__DIR__"mixture3");
        mixture->move(me);
        message_vision("$N依照神農藥草本所寫，將身上藥材調配出一個配方。\n",me);
        break;

        break;

        default:
        return notify_fail("有這種配方嗎？？\n");
        break;
        }
        return 1;
}



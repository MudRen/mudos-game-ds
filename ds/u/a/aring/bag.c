#include <ansi.h>;
inherit ITEM;

void resetname(int size);
int MAX_SIZE = 10;

void create()
{
        set_name(HIM"十格小福袋"NOR, ({ "small luck bag","bag" }) );
        set_weight(500);
        //set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "這是一口可以裝入一些物品的小袋子﹐可以用來長期保存一些物品。\n"
                        "inbag 物品id: 將東西放入袋內\n"
                        "outbag 編號: 將東西從袋中拿出\n"
                        "listbag: 看袋內的東西\n"
                );
                set("value", 0);
                set("no_drop",1);
                set("no_sac",1);
                set("no_toss",1);
                set("maxsize",10);
                set("saveeq_type","suechi");
        }
}

int query_autoload() { return 1; }

void init()
{
        object me;
        
        me = this_player();
        if ( query("maxsize") )
                resetname(query("maxsize"));
        add_action("do_inbag","inbag");
        add_action("do_outbag","outbag");
        add_action("do_listbag","listbag");
        if ( wizardp(me) )
                add_action("do_setsize","setsize");
}

void resetname(int size)
{
        set_name(HIY" "+size+" "HIM"格小福袋"NOR, ({ "luck bag","bag" }) );
        MAX_SIZE = size;
}

int do_setsize(string arg)
{
        int newsize,tmpsize;
        
        if ( !arg ) return notify_fail("setsize 大小\n");
        if ( sscanf(arg,"%d",newsize)!=1 )
                return notify_fail("請輸入數字.\n");
        //當要把袋子變小時先檢查newsize+1到maxsize間是否有存東西
        if ( query("maxsize") > newsize )
        {
                tmpsize = newsize+1;
                while (tmpsize <= query("maxsize"))
                {
                        write(query("stored"+tmpsize)+"\n");
                        if ( query("stored"+tmpsize) )
                                return notify_fail("你要縮小袋子大小前, 要先把大於新大小的物品拿出來.\n");
                        tmpsize += 1;
                }
        }
        set("maxsize",newsize);
        resetname(newsize);
        write("設定新的袋子大小為 "+newsize+".\n");
        return 1;
}

int do_inbag(string arg)
{
        object item,ppl;
        int cnt,i;
        mapping itemdb;
        
        ppl = this_player();
        if ( ppl->is_busy() )
                return notify_fail("你沒空放東西進袋子內.\n");
        if ( ppl->is_fighting() )
                return notify_fail("戰鬥中不能放東西進袋子內.\n");
        if ( !arg )
                return notify_fail("你要放什麼東西到袋子裡?\n");
        item = present(arg,ppl);
        if ( !item )
                return notify_fail("這裡沒有 "+arg+" 這個東西.\n");
        if ( item == this_object() )
                return notify_fail("你想做什麼?\n");
        if ( item->query_autoload() ||
                item->query("no_drop") ||
                item->query("no_toss") )
                return notify_fail("這樣東西不能放進去.\n");
        if ( item->query("name") &&
                 strsrch(item->query("name"),"電磁")!=-1 &&
                 strsrch(item->query("name"),"纏護")!=-1 )
                return notify_fail("電磁纏護過後不能放進去.\n");
        cnt = query("stored_cnt");
        if ( cnt >= MAX_SIZE ) return notify_fail("裡面已經放了 "+MAX_SIZE+" 樣物品了\n");
        cnt += 1;
        set("stored_cnt",cnt);
        i=1;
        while ( i <=MAX_SIZE )
        {
                if ( !query("stored_name"+i) )
                {
                        set("stored"+i,base_name(item));
                        set("stored_name"+i,item->short());
                        itemdb = item->query_entire_dbase();
                        map_delete(itemdb,"symbol");
                        map_delete(itemdb,"symbol2");
                        map_delete(itemdb,"symbol3");
                        map_delete(itemdb,"symbol_name");
                        set("itemdb"+i,itemdb);
                        break;
                }
                i = i+1;
        }
        message_vision(CYN"$N"NOR CYN"將一個"+item->name()+NOR CYN"放進"+this_object()->name()+NOR CYN"內.\n"NOR,ppl);
        destruct(item);
        return 1;
}

int do_outbag(string arg)
{
        object obj,ppl;
        int cnt,idx,i;
        string file,err,*dbkey;
        mapping itemdb;
        
        ppl = this_player();
        if ( ppl->is_busy() )
                return notify_fail("你沒空從袋子裡拿東西.\n");
        if ( ppl->is_fighting() )
                return notify_fail("戰鬥中不能從袋子裡拿東西.\n");
        if ( !arg )
                return notify_fail("你要從袋子裡拿哪個編號的東西?\n");
        if ( sscanf(arg,"%d",idx)!=1 )
                return notify_fail("請輸入數字.\n");
        cnt = query("stored_cnt");
        if ( !query("stored"+idx) || idx < 1 ) return notify_fail("沒有這個編號的物品在袋子裡.\n");
        file = query("stored"+idx);
        if ( !file )
                return notify_fail("袋子裡沒有這個編號的東西.\n");
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        if( file_size(file) < 0 )
                return notify_fail("物件檔案(" + file + ")不存在, 請通報巫師。\n");
        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("物件檔案(" + file + ")載入失敗﹕" + err + ", \n請將訊息回報給巫師。\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("物件檔案(" + file + ")複製失敗﹕" + err + "\n請將訊息回報給巫師。\n");
                return 1;
        }
        if ( !obj->move(ppl) )
        {
                destruct(obj);
                return notify_fail("你拿不出這個東西, 因為太重了\n");
        }
        if ( query("itemdb"+idx) )
        {
                itemdb = query("itemdb"+idx);
                dbkey = keys(itemdb);
                for ( i=0;i<sizeof(dbkey);i++ )
                        obj->set(dbkey[i],itemdb[dbkey[i]]);
        }
        message_vision(CYN"$N"NOR CYN"將一個"+obj->name()+NOR CYN"從"+this_object()->name()+NOR CYN"拿出來.\n"NOR,ppl);
        cnt -= 1;
        set("stored_cnt",cnt);
        delete("stored"+idx);
        delete("stored_name"+idx);
        delete("itemdb"+idx);
        return 1;
}

int do_listbag()
{
        int cnt,i;
        string msg;
        
        cnt = query("stored_cnt");
        
        if ( !cnt )
                return notify_fail("這個袋子裡沒有任何東西.\n");
        msg = "袋子裡目前放著這些東西:\n";
        i = 1;
        while ( i <=MAX_SIZE )
        {
                if ( query("stored_name"+i) )
                        msg += "編號 "+i+": "+query("stored_name"+i)+"\n";
                i = i+1;
        }
        tell_object(this_player(),msg);
        return 1;
}


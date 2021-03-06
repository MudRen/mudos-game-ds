/*

  3N Scriper 3N 便條紙製造機
  所需檔案: 1.  ansi.h
            2.  3n_easy.c
  .... produced by Cominging 2001.5.13 12:00 AM

*/
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"3N 便條紙製造機"NOR, ({ "3n scriper", "scriper" }));
        set_weight(1);
        set("long", @LONG

一台極小的機器, 其後不斷地冒出一張張的便條紙, 你可以使用

wrote {所要留下的文字}  也可以用 to write 來輸入大串文字
                        並且可以使用 help nick 中的 $NOR$
                        等控制碼。
cleanup                 清除所有的便條。
checkup [0|1]           0 檢查所有的便條在那裡。
                        1 觀看全部的便條。

LONG
        );
        set("unit", "台");
        setup();
}

void init()
{
        if( base_name(this_object()) != "/u/c/cominging/test/3n_scriper" )
        {
                write("無法複製, 自動消除..\n");
                destruct(this_object());
                return;
        }
        add_action("do_wrote", "wrote");
        add_action("do_cleanup", "cleanup");
        add_action("do_checkup", "checkup");
}

int do_wrote(string arg)
{
        object m_ez;

        if( !arg ) return notify_fail("請輸入你所要留言的內容..\n");
        m_ez = new(__DIR__"3n_easy.c");
        m_ez->set_long(arg);
        if( m_ez->move(environment(this_player())) )
        {
                message_vision("$N沖沖的寫下一張便條紙, 遺落在地上..\n", this_player());
                return 1;
        }
        else return notify_fail(HIR"發生錯誤！！\n"NOR);
}

int do_cleanup(string arg)
{
        object *obs;
        obs = children(__DIR__"3m_easy.c");
        if( sizeof(obs) > 1)
        {
                write("確定要清除所有的便條嗎？[y/n]");
                input_to("ready_cleanup", obs);
        }
        else return notify_fail("沒有已複製出來的便條紙。\n");
}

int ready_cleanup(string yn, object obs)
{
        int x;
        if( strlen(yn) < 1 || yn[0] != 'y' )
                return notify_fail("取消清除。\n");
        for(x=0;x<sizeof(obs);x++)
                destruct(obs);
        write(HIR"已刪除 "+x+" 個便條紙。\n"NOR);
        return 1;
}

int do_checkup(string arg)
{
        object *obs;
        int sw, ob_liz, tmp;
        string out= "";

	if( ob_liz = sizeof(obs=children(__DIR__"3n_easy.c")) )
                out = sprintf("現在有 %d 張便條紙。\n");

        if( sscanf(arg, "%d", sw) != 1 || sw == 0 )
                if( ob_liz > 1 )
                        for(tmp=0;tmp<ob_liz;tmp++)
                                out += sprintf("第%-2d張 => %s", tmp+1, base_name(environment(obs[tmp])));
        else if( ob_liz > 1 )
                        for(tmp=0;tmp<ob_liz;tmp++)
                                out += sprintf("第%-2d張 => %s\n　　　　內容：%s\n",
                                        tmp+1,
                                        base_name(environment(obs[tmp])),
                                        obs[tmp]->long());
        this_player()->start_more(out);
        return 1;
}

int query_autoload() { return 1; }

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("立爾卡",({"li-r-ka","ka"}) );
        set("long",@LONG
在你眼前的男人看起來十分的親切，戴副墨鏡，留著小平頭，接受獵
人公會的命令，到這辦理「獵人試驗」的報名，要是你想成為一個獵人的
話，他可以提供你許多的相關資訊(ask ka about 報名)。
LONG
);
        set("age",30);
        set("race","人類");
        set("level",35);
        set("attitude", "peaceful");
        set("title","二星獵人");
        set("gender", "男性" );
        set("inquiry",([
          "報名":"現在正舉辨獵人試驗報名(join)，只須繳交報名費2000。",
        "尼可骨森林":"ㄜ..尼可骨森林在舊世界礦區的西北邊。",
        "試驗內容":"這次的試驗內容，就是利用森林中的天然資源，追捕「骨名」。",
        "骨名":"ㄜ..骨名是生活在尼可骨森林的動物，其餘就不便多說了。",
        ]) );
        setup();
}

void init()
{
        add_action("do_join","join");
}

int do_join()
{
        object me;
        me=this_player();

       return notify_fail("現在暫時停止報名。\n");

        if(stringp(me->query("class1") ) )
                return notify_fail("你已經參加公會或門派了。\n");
            if(me->query("bank/future") < 2000) 
                return notify_fail("你的銀行帳戶中並沒有足夠的錢。\n");
        if(me->query_temp("join_hunter_test") )
                return notify_fail("你已經報名參加了。\n");
        message_vision("$N向立爾卡登記報名獵人試驗。\n",me);
        command("nod "+me->query("id") );
        command("say 這位"+me->query("name")+"報名者登記成功\，請至尼可骨森林參加試驗吧。" );
        command("say 知道這屆的試驗內容嗎？");
            me->receive_money(-2000);
        me->set_temp("join_hunter_test",1);
        return 1;
}

int accept_object(object me,object obj)
{
        message_vision("$N給了立爾卡一"+obj->query("unit")+obj->query("name")+"。\n",me);
        if(obj->query("catch_ok")!=1 || obj->query("id")!="yalen cirri" )
        return ::accept_object(me,obj);
        destruct(obj);
        if(!me->query_temp("join_hunter_test") ) {
                command("say 謝謝你的好意。");
                command("say");
        }
        else {
                command("say 哦！你成功\的完成了獵人試驗。");
                me->delete_temp("join_hunter_test",);
                me->set_temp("join_hunter_ok",1);
        }
        return 1;
}





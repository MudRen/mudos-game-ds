#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", YEL"古堡"HIY"城門"NOR);
        set("long", @LONG
歷經重重的困難後，你終於到了目的地【古堡】，傳說中它曾經是一
名古代皇族的城池，但不知道什麼原因，現在已經淪落為妖魔們落腳之處
、對人類行刑的恐怖城堡。
LONG);
        set("exits", ([ /* sizeof() == 3 */
    ]));
        set("item_desc", ([
  "大門" : "這是古堡的大門,不知道裡面是不是還會有人,不彷試著敲敲看(knock)？\n",

]));
        set("no_fight",1);
        set("no_cast",1);
        set("no_exert", 1);
        set("no_steal", 1);
        set("world", "past");
        set("no_clean_up", 0);
        set("light",1);

        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_knock","knock");
}

int do_push(string arg)

{
        object me = this_player();
        string gender;
        gender=me->query("gender");

        if( arg != "大門" && arg != "door" )
                return 0;
        if ( gender=="男性" ) gender="少俠";
        if ( gender=="女性" ) gender="俠女";
        if ( me->query("age") > 50 ) gender="前輩";
message("world:world1:vision",
HIY"古堡內傳出陣陣的咆笑聲....................................................！！\n\n"
HIW"傳說中的"+gender+"，遠渡前來，挑戰懸掛百年無人所能破解的「"YEL"古堡試驗"HIW"」！！\n"
NOR+CYN"鬼閃 眾聽聞此事後，便整個興奮了起來說道："HIC"勇者【"HIW+me->query("name")+HIC"】，賞識你的膽識，放馬過來吧！！\n\n"
HIG"\t\t此時古堡上下，蔓延了一陣陣凜冽的殺氣，
"NOR+GRN"\t\t來迎接傳說中勇者『"HIW+me->query("name")+NOR+GRN"』的挑戰！！\n\n"NOR,users());
        me->move(__DIR__"castle1");
        tell_room(environment(me), HIW"只見"+me->name()+"使勁的推開了城門，闖了進去！\n"NOR, ({ me }));
        me->start_busy(1);
        
        return 1;
}
int do_knock(string arg)

{
        object me = this_player();

        if( arg != "大門" && arg != "door" )
                return 0;
        message_vision(HIY"$N敲了敲城門,但是過了許\久還是無人回應,只聽見裡面傳荓x悉蘇蘇的聲音？這時你心想,直接推開(push)大門闖進去好了！\n"NOR,me);
        tell_room(environment(me), HIW"只見"+me->name()+"用力的敲打著城門，但無人回應！\n"NOR, ({ me }));
        me->start_busy(1);
        me->set_temp("knock_door",1);
        return 1;
}


